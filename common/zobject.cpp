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
