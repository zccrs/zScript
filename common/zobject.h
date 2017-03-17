#ifndef ZOBJECT_H
#define ZOBJECT_H

#include "zvariant.h"

#include <QObject>
#include <QPointer>

#include <functional>

Z_BEGIN_NAMESPACE

#define Z_REGIST_SLOT(Fun) \
    setProperty(QString(#Fun).split("::").last().toLatin1().constData(), ZVariant(new ZFunction(this, Fun, this)))

class ZObject : public QObject
{
    Q_OBJECT

public:
    explicit ZObject(ZObject *parent = 0);

    inline ZVariant property(const char *name) const
    { return ZVariant(QObject::property(name));}

public slots:
    void setProperty(const char *name, const ZVariant &value)
    { QObject::setProperty(name, value.toQVariant());}
};

class ZFunction : public ZObject
{
    Q_OBJECT

public:
    inline explicit ZFunction(ZObject *parent = 0)
        : ZObject(parent){}

    template<typename T, typename Fun>
    inline explicit ZFunction(T target, Fun method, ZObject *parent)
        : ZObject(parent)
    {
        connect(this, &ZFunction::callFun, target, method, Qt::DirectConnection);
    }

    virtual ZVariant call(const QList<ZVariant> &args) const;

signals:
    void callFun(ZVariant &retVals, const QList<ZVariant> &args) const;
};

class ZMethod : public ZFunction
{
public:
    inline explicit ZMethod(const std::function<ZVariant(const QList<ZVariant>&)> &fun, ZObject *parent = 0)
        : ZFunction(parent)
        , function(fun)
    {

    }

    ZVariant call(const QList<ZVariant> &args) const Q_DECL_OVERRIDE
    {
        return function(args);
    }

private:
    std::function<ZVariant(const QList<ZVariant>&)> function;
};

class ZPropertyVariant : public ZVariant
{
public:
    explicit ZPropertyVariant(const ZVariant &other, ZObject *object, const QByteArray &name);

    void depthCopyAssign(const ZVariant &other) const Q_DECL_OVERRIDE;
    ZVariant& operator=(const ZVariant &other) Q_DECL_OVERRIDE;
    ZVariant& operator=(ZVariant &&other) Q_DECL_OVERRIDE;

private:
    QPointer<ZObject> object;
    QByteArray propertyName;
};

Z_END_NAMESPACE

#endif // ZOBJECT_H
