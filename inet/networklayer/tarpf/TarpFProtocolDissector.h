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

#ifndef INET_NETWORKLAYER_EXTRAS_TARPF_TARPFPROTOCOLDISSECTOR_H_
#define INET_NETWORKLAYER_EXTRAS_TARPF_TARPFPROTOCOLDISSECTOR_H_


#include "inet/common/INETDefs.h"
#include "inet/common/packet/dissector/ProtocolDissector.h"


namespace inet {

class INET_API TarpFProtocolDissector : public ProtocolDissector
{
  public:
    virtual void dissect(Packet *packet, const Protocol *protocol, ICallback& callback) const override;
};

} /* namespace inet */

#endif /* INET_NETWORKLAYER_EXTRAS_TARPF_TARPFPROTOCOLDISSECTOR_H_ */
