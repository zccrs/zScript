#ifndef ZOBJECT_H
#define ZOBJECT_H

#include "zvariant.h"

#include <QObject>

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

    virtual QList<ZVariant> call(const QList<ZVariant> &args) const;

signals:
    void callFun(QList<ZVariant> &retVals, const QList<ZVariant> &args) const;
};

Z_END_NAMESPACE

#endif // ZOBJECT_H
