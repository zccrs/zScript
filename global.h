#ifndef GLOBAL_H
#define GLOBAL_H

#define zDebug qDebug().noquote() << __FILE__ << __LINE__ << __FUNCTION__ << "[Debug]:"
#define zError qCritical().noquote() << "[Error]:"
#define zInfo qInfo().noquote() << "[Info]:"
#define zWarning qWarning().noquote() << "[Warning]:"
#define zPrint qDebug().noquote()
#define zStandardPrint std::cout
#define zExit(code) exit(code)
#define zErrorQuit zExit(-1)
#define zQuit zExit(0)

#include <QVariant>
#include <QDebug>

Q_CORE_EXPORT QDebug operator<<(QDebug deg, const QVariant &var)
{
    deg.nospace() << "Variant(" << var.typeName() << "," << var.toString() << ")";

    return deg;
}

QVariant operator +(const int var1, const QVariant &var2)
{
    switch(var2.type()) {
    case QVariant::Int:
        return var1 + var2.toInt();
    case QVariant::Double:
        return var1 + var2.toDouble();
    case QVariant::ByteArray:
        return QByteArray::number(var1) + var2.toByteArray();
    case QVariant::Bool:
        return var1 + var2.toBool();
    default: break;
    }

    return QVariant::Invalid;
}

QVariant operator -(const int var1, const QVariant &var2)
{
    switch(var2.type()) {
    case QVariant::Int:
        return var1 - var2.toInt();
    case QVariant::Double:
        return var1 - var2.toDouble();
    case QVariant::Bool:
        return var1 - var2.toBool();
    default: break;
    }

    return QVariant::Invalid;
}

QVariant operator *(const int var1, const QVariant &var2)
{
    switch(var2.type()) {
    case QVariant::Int:
        return var1 * var2.toInt();
    case QVariant::Double:
        return var1 * var2.toDouble();
    case QVariant::Bool:
        return var1 * var2.toBool();
    default: break;
    }

    return QVariant::Invalid;
}

QVariant operator /(const int var1, const QVariant &var2)
{
    switch(var2.type()) {
    case QVariant::Int:
        return var1 / var2.toInt();
    case QVariant::Double:
        return var1 / var2.toDouble();
    case QVariant::Bool:
        return var1 / var2.toBool();
    default: break;
    }

    return QVariant::Invalid;
}

QVariant operator &&(const int var1, const QVariant &var2)
{
    switch(var2.type()) {
    case QVariant::Int:
        return var1 && var2.toInt();
    case QVariant::Double:
        return var1 && var2.toDouble();
    case QVariant::Bool:
        return var1 && var2.toBool();
    default: break;
    }

    return QVariant::Invalid;
}

QVariant operator ||(const int var1, const QVariant &var2)
{
    switch(var2.type()) {
    case QVariant::Int:
        return var1 || var2.toInt();
    case QVariant::Double:
        return var1 || var2.toDouble();
    case QVariant::Bool:
        return var1 || var2.toBool();
    default: break;
    }

    return QVariant::Invalid;
}

QVariant operator &(const int var1, const QVariant &var2)
{
    switch(var2.type()) {
    case QVariant::Int:
        return var1 & var2.toInt();
    case QVariant::Double:
        return var1 & (int)var2.toDouble();
    case QVariant::Bool:
        return var1 & var2.toBool();
    default: break;
    }

    return QVariant::Invalid;
}

QVariant operator |(const int var1, const QVariant &var2)
{
    switch(var2.type()) {
    case QVariant::Int:
        return var1 | var2.toInt();
    case QVariant::Double:
        return var1 | (int)var2.toDouble();
    case QVariant::Bool:
        return var1 | var2.toBool();
    default: break;
    }

    return QVariant::Invalid;
}

QVariant operator ^(const int var1, const QVariant &var2)
{
    switch(var2.type()) {
    case QVariant::Int:
        return var1 ^ var2.toInt();
    case QVariant::Double:
        return var1 ^ (int)var2.toDouble();
    case QVariant::Bool:
        return var1 ^ var2.toBool();
    default: break;
    }

    return QVariant::Invalid;
}

QVariant operator +(const double &var1, const QVariant &var2)
{
    switch(var2.type()) {
    case QVariant::Int:
        return var1 + var2.toInt();
    case QVariant::Double:
        return var1 + var2.toDouble();
    case QVariant::ByteArray:
        return QByteArray::number(var1) + var2.toByteArray();
    case QVariant::Bool:
        return var1 + var2.toBool();
    default: break;
    }

    return QVariant::Invalid;
}

QVariant operator -(const double &var1, const QVariant &var2)
{
    switch(var2.type()) {
    case QVariant::Int:
        return var1 - var2.toInt();
    case QVariant::Double:
        return var1 - var2.toDouble();
    case QVariant::Bool:
        return var1 - var2.toBool();
    default: break;
    }

    return QVariant::Invalid;
}

QVariant operator *(const double &var1, const QVariant &var2)
{
    switch(var2.type()) {
    case QVariant::Int:
        return var1 * var2.toInt();
    case QVariant::Double:
        return var1 * var2.toDouble();
    case QVariant::Bool:
        return var1 * var2.toBool();
    default: break;
    }

    return QVariant::Invalid;
}

