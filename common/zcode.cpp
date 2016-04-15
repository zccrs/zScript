#include "zcode.h"
#include "zobject.h"

#include <QDebug>
#include <QStack>

Z_BEGIN_NAMESPACE

QString ZCode::actionName(quint8 action)
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
    for(ZCode *code : codeList) {
        zDebug << *code;

        switch(code->action) {
        case Assign: {
            ZVariant &right_val = *virtualStack.pop();
            ZVariant &left_val = *virtualStack.pop();

            left_val = right_val;
            virtualStack.push(&left_val);
            break;
        }
        case Add:
            virtualRegister = *virtualStack.pop() + *virtualStack.pop();
            virtualStack.push(&virtualRegister);
            break;
        case Sub:
            virtualRegister = *virtualStack.pop() + *virtualStack.pop();
            virtualStack.push(&virtualRegister);
            break;
        case Mul:
            virtualRegister = *virtualStack.pop() + *virtualStack.pop();
            virtualStack.push(&virtualRegister);
            break;
        case Div:
            virtualRegister = *virtualStack.pop() + *virtualStack.pop();
            virtualStack.push(&virtualRegister);
            break;
        case Abs:
            virtualRegister = + *virtualStack.pop();
            virtualStack.push(&virtualRegister);
            break;
        case Minus:
            virtualRegister = - *virtualStack.pop();
            virtualStack.push(&virtualRegister);
            break;
        case And:
            virtualRegister = *virtualStack.pop() & *virtualStack.pop();
            virtualStack.push(&virtualRegister);
            break;
        case Or:
            virtualRegister = *virtualStack.pop() | *virtualStack.pop();
            virtualStack.push(&virtualRegister);
            break;
        case Xor:
            virtualRegister = *virtualStack.pop() ^ *virtualStack.pop();
            virtualStack.push(&virtualRegister);
            break;
        case Contrary:
            virtualRegister = ~ *virtualStack.pop();
            virtualStack.push(&virtualRegister);
            break;
        case Mod:
            virtualRegister = *virtualStack.pop() % *virtualStack.pop();
            virtualStack.push(&virtualRegister);
            break;
        case Not:
            virtualRegister = ! *virtualStack.pop();
            virtualStack.push(&virtualRegister);
            break;
        case Less:
            virtualRegister = *virtualStack.pop() < *virtualStack.pop();
            virtualStack.push(&virtualRegister);
            break;
        case Greater:
            virtualRegister = *virtualStack.pop() > *virtualStack.pop();
            virtualStack.push(&virtualRegister);
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
            virtualRegister = *virtualStack.pop() == *virtualStack.pop();
            virtualStack.push(&virtualRegister);
            break;
        case STEQ: {
            const ZVariant &v1 = *virtualStack.pop();
            const ZVariant &v2 = *virtualStack.pop();

            virtualRegister = v1.type() == v2.type() && v1 == v2;
            virtualStack.push(&virtualRegister);
            break;
        }
        case NEQ:
            virtualRegister = *virtualStack.pop() != *virtualStack.pop();
            virtualStack.push(&virtualRegister);
            break;
        case STNEQ: {
            const ZVariant &v1 = *virtualStack.pop();
            const ZVariant &v2 = *virtualStack.pop();

            virtualRegister = v1.type() != v2.type() || v1 != v2;
            virtualStack.push(&virtualRegister);
            break;
        }
        case LE:
            virtualRegister = *virtualStack.pop() <= *virtualStack.pop();
            virtualStack.push(&virtualRegister);
            break;
        case GE:
            virtualRegister = *virtualStack.pop() >= *virtualStack.pop();
            virtualStack.push(&virtualRegister);
            break;
        case LAnd:
            virtualRegister = *virtualStack.pop() && *virtualStack.pop();
            virtualStack.push(&virtualRegister);
            break;
        case LOr:
            virtualRegister = *virtualStack.pop() || *virtualStack.pop();
            virtualStack.push(&virtualRegister);
            break;
        case Get: {
            ZVariant &right_val = *virtualStack.pop();
            ZVariant &left_val = *virtualStack.pop();
            ZObject *obj = left_val.toObject();

            virtualRegister = obj->property(right_val.toString().toLatin1().constData());
            virtualStack.push(&virtualRegister);
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
            virtualStack.pop();
            break;
        }
        case PopAll: {
            virtualStack.clear();
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
