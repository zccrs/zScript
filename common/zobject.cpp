#include "zobject.h"

Z_BEGIN_NAMESPACE

/// ZObject
ZObject::ZObject(ZObject *parent)
    : QObject(parent)
{

}

ZVariant ZObject::property(const char *name) const
{
    return ZVariant(QObject::property(name));
}

void ZObject::setProperty(const char *name, const ZVariant &value)
{
    QObject::setProperty(name, value.toQVariant());
}

QList<ZVariant> ZFunction::call(const QList<ZVariant> &args) const
{
    QList<ZVariant> retVal;

    emit callFun(retVal, args);

    return retVal;
}

Z_END_NAMESPACE
