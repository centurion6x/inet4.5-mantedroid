//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/networklayer/common/TosTag.msg.
//

#ifndef __INET_TOSTAG_M_H
#define __INET_TOSTAG_M_H

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

class TosTagBase;
class TosReq;
class TosInd;

}  // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/TagBase_m.h" // import inet.common.TagBase


namespace inet {

/**
 * Class generated from <tt>inet/networklayer/common/TosTag.msg:16</tt> by opp_msgtool.
 * <pre>
 * //
 * // This is an abstract base class that should not be directly added as a tag.
 * //
 * class TosTagBase extends TagBase
 * {
 *     int tos = -1; // differentiated services code point
 * }
 * </pre>
 */
class INET_API TosTagBase : public ::inet::TagBase
{
  protected:
    int tos = -1;

  private:
    void copy(const TosTagBase& other);

  protected:
    bool operator==(const TosTagBase&) = delete;

  public:
    TosTagBase();
    TosTagBase(const TosTagBase& other);
    virtual ~TosTagBase();
    TosTagBase& operator=(const TosTagBase& other);
    virtual TosTagBase *dup() const override {return new TosTagBase(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getTos() const;
    virtual void setTos(int tos);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const TosTagBase& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, TosTagBase& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/common/TosTag.msg:25</tt> by opp_msgtool.
 * <pre>
 * //
 * // This request determines the type of services that should be used to transmit the packet.
 * // It may be present on a packet from the application to the network protocol.
 * //
 * class TosReq extends TosTagBase
 * {
 * }
 * </pre>
 */
class INET_API TosReq : public ::inet::TosTagBase
{
  protected:

  private:
    void copy(const TosReq& other);

  protected:
    bool operator==(const TosReq&) = delete;

  public:
    TosReq();
    TosReq(const TosReq& other);
    virtual ~TosReq();
    TosReq& operator=(const TosReq& other);
    virtual TosReq *dup() const override {return new TosReq(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const TosReq& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, TosReq& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/common/TosTag.msg:33</tt> by opp_msgtool.
 * <pre>
 * //
 * // This indication specifies the type of services that was used to receive the packet.
 * // It may be present on a packet from the network protocol to the application.
 * //
 * class TosInd extends TosTagBase
 * {
 * }
 * </pre>
 */
class INET_API TosInd : public ::inet::TosTagBase
{
  protected:

  private:
    void copy(const TosInd& other);

  protected:
    bool operator==(const TosInd&) = delete;

  public:
    TosInd();
    TosInd(const TosInd& other);
    virtual ~TosInd();
    TosInd& operator=(const TosInd& other);
    virtual TosInd *dup() const override {return new TosInd(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const TosInd& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, TosInd& obj) {obj.parsimUnpack(b);}


}  // namespace inet


namespace omnetpp {

template<> inline inet::TosTagBase *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::TosTagBase*>(ptr.get<cObject>()); }
template<> inline inet::TosReq *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::TosReq*>(ptr.get<cObject>()); }
template<> inline inet::TosInd *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::TosInd*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __INET_TOSTAG_M_H

