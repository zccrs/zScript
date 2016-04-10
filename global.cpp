#include "global.h"

#include <QFile>
#include <QVariant>

namespace Global {

/// ZVariant
ZVariant::ZVariant(ZVariant::Type type)
    : data(new VariantData)
{
    qRegisterMetaType<ZVariant>("ZVariant");

    data->type = type;
}

ZVariant::ZVariant(int val)
    : data(new VariantData)
{
    qRegisterMetaType<ZVariant>("ZVariant");

    data->variant = val;
    data->type = Int;
}

ZVariant::ZVariant(double val)
    : data(new VariantData)
{
    qRegisterMetaType<ZVariant>("ZVariant");

    data->variant = val;
    data->type = Double;
}

ZVariant::ZVariant(bool val)
    : data(new VariantData)
{
    qRegisterMetaType<ZVariant>("ZVariant");

    data->variant = val;
    data->type = Bool;
}

ZVariant::ZVariant(const char *val)
    : data(new VariantData)
{
    qRegisterMetaType<ZVariant>("ZVariant");

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
    qRegisterMetaType<ZVariant>("ZVariant");

    data->variant = val;
    data->type = String;
}

ZVariant::ZVariant(QLatin1String val)
    : data(new VariantData)
{
    qRegisterMetaType<ZVariant>("ZVariant");

    data->variant = val;
    data->type = String;
}

ZVariant::ZVariant(const QList<ZVariant> &val)
    : data(new VariantData)
{
    qRegisterMetaType<ZVariant>("ZVariant");

    data->variant = QVariant::fromValue(val);
    data->type = List;
}

template <typename T>
ZVariant::ZVariant(const QList<T> &val)
    : data(new VariantData)
{
    qRegisterMetaType<ZVariant>("ZVariant");

    QList<ZVariant> list;

    list.reserve(val.size());

    for(const T &v : val)
        list << ZVariant(v);

    data->variant = QVariant::fromValue(list);
    data->type = List;
}

ZVariant::ZVariant(ZObject * const object)
    : data(new VariantData)
{
    qRegisterMetaType<ZVariant>("ZVariant");

    data->variant = QVariant::fromValue(object);
    data->type = object ? Object : Null;
}

ZVariant::ZVariant(const QVariant &val)
    : data(new VariantData)
{
    data->variant = val;

    switch (val.type()) {
    case QVariant::Int:
        data->type = Int;
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
            data->type = toObject() ? Object : Null;
        } else if(QString(val.typeName()) == "ZVariant") {
            data = qvariant_cast<ZVariant>(val).data;
        } else {
            zError << "Unknow Type:" << val.typeName();
        }
        break;
    }
    default:
        data->type = NaN;
        break;
    }
}

ZVariant::~ZVariant()
{

}

ZVariant::Type ZVariant::type() const
{
    return data->type;
}

const char *ZVariant::typeName() const
{
    if(data->type == NaN)
        return "NaN";
    else if(data->type == Undefined)
        return "Undefined";

    return data->variant.typeName();
}

int ZVariant::toInt(bool *ok) const
{
    switch(data->type) {
    case Int:
        return data->variant.toInt();
    case Double:
        return (int)data->variant.toDouble();
    case Bool:
        return data->variant.toBool();
    case String:
    case Object:
    case Null:
    case Undefined:
    case NaN:
        if(ok)
            *ok = false;
        return 0;
    default:break;
    }

    return data->variant.toInt(ok);
}

double ZVariant::toDouble(bool *ok) const
{
    return data->variant.toDouble(ok);
}

bool ZVariant::toBool() const
{
    switch(data->type) {
    case Int:
        return data->variant.toInt();
    case Double:
        return (int)data->variant.toDouble();
    case Bool:
        return data->variant.toBool();
    case String:
        return !data->variant.toString().isEmpty();
    case Object:
        return true;
    case Null:
    case Undefined:
    case NaN:
        return false;
    default: break;
    }

    return data->variant.toBool();
}

QString ZVariant::toString() const
{
    switch (data->type) {
    case Object:
        return QString::number((qlonglong)toObject(), 16);
    case Null:
        return "0x0";
    case NaN:
    case Undefined:
        return QString(typeName());
    default:
        break;
    }

    return data->variant.toString();
}

QList<ZVariant> ZVariant::toList() const
{
    return qvariant_cast<QList<ZVariant>>(data->variant);
}

ZObject *ZVariant::toObject() const
{
    return qvariant_cast<ZObject*>(data->variant);
}

QVariant ZVariant::toQVariant() const
{
    return data->variant;
}

QDebug operator<<(QDebug deg, const ZVariant &var)
{
    deg.nospace() << "Variant(" << var.typeName() << ",";

    switch(var.type()) {
    case ZVariant::Null:
    case ZVariant::Object:
        deg.nospace() << var.toObject();
        break;
    case ZVariant::List:
        deg.nospace() << var.toList();
        break;
    case ZVariant::NaN:
    case ZVariant::Undefined:
        deg.nospace() << var.typeName();
    default:
        deg.nospace() << var.toString();
        break;
    }

    deg.nospace() << ")";

    return deg;
}

/// ZObject
ZObject::ZObject(ZObject *parent)
    : QObject(parent)
{

}

ZVariant ZObject::property(const char *name) const
{
    return ZVariant(QObject::property(name));
}

void ZObject::setProperty(const char *name, const ZVariant &value)
{
    QObject::setProperty(name, value.toQVariant());
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

    return ZVariant::NaN;
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

    return ZVariant::NaN;
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

    return ZVariant::NaN;
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

    return ZVariant::NaN;
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

    return ZVariant::NaN;
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

    return ZVariant::NaN;
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

    return ZVariant::NaN;
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

    return ZVariant::NaN;
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

    return ZVariant::NaN;
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

    return ZVariant::NaN;
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

    return ZVariant::NaN;
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

    return ZVariant::NaN;
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

    return ZVariant::NaN;
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

    return ZVariant::NaN;
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

    return ZVariant::NaN;
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

QHash<QByteArray, IdentifierValue*> identifiersHash;

ZVariant &NodeValue::getValue() const
{
    switch(operatorType) {
    case '=': {
        if(right)
            *left = right->getValue();
        else
            *left = ZVariant();

        break;
    }
    case '+': {
        *value = left->getValue() + right->getValue();
        break;
    }
    case '-': {
        *value = left->getValue() - right->getValue();
        break;
    }
    case '*': {
        *value = left->getValue() * right->getValue();
        break;
    }
    case '/': {
        *value = left->getValue() / right->getValue();
        break;
    }
    }

    return *value;
}

}/// namespace Global end
