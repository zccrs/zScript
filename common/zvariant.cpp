#include "zvariant.h"
#include "zobject.h"

#include <QDebug>

Z_BEGIN_NAMESPACE

/// ZVariant
ZVariant::ZVariant(ZVariant::Type type)
    : data(new VariantData)
{
    data->type = type;
}

ZVariant::ZVariant(int val)
    : data(new VariantData)
{
    data->variant = val;
    data->type = Int;
}

ZVariant::ZVariant(uint val)
    : data(new VariantData)
{
    data->variant = val;
    data->type = UInt;
}

ZVariant::ZVariant(double val)
    : data(new VariantData)
{
    data->variant = val;
    data->type = Double;
}

ZVariant::ZVariant(bool val)
    : data(new VariantData)
{
    data->variant = val;
    data->type = Bool;
}

ZVariant::ZVariant(const char *val)
    : data(new VariantData)
{
    data->variant = val;
    data->type = String;
}

ZVariant::ZVariant(const ZVariant &other)
    : data(other.data)
{

}

ZVariant::ZVariant(ZVariant &&other)
{
    qSwap(data, other.data);
}

ZVariant::ZVariant(const QString &val)
    : data(new VariantData)
{
    data->variant = val;
    data->type = String;
}

ZVariant::ZVariant(QLatin1String val)
    : data(new VariantData)
{
    data->variant = val;
    data->type = String;
}

template <typename T>
ZVariant::ZVariant(const QList<T> &val)
    : data(new VariantData)
{
    QList<ZVariant> list;

    list.reserve(val.size());

    for(const T &v : val)
        list << ZVariant(v);

    data->variant = QVariant::fromValue(list);
    data->type = List;
}

ZVariant::ZVariant(const QList<ZVariant> &val)
    : data(new VariantData)
{
    data->variant = QVariant::fromValue(val);
    data->type = List;
}

ZVariant::ZVariant(const ZVariant::ZTuple &group)
    : data(new VariantData)
{
    data->variant = QVariant::fromValue(group);
    data->type = Tuple;
}

ZVariant::ZVariant(ZObject * const object)
    : data(new VariantData)
{
    data->variant = QVariant::fromValue(object);
    data->type = Object;
}

ZVariant::ZVariant(ZFunction * const function)
    : data(new VariantData)
{
    data->variant = QVariant::fromValue(function);
    data->type = Function;
}

ZVariant::ZVariant(const QVariant &val)
    : data(new VariantData)
{
    data->variant = val;

    switch (val.type()) {
    case QVariant::Int:
        data->type = Int;
        break;
    case QVariant::UInt:
        data->type = UInt;
        break;
    case QVariant::Double:
        data->type = Double;
        break;
    case QVariant::Bool:
        data->type = Bool;
        break;
    case QVariant::ByteArray:
    case QVariant::String:
        data->type = String;
        break;
    case QVariant::List:
        data->type = List;
        break;
    case QVariant::Invalid:
        data->type = Undefined;
        break;
    case QMetaType::PointerToQObject:
        data->type = Object;
        break;
    case QVariant::UserType:{
        if(QString(val.typeName()) == "ZObject*") {
            data->type = Object;
        } else if(QString(val.typeName()) == "ZFunction*") {
            data->type = Function;
        } else if(QString(val.typeName()) == "ZVariant") {
            data = qvariant_cast<ZVariant>(val).data;
        } else {
//            zWarning << "Unknow Type:" << val.typeName();
            data->type = Unknow;
            data->variant = val;
        }
        break;
    }
    default:
        data->type = Undefined;
        break;
    }
}

ZVariant::~ZVariant()
{
    delete data;
}

const char *ZVariant::typeName() const
{
    switch (data->type) {
    case Int:
        return "int";
    case UInt:
        return "uint";
    case Double:
        return "double";
    case Bool:
        return "boolean";
    case String:
        return "string";
    case List:
        return "list";
    case Object:
        return "object";
    case Function:
        return "function";
    case Undefined:
        return "undefined";
    case Tuple:
        return "tuple";
    default:
        return "unknow";
        break;
    }

    return data->variant.typeName();
}

