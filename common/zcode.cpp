#include "zcode.h"
#include "zobject.h"

#include <QDebug>
#include <QStack>

Z_BEGIN_NAMESPACE

QString ZCode::actionName(quint8 action)
{
    switch(action) {
        case LeftAssign:        return "=(left)";
        case RightAssign:       return "=(right)";
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
        case LAndAssign:        return "&&=";
        case LOrAssign:         return "||=";
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
        case Unknow:            return "unknow";
    }

    return "";
}

void ZCode::registerIdentifier(const QByteArray &name, ZVariant *variant)
{
    globalIdentifierHash[name] = variant;
}

QStack<ZVariant*> ZCode::virtualStack;
ZVariant ZCode::virtualRegister;
QList<ZCode*> ZCode::codeList;
QHash<QByteArray, ZVariant*> ZCode::globalIdentifierHash;

int ZCode::exec(const QList<ZCode *> &codeList)
{
    QList<ZVariant> temporaryList;

    for(ZCode *code : codeList) {
        zDebug << *code;

        switch(code->action) {
        case LeftAssign: {
            ZVariant &right_val = *virtualStack.pop();

            *virtualStack.top() = right_val;
            break;
        }
        case RightAssign: {
            ZVariant &left_val = *virtualStack.pop();
            ZVariant &right_val = *virtualStack.pop();

            left_val = right_val;
            virtualStack.push(&left_val);
            break;
        }
        case Add:
            temporaryList << *virtualStack.pop() + *virtualStack.pop();
            virtualStack.push(&temporaryList.last());
            break;
        case Sub:
            temporaryList << *virtualStack.pop() - *virtualStack.pop();
            virtualStack.push(&temporaryList.last());
            break;
        case Mul:
            temporaryList << *virtualStack.pop() * *virtualStack.pop();
            virtualStack.push(&temporaryList.last());
            break;
        case Div:
            temporaryList << *virtualStack.pop() / *virtualStack.pop();
            virtualStack.push(&temporaryList.last());
            break;
        case Abs:
            temporaryList << + *virtualStack.pop();
            virtualStack.push(&temporaryList.last());
            break;
        case Minus:
            temporaryList << - *virtualStack.pop();
            virtualStack.push(&temporaryList.last());
            break;
        case And:
            temporaryList << *virtualStack.pop() & *virtualStack.pop();
            virtualStack.push(&temporaryList.last());
            break;
        case Or:
            temporaryList << *virtualStack.pop() | *virtualStack.pop();
            virtualStack.push(&temporaryList.last());
            break;
        case Xor:
            temporaryList << *virtualStack.pop() ^ *virtualStack.pop();
            virtualStack.push(&temporaryList.last());
            break;
        case Contrary:
            temporaryList << ~ *virtualStack.pop();
            virtualStack.push(&temporaryList.last());
            break;
        case Mod:
            temporaryList << *virtualStack.pop() % *virtualStack.pop();
            virtualStack.push(&temporaryList.last());
            break;
        case Not:
            temporaryList << ! *virtualStack.pop();
            virtualStack.push(&temporaryList.last());
            break;
        case AddAssign: {
            ZVariant &right_val = *virtualStack.pop();

            *virtualStack.top() += right_val;
            break;
        }
        case SubAssign: {
            ZVariant &right_val = *virtualStack.pop();

            *virtualStack.top() -= right_val;
            break;
        }
        case MulAssign: {
            ZVariant &right_val = *virtualStack.pop();

            *virtualStack.top() *= right_val;
            break;
        }
        case DivAssign: {
            ZVariant &right_val = *virtualStack.pop();

            *virtualStack.top() /= right_val;
            break;
        }
        case AndAssign: {         // "&=";
            ZVariant &right_val = *virtualStack.pop();

            *virtualStack.top() &= right_val;
            break;
        }
        case OrAssign: {          // "|=";
            ZVariant &right_val = *virtualStack.pop();

            *virtualStack.top() |= right_val;
            break;
        }
        case XorAssign: {         // "^=";
            ZVariant &right_val = *virtualStack.pop();

            *virtualStack.top() ^= right_val;
            break;
        }
        case ModAssign: {         // "%=";
            ZVariant &right_val = *virtualStack.pop();

            *virtualStack.top() %= right_val;
            break;
        }
        case Less:
            temporaryList << (*virtualStack.pop() < *virtualStack.pop());
            virtualStack.push(&temporaryList.last());
            break;
        case Greater:
            temporaryList << (*virtualStack.pop() > *virtualStack.pop());
            virtualStack.push(&temporaryList.last());
            break;
        case New:
            /// TODO
            break;
        case Delete:
            /// TODO
            break;
        case Throw:
            /// TODO
            break;
        case EQ:
            temporaryList << (*virtualStack.pop() == *virtualStack.pop());
            virtualStack.push(&temporaryList.last());
            break;
        case STEQ: {
            const ZVariant &v1 = *virtualStack.pop();
            const ZVariant &v2 = *virtualStack.pop();

            temporaryList << (v1.type() == v2.type() && v1 == v2);

            zDebug << temporaryList.last();

            virtualStack.push(&temporaryList.last());
            break;
        }
        case NEQ:
            temporaryList << (*virtualStack.pop() != *virtualStack.pop());
            virtualStack.push(&temporaryList.last());
            break;
        case STNEQ: {
            const ZVariant &v1 = *virtualStack.pop();
            const ZVariant &v2 = *virtualStack.pop();

            temporaryList << (v1.type() != v2.type() || v1 != v2);
            virtualStack.push(&temporaryList.last());
            break;
        }
        case LE:
            temporaryList << (*virtualStack.pop() <= *virtualStack.pop());
            virtualStack.push(&temporaryList.last());
            break;
        case GE:
            temporaryList << (*virtualStack.pop() >= *virtualStack.pop());
            virtualStack.push(&temporaryList.last());
            break;
        case LAnd:
            temporaryList << (*virtualStack.pop() && *virtualStack.pop());
            virtualStack.push(&temporaryList.last());
            break;
        case LOr:
            temporaryList << (*virtualStack.pop() || *virtualStack.pop());
            virtualStack.push(&temporaryList.last());
            break;
        case LAndAssign: {        // "&&=";
            ZVariant &right_val = *virtualStack.pop();
            ZVariant &left_val = *virtualStack.top();

            left_val = left_val && right_val;
            break;
        }
        case LOrAssign: {         // "||=";
            ZVariant &right_val = *virtualStack.pop();
            ZVariant &left_val = *virtualStack.top();

            left_val = left_val || right_val;
            break;
        }
        case PrefixAddSelf: {     // "++(prefix)";
            ZVariant &left_val = *virtualStack.top();

            left_val = 1 + left_val;
            break;
        }
        case PostfixAddSelf: {   // "++(postfix)";
            ZVariant &left_val = *virtualStack.pop();
            temporaryList << left_val;
            virtualStack.push(&temporaryList.last());
            left_val = 1 + left_val;
            break;
        }
        case PrefixSubSelf: {     // "--(prefix)";
            ZVariant &left_val = *virtualStack.top();

            left_val = -1 + left_val;
            break;
        }
        case PostfixSubSelf: {   // "--(postfix)";
            ZVariant &left_val = *virtualStack.pop();
            temporaryList << left_val;
            virtualStack.push(&temporaryList.last());
            left_val = -1 + left_val;
            break;
        }
        case Get: {
            ZVariant &right_val = *virtualStack.pop();
            ZVariant &left_val = *virtualStack.pop();
            ZObject *obj = left_val.toObject();

            temporaryList << obj->property(right_val.toString().toLatin1().constData());
            virtualStack.push(&temporaryList.last());
            break;
        }
        case Call: {
            QList<ZVariant> args;

            int argsCount = virtualStack.pop()->toInt();

            args.reserve(argsCount);

            for(int i = 0; i < argsCount; ++i) {
                args.insert(0, *virtualStack.pop());
            }

            ZFunction *fun = qobject_cast<ZFunction*>(virtualStack.pop()->toObject());

            if(fun) {
                fun->call(args);
            }

            break;
            /// TODO
        }
        case Push: {
            ValueCode *valueCode = static_cast<ValueCode*>(code);
            virtualStack.push(valueCode->value);
            break;
        }
        case Pop: {
            temporaryList.removeOne(*virtualStack.pop());
            break;
        }
        case PopAll: {
            virtualStack.clear();
            temporaryList.clear();
            break;
        }
        default: break;
        }

        if(ENABLE_DEBUG) {
            qDebug().noquote() << "------------stack-start--------------";

            for(int i = 0; i < virtualStack.count(); ++i)
                qDebug().noquote() << *virtualStack.value(i);

            qDebug().noquote() << "------------stack-end--------------";
        }
    }

    return 0;
}

QT_BEGIN_NAMESPACE
QDebug operator<<(QDebug deg, const ZCode &var)
{
    QString actionName = ZCode::actionName(var.action);

    deg << actionName.sprintf("%-10s", actionName.toLatin1().constData());

    if(var.action == ZCode::Push) {
        deg << *static_cast<const ValueCode*>(&var)->value;
    }

    return deg;
}
QT_END_NAMESPACE

Z_END_NAMESPACE
