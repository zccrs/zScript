#include "global.h"

#include <QFile>
#include <QVariant>
#include <QMetaMethod>
#include <QMetaType>
#include <QStack>

#include <iostream>

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
        if(QString(val.typeName()) == "Global::ZObject*") {
            data->type = toObject() ? Object : Null;
        } else if(QString(val.typeName()) == "Global::ZVariant") {
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
        deg.nospace() << QByteArray::number(qlonglong(var.toObject()));
        break;
    case ZVariant::List:
        deg.nospace() << var.toList();
        break;
    case ZVariant::NaN:
    case ZVariant::Undefined:
        deg.nospace() << var.typeName();
        break;
    default:
        deg.nospace() << var.toString();
        break;
    }

    deg.nospace() << ")";

    return deg;
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

/// ZObject
ZObject::ZObject(ZObject *parent)
    : QObject(parent)
{
    /// call later

    QMetaObject::invokeMethod(this, "initFunctionProperty", Qt::QueuedConnection);
}

ZVariant ZObject::property(const char *name) const
{
    return ZVariant(QObject::property(name));
}

void ZObject::setProperty(const char *name, const ZVariant &value)
{
    QObject::setProperty(name, value.toQVariant());
}

void ZObject::addFunctionProperty(const char *name)
{
    setProperty(name, new ZFunction(this, name, this));
}

void ZObject::initFunctionProperty()
{
    const QMetaObject *meta = this->metaObject();

    int methodOffse = meta->methodOffset();
    int methodCount = meta->methodCount();

    for(int i = methodOffse; i < methodOffse + methodCount; ++i) {
        const QMetaMethod &method = meta->method(i);

        if(QByteArray(method.name()) == "call")
            continue;

        if(QByteArray(QMetaType::typeName(method.returnType())) == "QList<Global::ZVariant>"
                && method.parameterCount() == 1
                && method.parameterTypes().first() == "QList<ZVariant>") {
            addFunctionProperty(method.name());
        }
    }
}

ZFunction::ZFunction(ZObject *target, const char *name, ZObject *parent)
    : ZObject(parent)
    , m_target(target)
    , m_methodName(name)
{

}

QList<ZVariant> ZFunction::call(const QList<ZVariant> &args) const
{
    QList<ZVariant> retVal;

    QMetaObject::invokeMethod(m_target, m_methodName.constData(),
//                                          Q_RETURN_ARG(QList<Global::ZVariant>, retVal),
                              Q_ARG(const QList<ZVariant>, args));

    return retVal;
}

Node::Node(OperatorType t, Node *, Node *)
    :/*left(l), right(r), */nodeType(t)
{

}

Node::~Node()
{
//    if(left)
//        delete left;

//    if(right)
//        delete right;

//    if(value)
//        delete value;
}

void Node::recursion()
{
//    if(left)
//        left->codeEnv = codeEnv;

//    if(right)
//        right->codeEnv = codeEnv;

//    switch(nodeType) {
//    case Assign:
//        left->recursion();

//        if(left->value)
//            *left->value = right->recursionAndGetValue();
//        else
//            zError << "Undefined reference";
//        break;
//    case Add:
//        *value = left->recursionAndGetValue() + right->recursionAndGetValue();
//        break;
//    case Sub:
//        *value = left->recursionAndGetValue() - right->recursionAndGetValue();
//        break;
//    case Mul:
//        *value = left->recursionAndGetValue() * right->recursionAndGetValue();
//        break;
//    case Div:
//        *value = left->recursionAndGetValue() / right->recursionAndGetValue();
//        break;
//    case Abs:
//        *value = +right->recursionAndGetValue();
//        break;
//    case Minus:
//        *value = -right->recursionAndGetValue();
//        break;
//    case And:
//        *value = left->recursionAndGetValue() & right->recursionAndGetValue();
//        break;
//    case Or:
//        *value = left->recursionAndGetValue() | right->recursionAndGetValue();
//        break;
//    case Xor:
//        *value = left->recursionAndGetValue() ^ right->recursionAndGetValue();
//        break;
//    case Contrary:
//        *value = ~left->recursionAndGetValue();
//        break;
//    case Mod:
//        *value = left->recursionAndGetValue() % right->recursionAndGetValue();
//        break;
//    case Not:
//        *value = !left->recursionAndGetValue();
//        break;
//    case Less:
//        *value = left->recursionAndGetValue() < right->recursionAndGetValue();
//        break;
//    case Greater:
//        *value = left->recursionAndGetValue() > right->recursionAndGetValue();
//        break;
//    case New:
//        /// TODO
//        break;
//    case Delete:
//        /// TODO
//        break;
//    case Throw:
//        /// TODO
//        break;
//    case EQ:
//        *value = left->recursionAndGetValue() == right->recursionAndGetValue();
//        break;
//    case STEQ: {
//        const ZVariant &v1 = left->recursionAndGetValue();
//        const ZVariant &v2 = right->recursionAndGetValue();

//        *value = v1.type() == v2.type() && v1 == v2;
//        break;
//    }
//    case NEQ:
//        *value = left->recursionAndGetValue() != right->recursionAndGetValue();
//        break;
//    case STNEQ: {
//        const ZVariant &v1 = left->recursionAndGetValue();
//        const ZVariant &v2 = right->recursionAndGetValue();

//        *value = v1.type() != v2.type() || v1 != v2;
//        break;
//    }
//    case LE:
//        *value = left->recursionAndGetValue() <= right->recursionAndGetValue();
//        break;
//    case GE:
//        *value = left->recursionAndGetValue() >= right->recursionAndGetValue();
//        break;
//    case LAnd:
//        *value = left->recursionAndGetValue() && right->recursionAndGetValue();
//        break;
//    case LOr:
//        *value = left->recursionAndGetValue() || right->recursionAndGetValue();
//        break;
//    case Get: {
//        ZObject *obj = left->recursionAndGetValue().toObject();

//        *value = obj->property(right->value->toString().toLatin1().constData());
//        break;
//    }
//    case Comma: {
//        const ZVariant &left_value = left->recursionAndGetValue();

//        if(left_value.type() == ZVariant::List) {
//            *value = ZVariant(left_value.toList() << right->recursionAndGetValue());
//        } else {
//            *value = QList<ZVariant>() << left_value << right->recursionAndGetValue();
//        }
//        break;
//    }
//    case Call: {
//        const ZFunction *fun = qobject_cast<ZFunction*>(left->recursionAndGetValue().toObject());

//        if(fun) {
//            fun->call(right->recursionAndGetValue().toList());
//        }
//        break;
//    }
//    case Variant: {
//        value = codeEnv->variantValue(name);
//        break;
//    }
//    default: break;
//    }
}

