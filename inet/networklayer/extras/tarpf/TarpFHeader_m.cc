//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/networklayer/extras/tarpf/TarpFHeader.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "TarpFHeader_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace inet {

Register_Class(TarpFHeader)

TarpFHeader::TarpFHeader() : ::inet::NetworkHeaderBase()
{
}

TarpFHeader::TarpFHeader(const TarpFHeader& other) : ::inet::NetworkHeaderBase(other)
{
    copy(other);
}

TarpFHeader::~TarpFHeader()
{
}

TarpFHeader& TarpFHeader::operator=(const TarpFHeader& other)
{
    if (this == &other) return *this;
    ::inet::NetworkHeaderBase::operator=(other);
    copy(other);
    return *this;
}

void TarpFHeader::copy(const TarpFHeader& other)
{
    this->srcAddr = other.srcAddr;
    this->destAddr = other.destAddr;
    this->hopCount = other.hopCount;
    this->hopBack = other.hopBack;
    this->seqNum = other.seqNum;
    this->protocolId = other.protocolId;
    this->payloadLengthField = other.payloadLengthField;
}

void TarpFHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::NetworkHeaderBase::parsimPack(b);
    doParsimPacking(b,this->srcAddr);
    doParsimPacking(b,this->destAddr);
    doParsimPacking(b,this->hopCount);
    doParsimPacking(b,this->hopBack);
    doParsimPacking(b,this->seqNum);
    doParsimPacking(b,this->protocolId);
    doParsimPacking(b,this->payloadLengthField);
}

void TarpFHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::NetworkHeaderBase::parsimUnpack(b);
    doParsimUnpacking(b,this->srcAddr);
    doParsimUnpacking(b,this->destAddr);
    doParsimUnpacking(b,this->hopCount);
    doParsimUnpacking(b,this->hopBack);
    doParsimUnpacking(b,this->seqNum);
    doParsimUnpacking(b,this->protocolId);
    doParsimUnpacking(b,this->payloadLengthField);
}

const L3Address& TarpFHeader::getSrcAddr() const
{
    return this->srcAddr;
}

void TarpFHeader::setSrcAddr(const L3Address& srcAddr)
{
    handleChange();
    this->srcAddr = srcAddr;
}

const L3Address& TarpFHeader::getDestAddr() const
{
    return this->destAddr;
}

void TarpFHeader::setDestAddr(const L3Address& destAddr)
{
    handleChange();
    this->destAddr = destAddr;
}

int TarpFHeader::getHopCount() const
{
    return this->hopCount;
}

void TarpFHeader::setHopCount(int hopCount)
{
    handleChange();
    this->hopCount = hopCount;
}

int TarpFHeader::getHopBack() const
{
    return this->hopBack;
}

void TarpFHeader::setHopBack(int hopBack)
{
    handleChange();
    this->hopBack = hopBack;
}

unsigned long TarpFHeader::getSeqNum() const
{
    return this->seqNum;
}

void TarpFHeader::setSeqNum(unsigned long seqNum)
{
    handleChange();
    this->seqNum = seqNum;
}

IpProtocolId TarpFHeader::getProtocolId() const
{
    return this->protocolId;
}

void TarpFHeader::setProtocolId(IpProtocolId protocolId)
{
    handleChange();
    this->protocolId = protocolId;
}

B TarpFHeader::getPayloadLengthField() const
{
    return this->payloadLengthField;
}

void TarpFHeader::setPayloadLengthField(B payloadLengthField)
{
    handleChange();
    this->payloadLengthField = payloadLengthField;
}

class TarpFHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_srcAddr,
        FIELD_destAddr,
        FIELD_hopCount,
        FIELD_hopBack,
        FIELD_seqNum,
        FIELD_protocolId,
        FIELD_payloadLengthField,
    };
  public:
    TarpFHeaderDescriptor();
    virtual ~TarpFHeaderDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(TarpFHeaderDescriptor)

TarpFHeaderDescriptor::TarpFHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::TarpFHeader)), "inet::NetworkHeaderBase")
{
    propertyNames = nullptr;
}

TarpFHeaderDescriptor::~TarpFHeaderDescriptor()
{
    delete[] propertyNames;
}

bool TarpFHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TarpFHeader *>(obj)!=nullptr;
}

const char **TarpFHeaderDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *TarpFHeaderDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int TarpFHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 7+base->getFieldCount() : 7;
}

unsigned int TarpFHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_srcAddr
        0,    // FIELD_destAddr
        FD_ISEDITABLE,    // FIELD_hopCount
        FD_ISEDITABLE,    // FIELD_hopBack
        FD_ISEDITABLE,    // FIELD_seqNum
        FD_ISEDITABLE,    // FIELD_protocolId
        FD_ISEDITABLE,    // FIELD_payloadLengthField
    };
    return (field >= 0 && field < 7) ? fieldTypeFlags[field] : 0;
}