int ZVariant::toInt(bool *ok) const
{
    return data->variant.toInt(ok);
}

uint ZVariant::toUInt(bool *ok) const
{
    return data->variant.toUInt(ok);
}

double ZVariant::toDouble(bool *ok) const
{
    return data->variant.toDouble(ok);
}

bool ZVariant::toBool() const
{
    switch(data->type) {
    case String:
        return !data->variant.toString().isEmpty();
    case Object:
    case Function:
        return (bool)toObject();
    case Undefined:
        return false;
    default: break;
    }

    return data->variant.toBool();
}

QList<ZVariant> ZVariant::toList() const
{
    if(type() == Tuple) {
        QList<ZVariant> list;

        for(const ZVariant *val : toTuple()) {
            list << *val;
        }

        return list;
    }

    return qvariant_cast<QList<ZVariant>>(data->variant);
}

ZObject *ZVariant::toObject() const
{
    return qvariant_cast<ZObject*>(data->variant);
}

ZFunction *ZVariant::toFunction() const
{
    return qobject_cast<ZFunction*>(toObject());
}

ZVariant ZVariant::operator[](const ZVariant &value) const
{
    switch (data->type) {
    case List: {
        bool ok = false;

        const ZVariant &val = toList().value(value.toInt(&ok));

        if(!ok)
            return ZVariant();
        else
            return val;
    }
    case Tuple: {
        bool ok;

        const ZVariant &val = *toTuple().value(value.toInt(&ok));

        if(!ok)
            return ZVariant();
        else
            return val;
    }
    case String: {
        bool ok;

        int index = value.toInt(&ok);
        const QString &str = toString();

        if(!ok || index >= str.size())
            return QString();
        else
            return QString(str.at(index));
    }
    case Function:
    case Object:
        return toObject()->property(value.toString().toLatin1().constData());
    default:
        return Undefined;
    }
}

/// global
ZVariant operator +(const int var1, const ZVariant &var2)
{
    switch(var2.type()) {
    case ZVariant::Int:
        return var1 + var2.toInt();
    case ZVariant::Double:
        return var1 + var2.toDouble();
    case ZVariant::String:
        return QString::number(var1) + var2.toString();
    case ZVariant::Bool:
        return var1 + var2.toBool();
    default: break;
    }

    return ZVariant::Undefined;
}

ZVariant operator -(const int var1, const ZVariant &var2)
{
    switch(var2.type()) {
    case ZVariant::Int:
        return var1 - var2.toInt();
    case ZVariant::Double:
        return var1 - var2.toDouble();
    case ZVariant::Bool:
        return var1 - var2.toBool();
    default: break;
    }

    return ZVariant::Undefined;
}

ZVariant operator *(const int var1, const ZVariant &var2)
{
    switch(var2.type()) {
    case ZVariant::Int:
        return var1 * var2.toInt();
    case ZVariant::Double:
        return var1 * var2.toDouble();
    case ZVariant::Bool:
        return var1 * var2.toBool();
    case ZVariant::String:
        return var2 * var1;
    default: break;
    }

    return ZVariant::Undefined;
}

ZVariant operator /(const int var1, const ZVariant &var2)
{
    switch(var2.type()) {
    case ZVariant::Int:
        return var1 / var2.toInt();
    case ZVariant::Double:
        return var1 / var2.toDouble();
    case ZVariant::Bool:
        return var1 / var2.toBool();
    default: break;
    }

    return ZVariant::Undefined;
}

ZVariant operator &(const int var1, const ZVariant &var2)
{
    switch(var2.type()) {
    case ZVariant::Int:
        return var1 & var2.toInt();
    case ZVariant::Double:
        return var1 & (int)var2.toDouble();
    case ZVariant::Bool:
        return var1 & var2.toBool();
    default: break;
    }

    return ZVariant::Undefined;
}

