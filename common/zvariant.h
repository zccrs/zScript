#ifndef ZVARIANT_H
#define ZVARIANT_H

#include "zglobal.h"

#include <QSharedDataPointer>
#include <QVariant>

Z_BEGIN_NAMESPACE

class ZObject;

class ZVariant
{
public:
    enum Type {
        Int = QMetaType::Int,
        Double = QMetaType::Double,
        Bool = QMetaType::Bool,
        String = QMetaType::QString,
        List = QMetaType::QVariantList,
        Object = QMetaType::PointerToQObject,
        Undefined = QMetaType::UnknownType,
        NaN = QMetaType::User + 1,
        Null = QMetaType::User + 2,
        Group = QMetaType::User + 3
    };

    typedef QList<ZVariant*> ZGroup;

    ZVariant(Type type = Undefined);
    ZVariant(int val);
    ZVariant(double val);
    ZVariant(bool val);
    ZVariant(const char *val);
    ZVariant(const ZVariant &other);
    ZVariant(ZVariant &&other);
    ZVariant(const QString &val);
    ZVariant(QLatin1String val);
    template <typename T>
    ZVariant(const QList<T> &val);
    ZVariant(const QList<ZVariant> &val);
    ZVariant(const ZGroup &group);
    ZVariant(ZObject * const object);
    ZVariant(const QVariant &val);
    ~ZVariant();

    Type type() const;
    const char *typeName() const;

    int toInt(bool *ok = 0) const;
    double toDouble(bool *ok = 0) const;
    bool toBool() const;
    QString toString() const;
    QList<ZVariant> toList() const;
    ZObject *toObject() const;
    QVariant toQVariant() const;

    inline ZVariant& operator=(const ZVariant &other)
    { data = other.data; return *this;}
    inline ZVariant& operator=(ZVariant &&other)
    { qSwap(data, other.data); return *this;}
    inline bool operator==(const ZVariant &v) const
    { return data->variant == v.data->variant; }
    inline bool operator!=(const ZVariant &v) const
    { return data->variant != v.data->variant; }
    inline bool operator<(const ZVariant &v) const
    { return data->variant < v.data->variant; }
    inline bool operator<=(const ZVariant &v) const
    { return data->variant <= v.data->variant; }
    inline bool operator>(const ZVariant &v) const
    { return data->variant > v.data->variant; }
    inline bool operator>=(const ZVariant &v) const
    { return data->variant >= v.data->variant; }
    inline bool operator&&(const ZVariant &v) const
    { return toBool() && v.toBool();}
    inline bool operator||(const ZVariant &v) const
    { return toBool() || v.toBool();}
    inline bool operator!() const
    { return !toBool();}
    inline ZVariant operator-() const
    {
        switch(data->type) {
        case Double:
            return -toDouble();
        case Int:
        case Bool:
            return -toInt();
        case String:
            return toString().toLower();
        default: return NaN;
        }
    }
    inline ZVariant operator+() const
    {
        switch(data->type) {
        case Double:
            return qAbs(toDouble());
        case Int:
        case Bool:
            return qAbs(toInt());
        case String:
            return toString().toUpper();
        default: return NaN;
        }
    }

private:
    class VariantData : public QSharedData
    {
        QVariant variant;
        ZVariant::Type type;

        friend class ZVariant;
    };

    QSharedDataPointer<VariantData> data;
};

QT_BEGIN_NAMESPACE
Q_CORE_EXPORT QDebug operator<<(QDebug deg, const ZVariant &var);
QT_END_NAMESPACE

/// int
ZVariant operator +(const int var1, const ZVariant &var2);
ZVariant operator -(const int var1, const ZVariant &var2);
ZVariant operator *(const int var1, const ZVariant &var2);
ZVariant operator /(const int var1, const ZVariant &var2);
ZVariant operator &(const int var1, const ZVariant &var2);
ZVariant operator |(const int var1, const ZVariant &var2);
ZVariant operator ^(const int var1, const ZVariant &var2);
ZVariant operator %(const int var1, const ZVariant &var2);

/// double
ZVariant operator +(const double &var1, const ZVariant &var2);
ZVariant operator -(const double &var1, const ZVariant &var2);
ZVariant operator *(const double &var1, const ZVariant &var2);
ZVariant operator /(const double &var1, const ZVariant &var2);

inline ZVariant operator &(const double &var1, const ZVariant &var2)
{return (int)var1 & var2;}

inline ZVariant operator |(const double &var1, const ZVariant &var2)
{return (int)var1 | var2;}

inline ZVariant operator ^(const double &var1, const ZVariant &var2)
{return (int)var1 ^ var2;}

inline ZVariant operator %(const double &var1, const ZVariant &var2)
{return (int)var1 ^ var2;}

/// string
ZVariant operator +(const QString &var1, const ZVariant &var2);
ZVariant operator -(const QString &var1, const ZVariant &var2);
ZVariant operator *(const QString &var1, const ZVariant &var2);
ZVariant operator /(const QString &var1, const ZVariant &var2);
ZVariant operator &(const QString &var1, const ZVariant &var2);
ZVariant operator |(const QString &var1, const ZVariant &var2);
ZVariant operator ^(const QString &var1, const ZVariant &var2);
ZVariant operator %(const QString &var1, const ZVariant &var2);

#define OPERATOR(OP) \
    inline ZVariant operator OP (const ZVariant &var1, const ZVariant &var2)\
    {\
        switch(var1.type()) {\
        case ZVariant::Int:\
            return var1.toInt() OP var2;\
        case ZVariant::Double:\
            return var1.toDouble() OP var2;\
        case ZVariant::String:\
            return var1.toString() OP var2;\
        case ZVariant::Bool:\
            return (int)var1.toBool() OP var2;\
        default: break;\
        }\
        return ZVariant::NaN;\
    }

#define OPERATOR_ASS(OP) \
    inline ZVariant &operator OP##=(ZVariant &var1, const ZVariant &var2)\
    {return var1 = var1 OP var2;}

OPERATOR(+)
OPERATOR(-)
OPERATOR(*)
OPERATOR(/)
OPERATOR(&)
OPERATOR(|)
OPERATOR(^)
OPERATOR(%)

OPERATOR_ASS(+)
OPERATOR_ASS(-)
OPERATOR_ASS(*)
OPERATOR_ASS(/)
OPERATOR_ASS(&)
OPERATOR_ASS(|)
OPERATOR_ASS(^)
OPERATOR_ASS(%)

inline ZVariant &operator ++(ZVariant &var, int)
{return var = 1 + var;}

inline ZVariant &operator --(ZVariant &var, int)
{return var = -1 + var;}

inline ZVariant &operator ++(ZVariant &var)
{return var = 1 + var;}

inline ZVariant &operator --(ZVariant &var)
{return var = -1 + var;}

ZVariant operator ~(const ZVariant &var);

Z_END_NAMESPACE

Q_DECLARE_METATYPE(ZVariant)
Q_DECLARE_METATYPE(ZVariant::ZGroup)

#endif // ZVARIANT_H
