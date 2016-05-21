#ifndef ZSYSTEM_H
#define ZSYSTEM_H

#include "zobject.h"

class ZSystem : public ZObject
{
public:
    explicit ZSystem(ZObject *parent = 0);

    void eval(ZVariant &retVals, const QList<ZVariant> &args);
    void sleep(ZVariant &retVals, const QList<ZVariant> &args);
    void msleep(ZVariant &retVals, const QList<ZVariant> &args);
    void usleep(ZVariant &retVals, const QList<ZVariant> &args);
    void random(ZVariant &retVals, const QList<ZVariant> &args) const;
    void msecsSinceStartOfDay(ZVariant &retVals, const QList<ZVariant> &args) const;
};

#endif // ZSYSTEM_H