ZVariant operator |(const int var1, const ZVariant &var2)
{
    switch(var2.type()) {
    case ZVariant::Int:
        return var1 | var2.toInt();
    case ZVariant::Double:
        return var1 | (int)var2.toDouble();
    case ZVariant::Bool:
        return var1 | var2.toBool();
    default: break;
    }

    return ZVariant::Undefined;
}

ZVariant operator ^(const int var1, const ZVariant &var2)
{
    switch(var2.type()) {
    case ZVariant::Int:
        return var1 ^ var2.toInt();
    case ZVariant::Double:
        return var1 ^ (int)var2.toDouble();
    case ZVariant::Bool:
        return var1 ^ var2.toBool();
    default: break;
    }

    return ZVariant::Undefined;
}

ZVariant operator %(const int var1, const ZVariant &var2)
{
    switch(var2.type()) {
    case ZVariant::Int:
        return var1 % var2.toInt();
    case ZVariant::Double:
        return var1 % (int)var2.toDouble();
    case ZVariant::Bool:
        return var1 % var2.toBool();
    default: break;
    }

    return ZVariant::Undefined;
}

ZVariant operator +(const double &var1, const ZVariant &var2)
{
    switch(var2.type()) {
    case ZVariant::Int:
        return var1 + var2.toInt();
    case ZVariant::Double:
        return var1 + var2.toDouble();
    case ZVariant::String:
        return QString::number(var1) + var2.toString();
    case ZVariant::Bool:
        return var1 + var2.toBool();
    default: break;
    }

    return ZVariant::Undefined;
}

ZVariant operator -(const double &var1, const ZVariant &var2)
{
    switch(var2.type()) {
    case ZVariant::Int:
        return var1 - var2.toInt();
    case ZVariant::Double:
        return var1 - var2.toDouble();
    case ZVariant::Bool:
        return var1 - var2.toBool();
    default: break;
    }

    return ZVariant::Undefined;
}

ZVariant operator *(const double &var1, const ZVariant &var2)
{
    switch(var2.type()) {
    case ZVariant::Int:
        return var1 * var2.toInt();
    case ZVariant::Double:
        return var1 * var2.toDouble();
    case ZVariant::Bool:
        return var1 * var2.toBool();
    default: break;
    }

    return ZVariant::Undefined;
}

ZVariant operator /(const double &var1, const ZVariant &var2)
{
    switch(var2.type()) {
    case ZVariant::Int:
        return var1 / var2.toInt();
    case ZVariant::Double:
        return var1 / var2.toDouble();
    case ZVariant::Bool:
        return var1 / var2.toBool();
    default: break;
    }

    return ZVariant::Undefined;
}

ZVariant operator +(const QString &var1, const ZVariant &var2)
{
    switch(var2.type()) {
    case ZVariant::Int:
        return var1 + QString::number(var2.toInt());
    case ZVariant::Double:
        return var1 + QString::number(var2.toDouble());
    case ZVariant::String:
        return var1 + var2.toString();
    case ZVariant::Bool:
        return var1 + (var2.toBool() ? "true" : "false");
    default: break;
    }

    return ZVariant::Undefined;
}

ZVariant operator -(const QString &var1, const ZVariant &var2)
{
    const QString &str = var2.toString();

    if(!str.isEmpty())
        return QString(var1).replace(str, "");

    return var1;
}

ZVariant operator *(const QString &var1, const ZVariant &var2)
{
    if(var2.type() == ZVariant::Int) {
        QString array;
        int count = var2.toInt();

        array.reserve(var1.size() * count);

        while(count-- > 0)
            array.append(var1);

        return array;
    }

    return ZVariant::Undefined;
}

ZVariant operator /(const QString &var1, const ZVariant &var2)
{
    const QString &str = var2.toString();

    if(str.isEmpty())
        return var1;

    return QString(var1).split(str);
}

