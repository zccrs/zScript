#ifndef ZVARIANT_H
#define ZVARIANT_H

#include "zglobal.h"

#include <QSharedDataPointer>
#include <QVariant>

Z_BEGIN_NAMESPACE
class ZVariant;
Z_END_NAMESPACE

QT_BEGIN_NAMESPACE
uint qHash(const ZVariant &val, uint seed = 0);
QT_END_NAMESPACE

Z_BEGIN_NAMESPACE

class ZObject;
class ZFunction;

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
        Tuple = QMetaType::User + 1,
        Function = QMetaType::User + 2,
        Unknow = QMetaType::User + 3
    };

    typedef QList<ZVariant*> ZTuple;

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
    ZVariant(const ZTuple &group);
    ZVariant(ZObject * const object);
    ZVariant(ZFunction * const function);
    ZVariant(const QVariant &val);
    ~ZVariant();

    const char *typeName() const;

    inline Type type() const
    { return data->type;}

    int toInt(bool *ok = 0) const;
    double toDouble(bool *ok = 0) const;
    bool toBool() const;
    inline QString toString() const
    { return data->variant.toString();}
    QList<ZVariant> toList() const;
    inline ZTuple toTuple() const
    { if(type() == Tuple)
            return qvariant_cast<ZTuple>(data->variant);

        return ZTuple() << const_cast<ZVariant*>(this);
    }
    ZObject *toObject() const;
    ZFunction *toFunction() const;
    inline QVariant toQVariant() const
    { return data->variant;}

    inline void depthCopyAssign(const ZVariant &other) const
    {
        if(type() == Tuple) {
            const ZTuple &tuple = toTuple();
            const ZTuple &other_tuple = other.toTuple();

            int min = qMin(tuple.count(), other_tuple.count());

            for(int i = 0; i < min; ++i) {
                tuple.at(i)->depthCopyAssign(*other_tuple.at(i));
            }

            return;
        }

        VariantData *data = const_cast<VariantData*>(this->data.constData());

        data->variant = other.data->variant;
        data->type = other.data->type;
    }

    inline ZVariant& operator=(const ZVariant &other)
    {
        if(type() == Tuple) {
            const ZTuple &other_group = other.toTuple();
            const ZTuple &this_group = toTuple();

            int min = qMin(other_group.count(), this_group.count());

            for(int i = 0; i < min; ++i) {
                this_group[i]->data = other_group[i]->data;
            }
        } else {
            data = other.data;
        }

        return *this;
    }
    inline ZVariant& operator=(ZVariant &&other)
    {
        if(type() == Tuple) {
            const ZTuple &other_group = other.toTuple();
            const ZTuple &this_group = toTuple();

            int min = qMin(other_group.count(), this_group.count());

            for(int i = 0; i < min; ++i) {
                qSwap(this_group[i]->data, other_group[i]->data);
            }
        } else {
            qSwap(data, other.data);
        }

        return *this;
    }

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
        default: return Undefined;
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
        default: return Undefined;
        }
    }
    inline ZVariant operator<<(const ZVariant &value)
    {
        switch (data->type) {
        case List:
            data->variant = QVariant::fromValue(toList() += value);
            break;
        case String:
            data->variant = toString().append(value.toString());
            break;
        default:
            break;
        }

        return *this;
    }
    ZVariant operator[](const ZVariant &value) const;

    inline static ZVariant copy(const ZVariant &value)
    {
        ZVariant val(value.data->type);

        val.data->variant = value.data->variant;

        return val;
    }

    friend uint qHash(const ZVariant &val, uint seed);

private:
    class VariantData : public QSharedData
    {
        QVariant variant;
        ZVariant::Type type;

        friend class ZVariant;
    };

    QSharedDataPointer<VariantData> data;

    friend class ZCode;
};

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
        return ZVariant::Undefined;\
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

class ZSharedVariant : public ZVariant, public QSharedData
{
public:
    inline ZSharedVariant(Type type = Undefined)
        : ZVariant(type), QSharedData(){}
    inline ZSharedVariant(const ZSharedVariant& other)
        : ZVariant(other), QSharedData(other){}
    inline ZSharedVariant(ZSharedVariant &&other)
        : ZVariant(other), QSharedData(other){}
    inline ZSharedVariant(const ZVariant &variant)
        : ZVariant(variant), QSharedData(){}
    inline ZSharedVariant(ZVariant &&variant)
        : ZVariant(variant), QSharedData(){}

    inline ZSharedVariant& operator =(const ZSharedVariant &other)
    { ZVariant::operator =(other); return *this;}
    inline ZSharedVariant& operator =(ZSharedVariant &&other)
    { ZVariant::operator =(other); return *this;}
    inline ZSharedVariant& operator =(const ZVariant &other)
    { ZVariant::operator =(other); return *this;}
    inline ZSharedVariant& operator =(ZVariant &&other)
    { ZVariant::operator =(other); return *this;}
};

Z_END_NAMESPACE

QT_BEGIN_NAMESPACE
Q_CORE_EXPORT QDebug operator<<(QDebug deg, const ZVariant &var);
QT_END_NAMESPACE

Q_DECLARE_METATYPE(ZVariant)
Q_DECLARE_METATYPE(ZVariant::ZTuple)

#endif // ZVARIANT_H
