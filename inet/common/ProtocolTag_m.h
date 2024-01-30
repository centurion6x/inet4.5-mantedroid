//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/common/ProtocolTag.msg.
//

#ifndef __INET_PROTOCOLTAG_M_H
#define __INET_PROTOCOLTAG_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

// dll export symbol
#ifndef INET_API
#  if defined(INET_EXPORT)
#    define INET_API  OPP_DLLEXPORT
#  elif defined(INET_IMPORT)
#    define INET_API  OPP_DLLIMPORT
#  else
#    define INET_API
#  endif
#endif


namespace inet {

class ProtocolTagBase;
class ProtocolListTagBase;
class DispatchProtocolReq;
class DispatchProtocolInd;
class EncapsulationProtocolReq;
class EncapsulationProtocolInd;
class PacketProtocolTag;
class TransportProtocolReq;
class TransportProtocolInd;
class NetworkProtocolReq;
class NetworkProtocolInd;
class MacProtocolReq;
class MacProtocolInd;

}  // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/Protocol_m.h" // import inet.common.Protocol

#include "inet/common/TagBase_m.h" // import inet.common.TagBase

#include "inet/common/packet/chunk/Chunk_m.h" // import inet.common.packet.chunk.Chunk


namespace inet {

// cplusplus {{
typedef Ptr<const Chunk> ChunkPtr;
// }}

/**
 * Class generated from <tt>inet/common/ProtocolTag.msg:29</tt> by opp_msgtool.
 * <pre>
 * //
 * // This is an abstract base class that should not be directly added as a tag.
 * //
 * class ProtocolTagBase extends TagBase
 * {
 *     const Protocol *protocol \@getter(findProtocol); // specifies a protocol (internal class with an artificial identifier)
 * }
 * </pre>
 */
class INET_API ProtocolTagBase : public ::inet::TagBase
{
  protected:
    const Protocol * protocol = nullptr;

  private:
    void copy(const ProtocolTagBase& other);

  protected:
    bool operator==(const ProtocolTagBase&) = delete;