ZVariant CodeData::variantValue(const QByteArray &name) const
{
    const CodeData *code = this;

    do {
        if(identifiersHash.contains(name))
            return identifiersHash.value(name);

        code = code->parent.constData();
    } while(code);

    return ZVariant();
}

Code::Code(Code *p)
    : data(new CodeData)
{
    if(p)
        data->parent = p->data.constData()->parent;
}

void Code::exec() const
{
    for(Node *node : nodeList) {
//        node->codeEnv = const_cast<Code*>(this);
        node->recursion();
    }
}

ZConsole::ZConsole(ZObject *parent)
    : ZObject(parent)
{
    qRegisterMetaType<QList<ZVariant>>("QList<ZVariant>");
}

QList<ZVariant> ZConsole::log(const QList<ZVariant> &args) const
{
    QList<ZVariant> list;

    if(args.isEmpty())
        return list;

    for(int i = 0; i < args.count() - 1; ++i)
        zStandardPrint << args.at(i).toString().toStdString() << " ";

    zStandardPrint << args.last().toString().toStdString() << std::endl;

    return list;
}

QString ZCode::actionName(const ZCode::Action &action)
{
    switch(action) {
        case Assign:            return "=";
        case Add:               return "+";
        case Sub:               return "-";
        case Mul:               return "*";
        case Div:               return "/";
        case Abs:               return "abs";
        case Minus:             return "minus";
        case And:               return "&";
        case Or:                return "|";
        case Xor:               return "^";
        case Contrary:          return "~";
        case Mod:               return "%";
        case Not:               return "!";
        case AddAssign:         return "+=";
        case SubAssign:         return "-=";
        case MulAssign:         return "*=";
        case DivAssign:         return "/=";
        case AndAssign:         return "&=";
        case OrAssign:          return "|=";
        case XorAssign:         return "^=";
        case ContraryAssign:    return "~=";
        case ModAssign:         return "%=";
        case NotAssign:         return "!=";
        case Less:              return "<";
        case Greater:           return ">";
        case New:               return "new";
        case Delete:            return "delete";
        case Throw:             return "throw";
        case EQ:                return "==";
        case STEQ:              return "===";
        case NEQ:               return "!=";
        case STNEQ:             return "!==";
        case LE:                return "<=";
        case GE:                return ">=";
        case LAnd:              return "&&";
        case LOr:               return "||";
        case LAndAssign:        return "||=";
        case LOrAssign:         return "&&=";
        case PrefixAddSelf:     return "++(prefix)";
        case PostfixAddSelf:    return "++(postfix)";
        case PrefixSubSelf:     return "--(prefix)";
        case PostfixSubSelf:    return "--(postfix)";
        case Get:               return ".";
        case Comma:             return ",";
        case Call:              return "call";
        case Push:              return "push";
        case Pop:               return "pop";
        case PopAll:            return "pop all";
        case Variant:           return "variant";
        case Constant:          return "constant";
        case Unknow:            return "unknow";
    }

    return "";
}

QStack<ZVariant*> virtualStack;
ZVariant virtualRegister;
QList<ZCode*> codeList;

QDebug operator<<(QDebug deg, const ZCode &var)
{
    QString actionName = ZCode::actionName(var.action);

    deg << actionName.sprintf("%-10s", actionName.toLatin1().constData());

    if(var.target)
        deg << *var.target;
    else
        deg << var.target;

    return deg;
}

}/// namespace Global end
