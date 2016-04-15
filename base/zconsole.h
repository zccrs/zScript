#ifndef ZCONSOLE_H
#define ZCONSOLE_H

#include "zobject.h"

Z_BEGIN_NAMESPACE

class ZConsole : public ZObject
{
    Q_OBJECT

public:
    explicit ZConsole(ZObject *parent = 0);

public slots:
    void log(QList<ZVariant> &retVals, const QList<ZVariant> &args) const;
};

Z_END_NAMESPACE

#endif // ZCONSOLE_H