QVariant operator /(const double &var1, const QVariant &var2)
{
    switch(var2.type()) {
    case QVariant::Int:
        return var1 / var2.toInt();
    case QVariant::Double:
        return var1 / var2.toDouble();
    case QVariant::Bool:
        return var1 / var2.toBool();
    default: break;
    }

    return QVariant::Invalid;
}

QVariant operator &&(const double &var1, const QVariant &var2)
{
    return (int)var1 && var2;
}

QVariant operator ||(const double &var1, const QVariant &var2)
{
    return (int)var1 || var2;
}

QVariant operator &(const double &var1, const QVariant &var2)
{
    return (int)var1 & var2;
}

QVariant operator |(const double &var1, const QVariant &var2)
{
    return (int)var1 | var2;
}

QVariant operator ^(const double &var1, const QVariant &var2)
{
    return (int)var1 ^ var2;
}

QVariant operator +(const bool var1, const QVariant &var2)
{
    return (int)var1 + var2;
}

QVariant operator -(const bool var1, const QVariant &var2)
{
    return (int)var1 - var2;
}

QVariant operator *(const bool var1, const QVariant &var2)
{
    return (int)var1 * var2;
}

QVariant operator /(const bool var1, const QVariant &var2)
{
    return (int)var1 / var2;
}

QVariant operator &&(const bool var1, const QVariant &var2)
{
    return (int)var1 && var2;
}

QVariant operator ||(const bool var1, const QVariant &var2)
{
    return (int)var1 || var2;
}

QVariant operator &(const bool var1, const QVariant &var2)
{
    return (int)var1 & var2;
}

QVariant operator |(const bool var1, const QVariant &var2)
{
    return (int)var1 | var2;
}

QVariant operator ^(const bool var1, const QVariant &var2)
{
    return (int)var1 ^ var2;
}

QVariant operator +(const QByteArray &var1, const QVariant &var2)
{
    switch(var2.type()) {
    case QVariant::Int:
        return var1 + QByteArray::number(var2.toInt());
    case QVariant::Double:
        return var1 + QByteArray::number(var2.toDouble());
    case QVariant::ByteArray:
        return var1 + var2.toByteArray();
    case QVariant::Bool:
        return var1 + (var2.toBool() ? "true" : "false");
    default: break;
    }

    return QVariant::Invalid;
}

QVariant operator -(const QByteArray &/*var1*/, const QVariant &/*var2*/)
{
    return QVariant::Invalid;
}

QVariant operator *(const QByteArray &/*var1*/, const QVariant &/*var2*/)
{
    return QVariant::Invalid;
}

QVariant operator /(const QByteArray &/*var1*/, const QVariant &/*var2*/)
{
    return QVariant::Invalid;
}

QVariant operator &&(const QByteArray &/*var1*/, const QVariant &/*var2*/)
{
    return QVariant::Invalid;
}

QVariant operator ||(const QByteArray &/*var1*/, const QVariant &/*var2*/)
{
    return QVariant::Invalid;
}

QVariant operator &(const QByteArray &/*var1*/, const QVariant &/*var2*/)
{
    return QVariant::Invalid;
}

QVariant operator |(const QByteArray &/*var1*/, const QVariant &/*var2*/)
{
    return QVariant::Invalid;
}

QVariant operator ^(const QByteArray &/*var1*/, const QVariant &/*var2*/)
{
    return QVariant::Invalid;
}

#define OPERATOR(OP) \
    QVariant operator OP (const QVariant &var1, const QVariant &var2)\
    {\
        switch(var1.type()) {\
        case QVariant::Int:\
            return var1.toInt() OP var2;\
        case QVariant::Double:\
            return var1.toDouble() OP var2;\
        case QVariant::ByteArray:\
            return var1 OP var2;\
        case QVariant::Bool:\
            return var1 OP var2;\
        default: break;\
        }\
        return QVariant::Invalid;\
    }

#define OPERATOR_ASS(OP) \
    QVariant &operator OP##=(QVariant &var1, const QVariant &var2)\
    {\
        return var1 = var1 OP var2;\
    }

OPERATOR(+)
OPERATOR(-)
OPERATOR(*)
OPERATOR(/)
OPERATOR(&&)
OPERATOR(||)
OPERATOR(&)
OPERATOR(|)
OPERATOR(^)

OPERATOR_ASS(+)
OPERATOR_ASS(-)
OPERATOR_ASS(*)
OPERATOR_ASS(/)
OPERATOR_ASS(&)
OPERATOR_ASS(|)
OPERATOR_ASS(^)

QVariant &operator ++(QVariant &var, int)
{
    return var = 1 + var;
}

QVariant &operator --(QVariant &var, int)
{
    return var = 1 - var;
}

QVariant &operator ++(QVariant &var)
{
    return var = 1 + var;
}

QVariant &operator --(QVariant &var)
{
    return var = 1 - var;
}

QVariant operator !(const QVariant &var)
{
    switch(var.type()) {
    case QVariant::Int:
        return !var.toInt();
    case QVariant::Double:
        return !var.toDouble();
    case QVariant::Bool:
        return !var.toBool();
    default: break;
    }

    return QVariant::Invalid;
}

struct TreeNode
{
    QVariant value;
    QByteArray name;
};

#endif // GLOBAL_H