  public:
    ProtocolTagBase();
    ProtocolTagBase(const ProtocolTagBase& other);
    virtual ~ProtocolTagBase();
    ProtocolTagBase& operator=(const ProtocolTagBase& other);
    virtual ProtocolTagBase *dup() const override {return new ProtocolTagBase(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual const Protocol * findProtocol() const;
    virtual void setProtocol(const Protocol * protocol);


    const Protocol *getProtocol() const {
        if (protocol == nullptr)
            throw cRuntimeError("Protocol is not specified");
        return protocol;
    }
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const ProtocolTagBase& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, ProtocolTagBase& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/common/ProtocolTag.msg:45</tt> by opp_msgtool.
 * <pre>
 * //
 * // This is an abstract base class that should not be directly added as a tag.
 * //
 * class ProtocolListTagBase extends TagBase
 * {
 *     const Protocol *protocol[]; // specifies a list of protocols (internal class with an artificial identifier)
 * }
 * </pre>
 */
class INET_API ProtocolListTagBase : public ::inet::TagBase
{
  protected:
    const Protocol * *protocol = nullptr;
    size_t protocol_arraysize = 0;

  private:
    void copy(const ProtocolListTagBase& other);

  protected:
    bool operator==(const ProtocolListTagBase&) = delete;

  public:
    ProtocolListTagBase();
    ProtocolListTagBase(const ProtocolListTagBase& other);
    virtual ~ProtocolListTagBase();
    ProtocolListTagBase& operator=(const ProtocolListTagBase& other);
    virtual ProtocolListTagBase *dup() const override {return new ProtocolListTagBase(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual void setProtocolArraySize(size_t size);
    virtual size_t getProtocolArraySize() const;
    virtual const Protocol * getProtocol(size_t k) const;
    virtual void setProtocol(size_t k, const Protocol * protocol);
    virtual void insertProtocol(size_t k, const Protocol * protocol);
    [[deprecated]] void insertProtocol(const Protocol * protocol) {appendProtocol(protocol);}
    virtual void appendProtocol(const Protocol * protocol);
    virtual void eraseProtocol(size_t k);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const ProtocolListTagBase& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, ProtocolListTagBase& obj) {obj.parsimUnpack(b);}

/**
 * Enum generated from <tt>inet/common/ProtocolTag.msg:53</tt> by opp_msgtool.
 * <pre>
 * //
 * // OSI layered service primitives
 * //
 * enum ServicePrimitive
 * {
 *     SP_UNSPECIFIED = -1;
 *     SP_REQUEST = 1;
 *     SP_INDICATION = 2;
 *     SP_RESPONSE = 3;
 *     SP_CONFIRM = 4;
 * }
 * </pre>
 */
enum ServicePrimitive {
    SP_UNSPECIFIED = -1,
    SP_REQUEST = 1,
    SP_INDICATION = 2,
    SP_RESPONSE = 3,
    SP_CONFIRM = 4
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const ServicePrimitive& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, ServicePrimitive& e) { int n; b->unpack(n); e = static_cast<ServicePrimitive>(n); }

/**
 * Class generated from <tt>inet/common/ProtocolTag.msg:66</tt> by opp_msgtool.
 * <pre>
 * //
 * // This request determines the destination protocol of the message or packet
 * // when it's sent from one protocol module to another using the ~MessageDispatcher.
 * //
 * class DispatchProtocolReq extends ProtocolTagBase
 * {
 *     ServicePrimitive servicePrimitive;
 * }
 * </pre>
 */
class INET_API DispatchProtocolReq : public ::inet::ProtocolTagBase
{
  protected:
    ServicePrimitive servicePrimitive = static_cast<inet::ServicePrimitive>(-1);

  private:
    void copy(const DispatchProtocolReq& other);

  protected:
    bool operator==(const DispatchProtocolReq&) = delete;

  public:
    DispatchProtocolReq();
    DispatchProtocolReq(const DispatchProtocolReq& other);
    virtual ~DispatchProtocolReq();
    DispatchProtocolReq& operator=(const DispatchProtocolReq& other);
    virtual DispatchProtocolReq *dup() const override {return new DispatchProtocolReq(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual ServicePrimitive getServicePrimitive() const;
    virtual void setServicePrimitive(ServicePrimitive servicePrimitive);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const DispatchProtocolReq& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, DispatchProtocolReq& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/common/ProtocolTag.msg:75</tt> by opp_msgtool.
 * <pre>
 * //
 * // This indication specifies the sending protocol of the message or packet
 * // when it's sent from one protocol module to another using the ~MessageDispatcher.
 * //
 * class DispatchProtocolInd extends ProtocolTagBase
 * {
 * }
 * </pre>
 */
class INET_API DispatchProtocolInd : public ::inet::ProtocolTagBase
{
  protected:

  private:
    void copy(const DispatchProtocolInd& other);

  protected:
    bool operator==(const DispatchProtocolInd&) = delete;

  public:
    DispatchProtocolInd();
    DispatchProtocolInd(const DispatchProtocolInd& other);
    virtual ~DispatchProtocolInd();
    DispatchProtocolInd& operator=(const DispatchProtocolInd& other);
    virtual DispatchProtocolInd *dup() const override {return new DispatchProtocolInd(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const DispatchProtocolInd& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, DispatchProtocolInd& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/common/ProtocolTag.msg:86</tt> by opp_msgtool.
 * <pre>
 * //
 * // This request determines the expected protocol encapsulation order of the
 * // packet. If this tag is attached to a packet, then the first encapsulation
 * // protocol specifies the next dispatch protocol. Otherwise the individual
 * // protocol modules are expected to request dispatching to their default
 * // following encapsulation protocol.
 * //
 * class EncapsulationProtocolReq extends ProtocolListTagBase
 * {
 * }
 * </pre>
 */
class INET_API EncapsulationProtocolReq : public ::inet::ProtocolListTagBase
{
  protected:

  private:
    void copy(const EncapsulationProtocolReq& other);

  protected:
    bool operator==(const EncapsulationProtocolReq&) = delete;

  public:
    EncapsulationProtocolReq();
    EncapsulationProtocolReq(const EncapsulationProtocolReq& other);
    virtual ~EncapsulationProtocolReq();
    EncapsulationProtocolReq& operator=(const EncapsulationProtocolReq& other);
    virtual EncapsulationProtocolReq *dup() const override {return new EncapsulationProtocolReq(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const EncapsulationProtocolReq& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, EncapsulationProtocolReq& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/common/ProtocolTag.msg:96</tt> by opp_msgtool.
 * <pre>
 * //
 * // This indication determines the original protocol encapsulation order of the
 * // packet. If this tag is attached to the packet, then the protocols specify the
 * // order of encapsulation as it seen by the protocol modules when the packet was
 * // processed and decapsulated.
 * //
 * class EncapsulationProtocolInd extends ProtocolListTagBase
 * {
 * }
 * </pre>
 */
class INET_API EncapsulationProtocolInd : public ::inet::ProtocolListTagBase
{
  protected:

  private:
    void copy(const EncapsulationProtocolInd& other);

  protected:
    bool operator==(const EncapsulationProtocolInd&) = delete;

  public:
    EncapsulationProtocolInd();
    EncapsulationProtocolInd(const EncapsulationProtocolInd& other);
    virtual ~EncapsulationProtocolInd();
    EncapsulationProtocolInd& operator=(const EncapsulationProtocolInd& other);
    virtual EncapsulationProtocolInd *dup() const override {return new EncapsulationProtocolInd(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const EncapsulationProtocolInd& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, EncapsulationProtocolInd& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/common/ProtocolTag.msg:153</tt> by opp_msgtool.
 * <pre>
 * //
 * // This tag specifies the protocol of the packet.
 * //
 * // Packet processing at the sender
 * // ===============================
 * //
 * // | ApplicationData |
 * //     whole packet has no protocol
 * //     data part has no protocol
 * //
 * // | UdpHeader ApplicationData |
 * //     whole packet has UDP protocol
 * //     data part has UDP protocol
 * //
 * // | Ipv4Header UdpHeader ApplicationData |
 * //     whole packet has IPv4 protocol
 * //     data part has IPv4 protocol
 * //
 * // EthernetMacHeader | Ipv4Header UdpHeader ApplicationData |
 * //     whole packet has incomplete Ethernet protocol
 * //     data part has IPv4 protocol
 * //
 * // EthernetMacHeader | Ipv4Header UdpHeader ApplicationData | EthernetPadding EthernetFcs
 * //     whole packet has Ethernet protocol
 * //     data part has IPv4 protocol
 * //
 * // | EthernetMacHeader Ipv4Header UdpHeader ApplicationData EthernetPadding EthernetFcs |
 * //     whole packet has Ethernet protocol
 * //     data part has Ethernet protocol
 * //
 * // Packet processing at the receiver
 * // =================================
 * //
 * // | EthernetMacHeader Ipv4Header UdpHeader ApplicationData EthernetPadding EthernetFcs |
 * //     whole packet has Ethernet protocol
 * //     data part has Ethernet protocol
 * //
 * // EthernetMacHeader Ipv4Header UdpHeader ApplicationData EthernetPadding | EthernetFcs
 * //     whole packet has Ethernet protocol
 * //     data part has no protocol
 * //
 * // EthernetMacHeader | Ipv4Header UdpHeader ApplicationData | EthernetPadding EthernetFcs
 * //     whole packet has Ethernet protocol
 * //     data part has IPv4 protocol
 * //
 * // EthernetMacHeader Ipv4Header | UdpHeader ApplicationData | EthernetPadding EthernetFcs
 * //     whole packet has Ethernet protocol
 * //     data part has UDP protocol
 * //
 * // EthernetMacHeader Ipv4Header UdpHeader | ApplicationData | EthernetPadding EthernetFcs
 * //     whole packet has Ethernet protocol
 * //     data part has no protocol
 * //
 * class PacketProtocolTag extends ProtocolTagBase
 * {
 *     b frontOffset = b(0); // extra offset relative to the packet data part front offset
 *     b backOffset = b(0); // extra offset relative to the packet data part back offset
 * }
 * </pre>
 */
class INET_API PacketProtocolTag : public ::inet::ProtocolTagBase
{
  protected:
    b frontOffset = b(0);
    b backOffset = b(0);

  private:
    void copy(const PacketProtocolTag& other);

  protected:
    bool operator==(const PacketProtocolTag&) = delete;

  public:
    PacketProtocolTag();
    PacketProtocolTag(const PacketProtocolTag& other);
    virtual ~PacketProtocolTag();
    PacketProtocolTag& operator=(const PacketProtocolTag& other);
    virtual PacketProtocolTag *dup() const override {return new PacketProtocolTag(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual b getFrontOffset() const;
    virtual void setFrontOffset(b frontOffset);

    virtual b getBackOffset() const;
    virtual void setBackOffset(b backOffset);


    void set(const Protocol *protocol, b frontOffset = b(0), b backOffset = b(0)) {
        this->protocol = protocol;
        this->frontOffset = frontOffset;
        this->backOffset = backOffset;
    }
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const PacketProtocolTag& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, PacketProtocolTag& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/common/ProtocolTag.msg:171</tt> by opp_msgtool.
 * <pre>
 * //
 * // This request determines the transport protocol that should be used to send the packet.
 * // It may be present from the application to the transport protocol.
 * //
 * class TransportProtocolReq extends ProtocolTagBase
 * {
 * }
 * </pre>
 */
class INET_API TransportProtocolReq : public ::inet::ProtocolTagBase
{
  protected:

  private:
    void copy(const TransportProtocolReq& other);

  protected:
    bool operator==(const TransportProtocolReq&) = delete;

  public:
    TransportProtocolReq();
    TransportProtocolReq(const TransportProtocolReq& other);
    virtual ~TransportProtocolReq();
    TransportProtocolReq& operator=(const TransportProtocolReq& other);
    virtual TransportProtocolReq *dup() const override {return new TransportProtocolReq(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const TransportProtocolReq& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, TransportProtocolReq& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/common/ProtocolTag.msg:180</tt> by opp_msgtool.
 * <pre>
 * //
 * // This indication specifies the transport protocol that was used to receive
 * // the packet. It may be present from the transport protocol to the application
 * // and from the transport protocol to the physical layer.
 * //
 * class TransportProtocolInd extends ProtocolTagBase
 * {
 *     ChunkPtr transportProtocolHeader;
 * }
 * </pre>
 */
class INET_API TransportProtocolInd : public ::inet::ProtocolTagBase
{
  protected:
    ChunkPtr transportProtocolHeader;

  private:
    void copy(const TransportProtocolInd& other);

  protected:
    bool operator==(const TransportProtocolInd&) = delete;

  public:
    TransportProtocolInd();
    TransportProtocolInd(const TransportProtocolInd& other);
    virtual ~TransportProtocolInd();
    TransportProtocolInd& operator=(const TransportProtocolInd& other);
    virtual TransportProtocolInd *dup() const override {return new TransportProtocolInd(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual const ChunkPtr& getTransportProtocolHeader() const;
    virtual ChunkPtr& getTransportProtocolHeaderForUpdate() { return const_cast<ChunkPtr&>(const_cast<TransportProtocolInd*>(this)->getTransportProtocolHeader());}
    virtual void setTransportProtocolHeader(const ChunkPtr& transportProtocolHeader);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const TransportProtocolInd& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, TransportProtocolInd& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/common/ProtocolTag.msg:190</tt> by opp_msgtool.
 * <pre>
 * //
 * // This request determines the network protocol that should be used to send the
 * // packet. It may be present from the application to the network protocol and
 * // from the network protocol to the physical layer.
 * //
 * class NetworkProtocolReq extends ProtocolTagBase
 * {
 * }
 * </pre>
 */
class INET_API NetworkProtocolReq : public ::inet::ProtocolTagBase
{
  protected:

  private:
    void copy(const NetworkProtocolReq& other);

  protected:
    bool operator==(const NetworkProtocolReq&) = delete;

  public:
    NetworkProtocolReq();
    NetworkProtocolReq(const NetworkProtocolReq& other);
    virtual ~NetworkProtocolReq();
    NetworkProtocolReq& operator=(const NetworkProtocolReq& other);
    virtual NetworkProtocolReq *dup() const override {return new NetworkProtocolReq(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const NetworkProtocolReq& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, NetworkProtocolReq& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/common/ProtocolTag.msg:198</tt> by opp_msgtool.
 * <pre>
 * //
 * // This indication specifies the network protocol that was used to receive the
 * // packet. It may be present from the network protocol to the application.
 * //
 * class NetworkProtocolInd extends ProtocolTagBase
 * {
 *     ChunkPtr networkProtocolHeader;
 * }
 * </pre>
 */
class INET_API NetworkProtocolInd : public ::inet::ProtocolTagBase
{
  protected:
    ChunkPtr networkProtocolHeader;

  private:
    void copy(const NetworkProtocolInd& other);

  protected:
    bool operator==(const NetworkProtocolInd&) = delete;

  public:
    NetworkProtocolInd();
    NetworkProtocolInd(const NetworkProtocolInd& other);
    virtual ~NetworkProtocolInd();
    NetworkProtocolInd& operator=(const NetworkProtocolInd& other);
    virtual NetworkProtocolInd *dup() const override {return new NetworkProtocolInd(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual const ChunkPtr& getNetworkProtocolHeader() const;
    virtual ChunkPtr& getNetworkProtocolHeaderForUpdate() { return const_cast<ChunkPtr&>(const_cast<NetworkProtocolInd*>(this)->getNetworkProtocolHeader());}
    virtual void setNetworkProtocolHeader(const ChunkPtr& networkProtocolHeader);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const NetworkProtocolInd& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, NetworkProtocolInd& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/common/ProtocolTag.msg:208</tt> by opp_msgtool.
 * <pre>
 * //
 * // This request determines the mac protocol that should be used to send the
 * // packet. It may be present from the application to the mac protocol and from
 * // the mac protocol to the physical layer.
 * //
 * class MacProtocolReq extends ProtocolTagBase
 * {
 * }
 * </pre>
 */
class INET_API MacProtocolReq : public ::inet::ProtocolTagBase
{
  protected:

  private:
    void copy(const MacProtocolReq& other);

  protected:
    bool operator==(const MacProtocolReq&) = delete;

  public:
    MacProtocolReq();
    MacProtocolReq(const MacProtocolReq& other);
    virtual ~MacProtocolReq();
    MacProtocolReq& operator=(const MacProtocolReq& other);
    virtual MacProtocolReq *dup() const override {return new MacProtocolReq(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const MacProtocolReq& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, MacProtocolReq& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/common/ProtocolTag.msg:216</tt> by opp_msgtool.
 * <pre>
 * //
 * // This indication specifies the mac protocol that was used to receive the
 * // packet. It may be present from the mac protocol to the application.
 * //
 * class MacProtocolInd extends ProtocolTagBase
 * {
 *     ChunkPtr macProtocolHeader;
 * }
 * </pre>
 */
class INET_API MacProtocolInd : public ::inet::ProtocolTagBase
{
  protected:
    ChunkPtr macProtocolHeader;

  private:
    void copy(const MacProtocolInd& other);

  protected:
    bool operator==(const MacProtocolInd&) = delete;

  public:
    MacProtocolInd();
    MacProtocolInd(const MacProtocolInd& other);
    virtual ~MacProtocolInd();
    MacProtocolInd& operator=(const MacProtocolInd& other);
    virtual MacProtocolInd *dup() const override {return new MacProtocolInd(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual const ChunkPtr& getMacProtocolHeader() const;
    virtual ChunkPtr& getMacProtocolHeaderForUpdate() { return const_cast<ChunkPtr&>(const_cast<MacProtocolInd*>(this)->getMacProtocolHeader());}
    virtual void setMacProtocolHeader(const ChunkPtr& macProtocolHeader);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const MacProtocolInd& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, MacProtocolInd& obj) {obj.parsimUnpack(b);}


}  // namespace inet


namespace omnetpp {

inline any_ptr toAnyPtr(const inet::ChunkPtr *p) {if (auto obj = as_cObject(p)) return any_ptr(obj); else return any_ptr(p);}
template<> inline inet::ChunkPtr *fromAnyPtr(any_ptr ptr) { return ptr.get<inet::ChunkPtr>(); }
template<> inline inet::ProtocolTagBase *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::ProtocolTagBase*>(ptr.get<cObject>()); }
template<> inline inet::ProtocolListTagBase *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::ProtocolListTagBase*>(ptr.get<cObject>()); }
template<> inline inet::DispatchProtocolReq *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::DispatchProtocolReq*>(ptr.get<cObject>()); }
template<> inline inet::DispatchProtocolInd *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::DispatchProtocolInd*>(ptr.get<cObject>()); }
template<> inline inet::EncapsulationProtocolReq *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::EncapsulationProtocolReq*>(ptr.get<cObject>()); }
template<> inline inet::EncapsulationProtocolInd *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::EncapsulationProtocolInd*>(ptr.get<cObject>()); }
template<> inline inet::PacketProtocolTag *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::PacketProtocolTag*>(ptr.get<cObject>()); }
template<> inline inet::TransportProtocolReq *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::TransportProtocolReq*>(ptr.get<cObject>()); }
template<> inline inet::TransportProtocolInd *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::TransportProtocolInd*>(ptr.get<cObject>()); }
template<> inline inet::NetworkProtocolReq *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::NetworkProtocolReq*>(ptr.get<cObject>()); }
template<> inline inet::NetworkProtocolInd *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::NetworkProtocolInd*>(ptr.get<cObject>()); }
template<> inline inet::MacProtocolReq *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::MacProtocolReq*>(ptr.get<cObject>()); }
template<> inline inet::MacProtocolInd *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::MacProtocolInd*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __INET_PROTOCOLTAG_M_H

