#include "global.h"

#include <QFile>
#include <QVariant>

Variant::Variant(Variant::Type type)
    : data(new VariantData)
{
    qRegisterMetaType<Variant>("Variant");

    data->type = type;
}

Variant::Variant(int val)
    : data(new VariantData)
{
    qRegisterMetaType<Variant>("Variant");

    data->variant = val;
    data->type = Int;
}

Variant::Variant(double val)
    : data(new VariantData)
{
    qRegisterMetaType<Variant>("Variant");

    data->variant = val;
    data->type = Double;
}

Variant::Variant(bool val)
    : data(new VariantData)
{
    qRegisterMetaType<Variant>("Variant");

    data->variant = val;
    data->type = Bool;
}

Variant::Variant(const char *val)
    : data(new VariantData)
{
    qRegisterMetaType<Variant>("Variant");

    data->variant = val;
    data->type = String;
}

Variant::Variant(const Variant &other)
    : data(other.data)
{

}

Variant::Variant(const QString &val)
    : data(new VariantData)
{
    qRegisterMetaType<Variant>("Variant");

    data->variant = val;
    data->type = String;
}

Variant::Variant(QLatin1String val)
    : data(new VariantData)
{
    qRegisterMetaType<Variant>("Variant");

    data->variant = val;
    data->type = String;
}

Variant::Variant(const QList<Variant> &val)
    : data(new VariantData)
{
    qRegisterMetaType<Variant>("Variant");

    data->variant = QVariant::fromValue(val);
    data->type = List;
}

template <typename T>
Variant::Variant(const QList<T> &val)
    : data(new VariantData)
{
    qRegisterMetaType<Variant>("Variant");

    QList<Variant> list;

    list.reserve(val.size());

    for(const T &v : val)
        list << Variant(v);

    data->variant = QVariant::fromValue(list);
    data->type = List;
}

Variant::Variant(QObject * const object)
    : data(new VariantData)
{
    qRegisterMetaType<Variant>("Variant");

    data->variant = QVariant::fromValue(object);
    data->type = object ? Object : Null;
}

Variant::~Variant()
{

}

Variant::Type Variant::type() const
{
    return data->type;
}

const char *Variant::typeName() const
{
    return data->variant.typeName();
}

int Variant::toInt(bool *ok) const
{
    return data->variant.toInt(ok);
}

double Variant::toDouble(bool *ok) const
{
    return data->variant.toDouble(ok);
}

bool Variant::toBool() const
{
    return data->variant.toBool();
}

QString Variant::toString() const
{
    return data->variant.toString();
}

QList<Variant> Variant::toList() const
{
    return qvariant_cast<QList<Variant>>(data->variant);
}

QObject *Variant::toObject() const
{
    return qvariant_cast<QObject*>(data->variant);
}

QDebug operator<<(QDebug deg, const Variant &var)
{
    deg.nospace() << "Variant(" << var.typeName() << ",";

    switch(var.type()) {
    case Variant::Object:
        deg.nospace() << var.toObject();
        break;
    case Variant::List:
        deg.nospace() << var.toList();
        break;
    default:
        deg.nospace() << var.toString();
        break;
    }

    deg.nospace() << ")";

    return deg;
}

Variant operator +(const int var1, const Variant &var2)
{
    switch(var2.type()) {
    case Variant::Int:
        return var1 + var2.toInt();
    case Variant::Double:
        return var1 + var2.toDouble();
    case Variant::String:
        return QString::number(var1) + var2.toString();
    case Variant::Bool:
        return var1 + var2.toBool();
    default: break;
    }

    return Variant::NaN;
}

Variant operator -(const int var1, const Variant &var2)
{
    switch(var2.type()) {
    case Variant::Int:
        return var1 - var2.toInt();
    case Variant::Double:
        return var1 - var2.toDouble();
    case Variant::Bool:
        return var1 - var2.toBool();
    default: break;
    }

    return Variant::NaN;
}

Variant operator *(const int var1, const Variant &var2)
{
    switch(var2.type()) {
    case Variant::Int:
        return var1 * var2.toInt();
    case Variant::Double:
        return var1 * var2.toDouble();
    case Variant::Bool:
        return var1 * var2.toBool();
    case Variant::String:
        return var2 * var1;
    default: break;
    }

    return Variant::NaN;
}

Variant operator /(const int var1, const Variant &var2)
{
    switch(var2.type()) {
    case Variant::Int:
        return var1 / var2.toInt();
    case Variant::Double:
        return var1 / var2.toDouble();
    case Variant::Bool:
        return var1 / var2.toBool();
    default: break;
    }

    return Variant::NaN;
}