ZVariant operator &(const QString &var1, const ZVariant &var2)
{
    const QString var2Str = var2.toString();

    if(var2Str.isEmpty())
        return var1;

    QString str;

    int max_size = qMax(var1.size(), var2Str.size());

    str.reserve(max_size);

    for(int i = 0; i < max_size; ++i) {
        str[i] = var1.at(i % var1.size()).unicode() & var2Str.at(i % var2Str.size()).unicode();
    }

    return str;
}

ZVariant operator |(const QString &var1, const ZVariant &var2)
{
    const QString var2Str = var2.toString();

    if(var2Str.isEmpty())
        return var1;

    QString str;

    int max_size = qMax(var1.size(), var2Str.size());

    str.reserve(max_size);

    for(int i = 0; i < max_size; ++i) {
        str[i] = var1.at(i % var1.size()).unicode() | var2Str.at(i % var2Str.size()).unicode();
    }

    return str;
}

ZVariant operator ^(const QString &var1, const ZVariant &var2)
{
    const QString var2Str = var2.toString();

    if(var2Str.isEmpty())
        return var1;

    QString str;

    int max_size = qMax(var1.size(), var2Str.size());

    str.reserve(max_size);

    for(int i = 0; i < max_size; ++i) {
        str[i] = var1.at(i % var1.size()).unicode() ^ var2Str.at(i % var2Str.size()).unicode();
    }

    return str;
}

ZVariant operator %(const QString &var1, const ZVariant &var2)
{
    const QString var2Str = var2.toString();

    if(var2Str.isEmpty())
        return var1;

    QString str;

    int max_size = qMax(var1.size(), var2Str.size());

    str.reserve(max_size);

    for(int i = 0; i < max_size; ++i) {
        str[i] = var1.at(i % var1.size()).unicode() % var2Str.at(i % var2Str.size()).unicode();
    }

    return str;
}

ZVariant operator ~(const ZVariant &var)
{
    switch(var.type()) {
    case ZVariant::Int:
        return ~var.toInt();
    case ZVariant::Double:
        return ~(int)var.toDouble();
    case ZVariant::Bool:
        return ~var.toBool();
    case ZVariant::String:{
        QString str = var.toString();

        for(QChar &ch : str) {
            if(ch.isLower())
                ch = ch.toUpper();
            else
                ch = ch.toLower();
        }

        return str;
    }
    default: break;
    }

    return ZVariant::Undefined;
}

Z_END_NAMESPACE

QDebug operator<<(QDebug deg, const ZVariant &var)
{
    deg.nospace() << "Variant(" << var.typeName() << ", ";

    switch(var.type()) {
    case ZVariant::Object:
        deg.nospace() << var.toObject();
        break;
    case ZVariant::Function:
        deg.nospace() << var.toFunction();
        break;
    case ZVariant::Undefined:
        deg.nospace() << var.typeName();
        break;
    case ZVariant::List:
    case ZVariant::Tuple:
        deg.noquote() << var.toList();
        break;
    case ZVariant::Int:
    case ZVariant::Double:
        deg.noquote() << var.toDouble();
        break;
    default:
        deg.nospace() << var.toString();
        break;
    }

    deg.nospace() << ")";

    return deg;
}

QT_BEGIN_NAMESPACE
uint qHash(const ZVariant &val, uint seed)
{
    switch (val.type()) {
    case ZVariant::Int:
        return qHash(val.toInt(), seed);
    case ZVariant::Double:
        return qHash(val.toDouble(), seed);
    case ZVariant::String:
        return qHash(val.toString(), seed);
    case ZVariant::Bool:
        return qHash(val.toBool(), seed);
    case ZVariant::List:
        return qHash(val.toList(), seed);
    case ZVariant::Object:
    case ZVariant::Function:
        return qHash(val.toObject(), seed);
    case ZVariant::Tuple: {
        uint hash = 0;

        for(const ZVariant *tmp_val : val.toTuple()) {
            hash ^= qHash(*tmp_val, seed);
        }

        return hash;
    }
    default:
        return -1;
    }
}
QT_END_NAMESPACE
