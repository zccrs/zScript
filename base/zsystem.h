#ifndef ZSYSTEM_H
#define ZSYSTEM_H

#include "zobject.h"

class ZSystem : public ZObject
{
public:
    explicit ZSystem(ZObject *parent = 0);

    void eval(ZVariant &retVals, const QList<ZVariant> &args);
};

#endif // ZSYSTEM_H