Variant operator &&(const int var1, const Variant &var2)
{
    switch(var2.type()) {
    case Variant::Int:
        return var1 && var2.toInt();
    case Variant::Double:
        return var1 && var2.toDouble();
    case Variant::Bool:
        return var1 && var2.toBool();
    default: break;
    }

    return Variant::NaN;
}

Variant operator ||(const int var1, const Variant &var2)
{
    switch(var2.type()) {
    case Variant::Int:
        return var1 || var2.toInt();
    case Variant::Double:
        return var1 || var2.toDouble();
    case Variant::Bool:
        return var1 || var2.toBool();
    default: break;
    }

    return Variant::NaN;
}

Variant operator &(const int var1, const Variant &var2)
{
    switch(var2.type()) {
    case Variant::Int:
        return var1 & var2.toInt();
    case Variant::Double:
        return var1 & (int)var2.toDouble();
    case Variant::Bool:
        return var1 & var2.toBool();
    default: break;
    }

    return Variant::NaN;
}

Variant operator |(const int var1, const Variant &var2)
{
    switch(var2.type()) {
    case Variant::Int:
        return var1 | var2.toInt();
    case Variant::Double:
        return var1 | (int)var2.toDouble();
    case Variant::Bool:
        return var1 | var2.toBool();
    default: break;
    }

    return Variant::NaN;
}

Variant operator ^(const int var1, const Variant &var2)
{
    switch(var2.type()) {
    case Variant::Int:
        return var1 ^ var2.toInt();
    case Variant::Double:
        return var1 ^ (int)var2.toDouble();
    case Variant::Bool:
        return var1 ^ var2.toBool();
    default: break;
    }

    return Variant::NaN;
}

Variant operator +(const double &var1, const Variant &var2)
{
    switch(var2.type()) {
    case Variant::Int:
        return var1 + var2.toInt();
    case Variant::Double:
        return var1 + var2.toDouble();
    case Variant::String:
        return QString::number(var1) + var2.toString();
    case Variant::Bool:
        return var1 + var2.toBool();
    default: break;
    }

    return Variant::NaN;
}

Variant operator -(const double &var1, const Variant &var2)
{
    switch(var2.type()) {
    case Variant::Int:
        return var1 - var2.toInt();
    case Variant::Double:
        return var1 - var2.toDouble();
    case Variant::Bool:
        return var1 - var2.toBool();
    default: break;
    }

    return Variant::NaN;
}

Variant operator *(const double &var1, const Variant &var2)
{
    switch(var2.type()) {
    case Variant::Int:
        return var1 * var2.toInt();
    case Variant::Double:
        return var1 * var2.toDouble();
    case Variant::Bool:
        return var1 * var2.toBool();
    default: break;
    }

    return Variant::NaN;
}

Variant operator /(const double &var1, const Variant &var2)
{
    switch(var2.type()) {
    case Variant::Int:
        return var1 / var2.toInt();
    case Variant::Double:
        return var1 / var2.toDouble();
    case Variant::Bool:
        return var1 / var2.toBool();
    default: break;
    }

    return Variant::NaN;
}

Variant operator +(const QString &var1, const Variant &var2)
{
    switch(var2.type()) {
    case Variant::Int:
        return var1 + QString::number(var2.toInt());
    case Variant::Double:
        return var1 + QString::number(var2.toDouble());
    case Variant::String:
        return var1 + var2.toString();
    case Variant::Bool:
        return var1 + (var2.toBool() ? "true" : "false");
    default: break;
    }

    return Variant::NaN;
}

Variant operator -(const QString &var1, const Variant &var2)
{
    const QString &str = var2.toString();

    if(!str.isEmpty())
        return QString(var1).replace(str, "");

    return var1;
}

Variant operator *(const QString &var1, const Variant &var2)
{
    if(var2.type() == Variant::Int) {
        QString array;
        int count = var2.toInt();

        array.reserve(var1.size() * count);

        while(count-- > 0)
            array.append(var1);

        return array;
    }

    return Variant::NaN;
}

Variant operator /(const QString &var1, const Variant &var2)
{
    const QString &str = var2.toString();

    if(str.isEmpty())
        return var1;

    return QString(var1).split(str);
}

Variant operator !(const Variant &var)
{
    switch(var.type()) {
    case Variant::Int:
        return !var.toInt();
    case Variant::Double:
        return !var.toDouble();
    case Variant::Bool:
        return !var.toBool();
    default: break;
    }

    return Variant::NaN;
}

QByteArray readFile(const QString &fileName)
{
    QFile file(fileName);
    QByteArray re;

    if(file.open(QIODevice::ReadOnly)) {
        re = file.readAll();
        file.close();
    }

    return re;
}