const char *TarpFHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcAddr",
        "destAddr",
        "hopCount",
        "hopBack",
        "seqNum",
        "protocolId",
        "payloadLengthField",
    };
    return (field >= 0 && field < 7) ? fieldNames[field] : nullptr;
}

int TarpFHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "srcAddr") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "destAddr") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "hopCount") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "hopBack") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "seqNum") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "protocolId") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "payloadLengthField") == 0) return baseIndex + 6;
    return base ? base->findField(fieldName) : -1;
}

const char *TarpFHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::L3Address",    // FIELD_srcAddr
        "inet::L3Address",    // FIELD_destAddr
        "int",    // FIELD_hopCount
        "int",    // FIELD_hopBack
        "unsigned long",    // FIELD_seqNum
        "inet::IpProtocolId",    // FIELD_protocolId
        "inet::B",    // FIELD_payloadLengthField
    };
    return (field >= 0 && field < 7) ? fieldTypeStrings[field] : nullptr;
}

const char **TarpFHeaderDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_protocolId: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *TarpFHeaderDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_protocolId:
            if (!strcmp(propertyName, "enum")) return "inet::IpProtocolId";
            return nullptr;
        default: return nullptr;
    }
}

int TarpFHeaderDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    TarpFHeader *pp = omnetpp::fromAnyPtr<TarpFHeader>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void TarpFHeaderDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    TarpFHeader *pp = omnetpp::fromAnyPtr<TarpFHeader>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'TarpFHeader'", field);
    }
}

const char *TarpFHeaderDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    TarpFHeader *pp = omnetpp::fromAnyPtr<TarpFHeader>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TarpFHeaderDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    TarpFHeader *pp = omnetpp::fromAnyPtr<TarpFHeader>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddr: return pp->getSrcAddr().str();
        case FIELD_destAddr: return pp->getDestAddr().str();
        case FIELD_hopCount: return long2string(pp->getHopCount());
        case FIELD_hopBack: return long2string(pp->getHopBack());
        case FIELD_seqNum: return ulong2string(pp->getSeqNum());
        case FIELD_protocolId: return enum2string(pp->getProtocolId(), "inet::IpProtocolId");
        case FIELD_payloadLengthField: return unit2string(pp->getPayloadLengthField());
        default: return "";
    }
}

void TarpFHeaderDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    TarpFHeader *pp = omnetpp::fromAnyPtr<TarpFHeader>(object); (void)pp;
    switch (field) {
        case FIELD_hopCount: pp->setHopCount(string2long(value)); break;
        case FIELD_hopBack: pp->setHopBack(string2long(value)); break;
        case FIELD_seqNum: pp->setSeqNum(string2ulong(value)); break;
        case FIELD_protocolId: pp->setProtocolId((inet::IpProtocolId)string2enum(value, "inet::IpProtocolId")); break;
        case FIELD_payloadLengthField: pp->setPayloadLengthField(B(string2long(value))); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TarpFHeader'", field);
    }
}

omnetpp::cValue TarpFHeaderDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    TarpFHeader *pp = omnetpp::fromAnyPtr<TarpFHeader>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddr: return omnetpp::toAnyPtr(&pp->getSrcAddr()); break;
        case FIELD_destAddr: return omnetpp::toAnyPtr(&pp->getDestAddr()); break;
        case FIELD_hopCount: return pp->getHopCount();
        case FIELD_hopBack: return pp->getHopBack();
        case FIELD_seqNum: return omnetpp::checked_int_cast<omnetpp::intval_t>(pp->getSeqNum());
        case FIELD_protocolId: return static_cast<int>(pp->getProtocolId());
        case FIELD_payloadLengthField: return cValue(pp->getPayloadLengthField().get(),"B");
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'TarpFHeader' as cValue -- field index out of range?", field);
    }
}

void TarpFHeaderDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    TarpFHeader *pp = omnetpp::fromAnyPtr<TarpFHeader>(object); (void)pp;
    switch (field) {
        case FIELD_hopCount: pp->setHopCount(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_hopBack: pp->setHopBack(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_seqNum: pp->setSeqNum(omnetpp::checked_int_cast<unsigned long>(value.intValue())); break;
        case FIELD_protocolId: pp->setProtocolId(static_cast<inet::IpProtocolId>(value.intValue())); break;
        case FIELD_payloadLengthField: pp->setPayloadLengthField(B(value.intValueInUnit("B"))); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TarpFHeader'", field);
    }
}

const char *TarpFHeaderDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr TarpFHeaderDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    TarpFHeader *pp = omnetpp::fromAnyPtr<TarpFHeader>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddr: return omnetpp::toAnyPtr(&pp->getSrcAddr()); break;
        case FIELD_destAddr: return omnetpp::toAnyPtr(&pp->getDestAddr()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void TarpFHeaderDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    TarpFHeader *pp = omnetpp::fromAnyPtr<TarpFHeader>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TarpFHeader'", field);
    }
}

}  // namespace inet

namespace omnetpp {

}  // namespace omnetpp

