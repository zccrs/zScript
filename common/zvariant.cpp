#include "zvariant.h"
#include "zobject.h"

#include <QDebug>

Z_BEGIN_NAMESPACE

/// ZVariant
ZVariant::ZVariant(ZVariant::Type type)
    : m_data(new VariantData)
{
    m_data->type = type;
}

ZVariant::ZVariant(int val)
    : m_data(new VariantData)
{
    m_data->variant = val;
    m_data->type = Int;
}

ZVariant::ZVariant(double val)
    : m_data(new VariantData)
{
    m_data->variant = val;
    m_data->type = Double;
}

ZVariant::ZVariant(bool val)
    : m_data(new VariantData)
{
    m_data->variant = val;
    m_data->type = Bool;
}

ZVariant::ZVariant(const char *val)
    : m_data(new VariantData)
{
    m_data->variant = val;
    m_data->type = String;
}

ZVariant::ZVariant(const ZVariant &other)
    : m_data(other.m_data)
{

}

ZVariant::ZVariant(ZVariant &&other)
{
    m_data.swap(other.m_data);
}

ZVariant::ZVariant(const QString &val)
    : m_data(new VariantData)
{
    m_data->variant = val;
    m_data->type = String;
}

ZVariant::ZVariant(QLatin1String val)
    : m_data(new VariantData)
{
    m_data->variant = val;
    m_data->type = String;
}

template <typename T>
ZVariant::ZVariant(const QList<T> &val)
    : m_data(new VariantData)
{
    QList<ZVariant> list;

    list.reserve(val.size());

    for(const T &v : val)
        list << ZVariant(v);

    m_data->variant = QVariant::fromValue(list);
    m_data->type = List;
}

ZVariant::ZVariant(const QList<ZVariant> &val)
    : m_data(new VariantData)
{
    m_data->variant = QVariant::fromValue(val);
    m_data->type = List;
}

ZVariant::ZVariant(const ZVariant::ZTuple &group)
    : m_data(new VariantData)
{
    m_data->variant = QVariant::fromValue(group);
    m_data->type = Tuple;
}

ZVariant::ZVariant(ZObject * const object)
    : m_data(new VariantData)
{
    m_data->variant = QVariant::fromValue(object);
    m_data->type = Object;
}

ZVariant::ZVariant(ZFunction * const function)
    : m_data(new VariantData)
{
    m_data->variant = QVariant::fromValue(function);
    m_data->type = Function;
}

ZVariant::ZVariant(const QVariant &val)
    : m_data(new VariantData)
{
    m_data->variant = val;

    switch (val.type()) {
    case QVariant::Int:
        m_data->type = Int;
        break;
    case QVariant::Double:
        m_data->type = Double;
        break;
    case QVariant::Bool:
        m_data->type = Bool;
        break;
    case QVariant::ByteArray:
    case QVariant::String:
        m_data->type = String;
        break;
    case QVariant::List:
        m_data->type = List;
        break;
    case QVariant::Invalid:
        m_data->type = Undefined;
        break;
    case QMetaType::PointerToQObject:
        m_data->type = Object;
        break;
    case QVariant::UserType:{
        if(QString(val.typeName()) == "ZObject*") {
            m_data->type = Object;
        } else if(QString(val.typeName()) == "ZFunction*") {
            m_data->type = Function;
        } else if(QString(val.typeName()) == "ZVariant") {
            m_data = qvariant_cast<ZVariant>(val).m_data;
        } else {
//            zWarning << "Unknow Type:" << val.typeName();
            m_data->type = Unknow;
            m_data->variant = val;
        }
        break;
    }
    default:
        m_data->type = Undefined;
        break;
    }
}

ZVariant::~ZVariant()
{

}

const char *ZVariant::typeName() const
{
    switch (m_data->type) {
    case Int:
        return "int";
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

    return m_data->variant.typeName();
}

int ZVariant::toInt(bool *ok) const
{
    if(ok)
        *ok = true;

    switch(m_data->type) {
    case Int:
        return m_data->variant.toInt();
    case Double:
        return (int)m_data->variant.toDouble();
    case Bool:
        return m_data->variant.toBool();
    case String:
        return m_data->variant.toString().toInt(ok);
    case Object:
    case Function:
    case Undefined:
        if(ok)
            *ok = false;
        return 0;
    default:break;
    }

    return m_data->variant.toInt(ok);
}

double ZVariant::toDouble(bool *ok) const
{
    if(ok)
        *ok = true;

    switch(m_data->type) {
    case Int:
        return m_data->variant.toInt();
    case Double:
        return m_data->variant.toDouble();
    case Bool:
        return m_data->variant.toBool();
    case String:
        return m_data->variant.toString().toDouble(ok);
    case Object:
    case Function:
    case Undefined:
        if(ok)
            *ok = false;
        return 0;
    default:break;
    }

    return m_data->variant.toDouble(ok);
}

bool ZVariant::toBool() const
{
    switch(m_data->type) {
    case Int:
        return m_data->variant.toInt();
    case Double:
        return (int)m_data->variant.toDouble();
    case Bool:
        return m_data->variant.toBool();
    case String:
        return !m_data->variant.toString().isEmpty();
    case Object:
    case Function:
        return (bool)toObject();
    case Undefined:
        return false;
    default: break;
    }

    return m_data->variant.toBool();
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

    return qvariant_cast<QList<ZVariant>>(m_data->variant);
}

ZObject *ZVariant::toObject() const
{
    return qvariant_cast<ZObject*>(m_data->variant);
}

ZFunction *ZVariant::toFunction() const
{
    return qobject_cast<ZFunction*>(toObject());
}

ZVariant ZVariant::operator[](const ZVariant &value) const
{
    switch (m_data->type) {
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

QT_BEGIN_NAMESPACE
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
