#include "zobject.h"

Z_BEGIN_NAMESPACE

/// ZObject
ZObject::ZObject(ZObject *parent)
    : QObject(parent)
{

}

Z_END_NAMESPACE

QList<ZVariant> ZFunction::call(const QList<ZVariant> &args) const
{
    QList<ZVariant> retVal;

    emit callFun(retVal, args);

    return retVal;
}
