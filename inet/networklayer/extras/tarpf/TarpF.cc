//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "inet/common/ProtocolTag_m.h"
#include "inet/linklayer/common/MacAddressTag_m.h"
#include "inet/networklayer/common/HopLimitTag_m.h"
#include "inet/networklayer/common/L3AddressTag_m.h"
#include "inet/networklayer/contract/IL3AddressType.h"
#include "TarpF.h"

namespace inet {

using std::endl;

Define_Module(TarpF);

void TarpF::initialize(int stage) {
    NetworkProtocolBase::initialize(stage);
    EV_DEBUG << "protocol initialized" << endl ;

    if (stage == INITSTAGE_LOCAL) {
        // initialize sequence number to 0
        seqNum = 0;
        nbDataPacketsReceived = 0;
        nbDataPacketsSent = 0;
        nbDataPacketsForwarded = 0;
        nbHops = 0;
        nbSpdDrops = 0;

        //parameters
        maxHopCount = par("maxHopCount");
        plainFlooding = par("plainFlooding");
        headerLength = par("headerLength");
        spdRule = par("spdRule");

        EV << "maxHopCount = " << maxHopCount << " plainFlooding = "
                  << plainFlooding << endl;

        if (plainFlooding) {
            // settings duplicate discard cache parameters
            ddMaxEntries = par("ddMaxEntries");
            ddDelTime = par("ddDelTime");
            EV << "ddMaxEntries = " << ddMaxEntries << " ddDelTime = "
                      << ddDelTime << endl;
        }
        if (spdRule) {
            // settings spd cache parameters
            spdMaxEntries = par("spdMaxEntries");
            spdDelTime = par("spdDelTime");
            slack = par("slack");
            relax = par("relax");
            EV << "spdMaxEntries = " << spdMaxEntries << " spdDelTime = "
                      << spdDelTime << endl;

        }

    } else if (stage == INITSTAGE_NETWORK_LAYER) {
        auto ie = interfaceTable->findFirstNonLoopbackInterface();
        if (ie != nullptr)
            myNetwAddr = ie->getNetworkAddress();
        else
            throw cRuntimeError("No non-loopback interface found!");
    }
}

void TarpF::finish() {
    if (plainFlooding) {
        ddCache.clear();
    }
    if (spdRule) {
        spdCache.clear();
    }
    recordScalar("nbDataPacketsReceived", nbDataPacketsReceived);
    recordScalar("nbDataPacketsSent", nbDataPacketsSent);
    recordScalar("nbDataPacketsForwarded", nbDataPacketsForwarded);
    if (nbDataPacketsReceived > 0) {
        recordScalar("meanNbHops",
                (double) nbHops / (double) nbDataPacketsReceived);
    } else {
        recordScalar("meanNbHops", 0);
    }
    recordScalar("nbSpdDrops", nbSpdDrops);

}

void TarpF::handleUpperPacket(Packet *packet) {
    encapsulate(packet);
    auto tarpfHeader = packet->peekAtFront<TarpFHeader>();

    if (plainFlooding) {
        //check and updating the dd counter.
        if (ddCache.size() >= ddMaxEntries) {
            // search and delete out-dated messages
            for (auto it = ddCache.begin(); it != ddCache.end();) {
                if (it->delTime < simTime())
                    it = ddCache.erase(it);
                else
                    ++it;

            }

            // delete oldest entry if still max size reached
            if (ddCache.size() >= ddMaxEntries) {
                EV << "ddCache is full, delete oldest entry" << endl;
                ddCache.pop_front();
            }

        }
        ddCache.push_back(
                Bcast(tarpfHeader->getSeqNum(), tarpfHeader->getSourceAddress(),
                        simTime() + ddDelTime));

    }
    // send to broadcast
    sendDown(packet);
    nbDataPacketsSent++;
}

void TarpF::handleLowerPacket(Packet *packet) {

    auto tarpfHeader = packet->peekAtFront<TarpFHeader>();

    if (notBroadcasted(tarpfHeader.get())) {

        // TODO - if msg is for me -> sendUp
        if (interfaceTable->isLocalAddress(
                tarpfHeader->getDestinationAddress())) {

            EV << " data msg for me! send to Upper | hopCount= "
                      << (tarpfHeader->getHopCount() + 1) << endl;

            isSubOptimal(tarpfHeader.get());

            nbHops = nbHops + (1 + tarpfHeader->getHopCount());
            decapsulate(packet);
            sendUp(packet);
            nbDataPacketsReceived++;
        }

        // TODO - else if broadcast message

        else if (tarpfHeader->getDestinationAddress().isBroadcast()) {

            //Check for the max-hop-count
            EV << " data msg not for me! | to = "
                      << tarpfHeader->getDestinationAddress() << " | seqNum = "
                      << tarpfHeader->getSeqNum() << " | hopCount = "
                      << tarpfHeader->getHopCount() << " < " << maxHopCount
                      << " forward" << endl;

            auto dMsg = packet->dup();
            auto newTarpFHeader = dMsg->removeAtFront<TarpFHeader>();
            newTarpFHeader->setHopCount(newTarpFHeader->getHopCount() - 1);
            dMsg->insertAtFront(newTarpFHeader);
            setDownControlInfo(dMsg, MacAddress::BROADCAST_ADDRESS);
            emit(packetsForwardedSignal, dMsg);
            sendDown(dMsg);
            nbDataPacketsForwarded++;
        } else
            EV << " max hops reached (ttl = " << tarpfHeader->getHopCount()
                      << ") -> only send to upper\n";

        // message has to be forwarded to upper layer
        nbHops = nbHops + (maxHopCount + 1 - tarpfHeader->getHopCount());
        decapsulate(packet);
        sendUp(packet);
        nbDataPacketsReceived++;

    }

// TODO - else not for me -> rebroadcast
    else {
        // check hop count and rebroadcast
        if (tarpfHeader->getHopCount() < maxHopCount) {
            EV << " data msg not for me! | to = "
                      << tarpfHeader->getDestinationAddress()
                      << "  | hopCount = " << tarpfHeader->getHopCount()
                      << " < " << maxHopCount << " forward" << endl;

            decapsulate(packet);

            if (isSubOptimal(tarpfHeader.get())) {

                nbSpdDrops++;
                delete packet;
                return;
            }

            auto packetCopy = new Packet();
            packetCopy->insertAtBack(
                    packet->peekDataAt(b(0), packet->getDataLength()));

            auto tarpfHeaderCopy = staticPtrCast<TarpFHeader>(
                    tarpfHeader->dupShared());

            tarpfHeaderCopy->setHopCount(tarpfHeader->getHopCount() + 1);

            packetCopy->insertAtFront(tarpfHeaderCopy);

            // needs to set the next hop address again to broadcast
            cObject *const pCtrlInfo = packetCopy->removeControlInfo();
            if (pCtrlInfo != nullptr)
                delete pCtrlInfo;

            setDownControlInfo(packetCopy, MacAddress::BROADCAST_ADDRESS);
            sendDown(packetCopy);
            emit(packetsForwardedSignal, packetCopy);
            sendDown(packetCopy);
            nbDataPacketsForwarded++;

            delete packet;

        } else {
            // max hops reached -> delete
            EV << " data msg already BROADCASTed! delete msg desAddr = "
                      << tarpfHeader->getDestinationAddress() << endl;
            delete packet;
        }

    }

}

bool TarpF::notBroadcasted(const TarpFHeader *msg) {

if (!plainFlooding)
    return true;

// search ddCacahe for out-dated entries and delete them
for (auto it = ddCache.begin(); it != ddCache.end();) {
    if (it->delTime < simTime()) {
        it = ddCache.erase(it);
    }
    // message was already broadcasted
    else if ((it->srcAddr == msg->getSourceAddress())
            && (it->seqNum == msg->getSeqNum())) {
        // update
        it->delTime = simTime() + ddDelTime;
        return false;
    } else
        ++it;
}

// delete oldest entry if max size is reached
if (ddCache.size() >= ddMaxEntries) {
    EV << "ddCache is full, delete oldest entry\n";
    ddCache.pop_front();
}

ddCache.push_back(
        Bcast(msg->getSeqNum(), msg->getSourceAddress(),
                simTime() + ddDelTime));
return true;
}

bool TarpF::isSubOptimal(const TarpFHeader *msg) {

if (!spdRule)
    return false;

// search spdCache
std::map<L3Address, SpdEntry>::iterator it;

for (it = spdCache.begin(); it != spdCache.end(); it++) {

    if (it->second.delTime < simTime()) {
        EV << "Reset spdCache: delTime= " << it->second.delTime
                  << " < current: " << simTime() << endl;

        EV << "Reset spdCache: " << it->first << " current: "
                  << it->second.hopCount << endl;

        it->second.hopCount = 0;
        it->second.delTime = simTime() + spdDelTime;
    }

}

if (spdCache[msg->getSourceAddress()].hopCount == 0) {

    spdCache[msg->getSourceAddress()] = SpdEntry((1 + msg->getHopCount()),
            simTime() + spdDelTime);

    EV << "New spdCache: " << msg->getSourceAddress() << " hopCount: "
              << (1 + msg->getHopCount()) << endl;

}

//    else if (spdCache[msg->getSourceAddress()].hopCount > ( 1 + msg->getHopCount())) {
//
//        spdCache[msg->getSourceAddress()] = SpdEntry( ( 1 + msg->getHopCount()), simTime() + spdDelTime);
//
//    }
if (spdCache[msg->getDestinationAddress()].hopCount > 0){
    if ((msg->getHopBack() + slack)
            < (spdCache[msg->getDestinationAddress()].hopCount + 1
                    + msg->getHopCount())) {

        EV << "Sub Optimal Path: Hb= " << msg->getHopBack() << " + slack= " << slack
                  << " < Hc= " << (1 + msg->getHopCount()) << " + " << "Hnk="
                  << spdCache[msg->getDestinationAddress()].hopCount << endl;

        return true;

    }
}

return false;

}

void TarpF::decapsulate(Packet *packet) {
EV << " decapsulating: " << packet << endl;

auto tarpfHeader = packet->popAtFront<TarpFHeader>();
auto payloadLength = tarpfHeader->getPayloadLengthField();
if (packet->getDataLength() < payloadLength) {
    throw cRuntimeError("Data error: illegal payload length");
}
if (packet->getDataLength() > payloadLength)
    packet->setBackOffset(packet->getFrontOffset() + payloadLength);

auto payloadProtocol = tarpfHeader->getProtocol();

packet->addTagIfAbsent<NetworkProtocolInd>()->setProtocol(&getProtocol());
packet->addTagIfAbsent<NetworkProtocolInd>()->setNetworkProtocolHeader(
        tarpfHeader);
packet->addTagIfAbsent<DispatchProtocolReq>()->setProtocol(payloadProtocol);
packet->addTagIfAbsent<PacketProtocolTag>()->setProtocol(payloadProtocol);

auto addressInd = packet->addTagIfAbsent<L3AddressInd>();

addressInd->setSrcAddress(tarpfHeader->getSourceAddress());
addressInd->setDestAddress(tarpfHeader->getDestinationAddress());
packet->addTagIfAbsent<HopLimitInd>()->setHopLimit(
        maxHopCount - tarpfHeader->getHopCount());

EV << " pkt decapsulated: " << packet << endl;

}

/**
 * Encapsulates the received ApplPkt into a NetwPkt and set all needed
 * header fields.
 **/
void TarpF::encapsulate(Packet *appPkt) {
// TODO - Generated method body

L3Address netwAddr;

EV << " encapsulating pkt:" << appPkt << endl;

auto cInfo = appPkt->removeControlInfo();
auto pkt = makeShared<TarpFHeader>();
pkt->setChunkLength(b(headerLength));

auto hopLimitReq = appPkt->removeTagIfPresent<HopLimitReq>();
int Hb = (hopLimitReq != nullptr) ? hopLimitReq->getHopLimit() : -1;
delete &hopLimitReq;

pkt->setSeqNum(seqNum);
seqNum++;

auto addressReq = appPkt->findTag<L3AddressReq>();
if (addressReq == nullptr) {

    EV
              << "warning: Application layer did not specify a destination L3 address\n"
              << "\t using broadcast address instead\n";

} else {
    pkt->setProtocol(appPkt->getTag<PacketProtocolTag>()->getProtocol());
    netwAddr = addressReq->getDestAddress();
    EV << " cInfo removed, netw addr=" << netwAddr << endl;
    delete cInfo;
}

pkt->setSrcAddr(myNetwAddr);
pkt->setDestAddr(netwAddr);

if (Hb == -1) {
    if (spdCache[pkt->getDestAddr()].hopCount == 0) {
        Hb = maxHopCount;
    } else {
        Hb = spdCache[pkt->getDestAddr()].hopCount;
    }
}

pkt->setHopBack(Hb);

EV << " netw " << myNetwAddr << " sending packet" << endl;

// TODO - Generated method body

EV << "sendDown: nHop=L3BROADCAST -> message has to be broadcasted"
          << " -> set destMac=L2BROADCAST" << endl;

pkt->setPayloadLengthField(appPkt->getDataLength());

//encapsulate the application packet
setDownControlInfo(appPkt, MacAddress::BROADCAST_ADDRESS);

appPkt->insertAtFront(pkt);
EV << " encapsulated pkt: " << appPkt << endl;

EV << " pkt header: seqNum=" << pkt->getSeqNum() << " hopCount="
          << pkt->getHopCount() << " hopBack=" << pkt->getHopBack()
          << " srcAddr=" << pkt->getSrcAddr() << " destAddr="
          << pkt->getDestAddr() << endl;

}

/**
 * Attaches a "control info" structure (object) to the down message pMsg.
 */
void TarpF::setDownControlInfo(Packet *const pMsg,
    const MacAddress &pDestAddr) {
pMsg->addTagIfAbsent<MacAddressReq>()->setDestAddress(pDestAddr);
pMsg->addTagIfAbsent<PacketProtocolTag>()->setProtocol(&getProtocol());
pMsg->addTagIfAbsent<DispatchProtocolInd>()->setProtocol(&getProtocol());
}

} //namespace inet
