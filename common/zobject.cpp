#include "zobject.h"

Z_BEGIN_NAMESPACE

/// ZObject
ZObject::ZObject(ZObject *parent)
    : QObject(parent)
{

}

Z_END_NAMESPACE

ZVariant ZFunction::call(const QList<ZVariant> &args) const
{
    ZVariant retVal;

    emit callFun(retVal, args);

    return retVal;
}

ZPropertyVariant::ZPropertyVariant(const ZVariant &other, ZObject *object, const QByteArray &name)
    : ZVariant(other)
{
    this->object = object;
    propertyName = name;
}

void ZPropertyVariant::depthCopyAssign(const ZVariant &other) const
{
    if (object)
        object->setProperty(propertyName, other);

    ZVariant::depthCopyAssign(other);
}

ZVariant &ZPropertyVariant::operator=(const ZVariant &other)
{
    if (object)
        object->setProperty(propertyName, other);

    return ZVariant::operator=(other);
}

ZVariant &ZPropertyVariant::operator=(ZVariant &&other)
{
    if (object)
        object->setProperty(propertyName, other);

    return ZVariant::operator=(other);
}
