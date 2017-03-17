#ifndef ZCONSOLE_H
#define ZCONSOLE_H

#include "zobject.h"

Z_BEGIN_NAMESPACE

class ZConsole : public ZObject
{
    Q_OBJECT

public:
    explicit ZConsole(ZObject *parent = 0);
    ~ZConsole();

public slots:
    void log(ZVariant &retVals, const QList<ZVariant> &args) const;
    void print(ZVariant &retVals, const QList<ZVariant> &args) const;
    void printLine(ZVariant &retVals, const QList<ZVariant> &args) const;
    void getLine(ZVariant &retVals, const QList<ZVariant> &args) const;
    void getChar(ZVariant &retVals, const QList<ZVariant> &args) const;
    void getCh(ZVariant &retVals, const QList<ZVariant> &args) const;
    void getKey(ZVariant &retVals, const QList<ZVariant> &args) const;
    void kbhit(ZVariant &retVals, const QList<ZVariant> &args) const;
    void setEcho(ZVariant &retVals, const QList<ZVariant> &args) const;
    void setCursorVisible(ZVariant &retVals, const QList<ZVariant> &args) const;
    void setCursorPos(ZVariant &retVals, const QList<ZVariant> &args) const;
    void upCursor(ZVariant &retVals, const QList<ZVariant> &args) const;
    void downCursor(ZVariant &retVals, const QList<ZVariant> &args) const;
    void leftCursor(ZVariant &retVals, const QList<ZVariant> &args) const;
    void rightCursor(ZVariant &retVals, const QList<ZVariant> &args) const;
    void clear(ZVariant &retVals, const QList<ZVariant> &args) const;
    void clearLine(ZVariant &retVals, const QList<ZVariant> &args) const;
    void reset(ZVariant &retVals, const QList<ZVariant> &args) const;
    void setColor(ZVariant &retVals, const QList<ZVariant> &args) const;
    void flushInput(ZVariant &retVals, const QList<ZVariant> &args) const;
    void flushOutput(ZVariant &retVals, const QList<ZVariant> &args) const;

private:
    QString variantToString(const ZVariant &val) const;
};

Z_END_NAMESPACE

#endif // ZCONSOLE_H
