#include "zcode.h"
#include "zobject.h"

#include "zScript.tab.hpp"
#include "FlexLexer.h"

#include <QDebug>
#include <QStack>
#include <QTemporaryFile>

#include <unistd.h>

Z_BEGIN_NAMESPACE

QStack<ZSharedVariant*> ZCode::virtualStack;

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
        case Join:              return ",";
        case Call:              return "call";
        case Push:              return "push";
        case Pop:               return "pop";
        case PopAll:            return "pop all";
        case Goto:              return "goto";
        case If:                return "if";
        case Unknow:            return "unknow";
    }

    return "";
}

int ZCode::exec(const QList<ZCode *> &codeList)
{
    QList<ZSharedVariant> temporaryList;

    temporaryList.reserve(10);

    for(int i = 0; i < codeList.count(); ++i) {
        ZCode *code = codeList.value(i);

        zDebug << i <<*code;

        switch(code->action) {
        case LeftAssign: {
            ZSharedVariant &right_val = *virtualStack.pop();

            *virtualStack.top() = right_val;
            break;
        }
        case RightAssign: {
            ZSharedVariant &left_val = *virtualStack.pop();
            ZSharedVariant &right_val = *virtualStack.pop();

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
            temporaryList << ZVariant(*virtualStack.pop() & *virtualStack.pop());
            virtualStack.push(&temporaryList.last());
            break;
        case Or:
            temporaryList << ZVariant(*virtualStack.pop() | *virtualStack.pop());
            virtualStack.push(&temporaryList.last());
            break;
        case Xor:
            temporaryList << ZVariant(*virtualStack.pop() ^ *virtualStack.pop());
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
            temporaryList << ZSharedVariant(! *virtualStack.pop());
            virtualStack.push(&temporaryList.last());
            break;
        case AddAssign: {
            ZSharedVariant &right_val = *virtualStack.pop();

            *virtualStack.top() += right_val;
            break;
        }
        case SubAssign: {
            ZSharedVariant &right_val = *virtualStack.pop();

            *virtualStack.top() -= right_val;
            break;
        }
        case MulAssign: {
            ZSharedVariant &right_val = *virtualStack.pop();

            *virtualStack.top() *= right_val;
            break;
        }
        case DivAssign: {
            ZSharedVariant &right_val = *virtualStack.pop();

            *virtualStack.top() /= right_val;
            break;
        }
        case AndAssign: {         // "&=";
            ZSharedVariant &right_val = *virtualStack.pop();

            *virtualStack.top() &= right_val;
            break;
        }
        case OrAssign: {          // "|=";
            ZSharedVariant &right_val = *virtualStack.pop();

            *virtualStack.top() |= right_val;
            break;
        }
        case XorAssign: {         // "^=";
            ZSharedVariant &right_val = *virtualStack.pop();

            *virtualStack.top() ^= right_val;
            break;
        }
        case ModAssign: {         // "%=";
            ZSharedVariant &right_val = *virtualStack.pop();

            *virtualStack.top() %= right_val;
            break;
        }
        case Less:
            temporaryList << ZSharedVariant(*virtualStack.pop() < *virtualStack.pop());
            virtualStack.push(&temporaryList.last());
            break;
        case Greater:
            temporaryList << ZSharedVariant(*virtualStack.pop() > *virtualStack.pop());
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
            temporaryList << ZSharedVariant(*virtualStack.pop() == *virtualStack.pop());
            virtualStack.push(&temporaryList.last());
            break;
        case STEQ: {
            const ZSharedVariant &v1 = *virtualStack.pop();
            const ZSharedVariant &v2 = *virtualStack.pop();

            temporaryList << ZSharedVariant(v1.type() == v2.type() && v1 == v2);

            virtualStack.push(&temporaryList.last());
            break;
        }
        case NEQ:
            temporaryList << ZSharedVariant(*virtualStack.pop() != *virtualStack.pop());
            virtualStack.push(&temporaryList.last());
            break;
        case STNEQ: {
            const ZSharedVariant &v1 = *virtualStack.pop();
            const ZSharedVariant &v2 = *virtualStack.pop();

            temporaryList << ZSharedVariant(v1.type() != v2.type() || v1 != v2);
            virtualStack.push(&temporaryList.last());
            break;
        }
        case LE:
            temporaryList << ZSharedVariant(*virtualStack.pop() <= *virtualStack.pop());
            virtualStack.push(&temporaryList.last());
            break;
        case GE:
            temporaryList << ZSharedVariant(*virtualStack.pop() >= *virtualStack.pop());
            virtualStack.push(&temporaryList.last());
            break;
        case LAnd:
            temporaryList << ZSharedVariant(*virtualStack.pop() && *virtualStack.pop());
            virtualStack.push(&temporaryList.last());
            break;
        case LOr:
            temporaryList << ZSharedVariant(*virtualStack.pop() || *virtualStack.pop());
            virtualStack.push(&temporaryList.last());
            break;
        case LAndAssign: {        // "&&=";
            ZSharedVariant &right_val = *virtualStack.pop();
            ZSharedVariant &left_val = *virtualStack.top();

            left_val = left_val && right_val;
            break;
        }
        case LOrAssign: {         // "||=";
            ZSharedVariant &right_val = *virtualStack.pop();
            ZSharedVariant &left_val = *virtualStack.top();

            left_val = left_val || right_val;
            break;
        }
        case PrefixAddSelf: {     // "++(prefix)";
            ZSharedVariant &left_val = *virtualStack.top();

            left_val = 1 + left_val;
            break;
        }
        case PostfixAddSelf: {   // "++(postfix)";
            ZSharedVariant &left_val = *virtualStack.pop();
            temporaryList << left_val;
            virtualStack.push(&temporaryList.last());
            left_val = 1 + left_val;
            break;
        }
        case PrefixSubSelf: {     // "--(prefix)";
            ZSharedVariant &left_val = *virtualStack.top();

            left_val = -1 + left_val;
            break;
        }
        case PostfixSubSelf: {   // "--(postfix)";
            ZSharedVariant &left_val = *virtualStack.pop();
            temporaryList << left_val;
            virtualStack.push(&temporaryList.last());
            left_val = -1 + left_val;
            break;
        }
        case Get: {
            ZSharedVariant &right_val = *virtualStack.pop();
            ZSharedVariant &left_val = *virtualStack.pop();
            ZObject *obj = left_val.toObject();

            temporaryList << obj->property(right_val.toString().toLatin1().constData());

            if(!temporaryList.last().toQVariant().isValid()) {
                zError << "no such property exists: " << right_val.toString();
            }

            virtualStack.push(&temporaryList.last());
            break;
        }
        case Join: {     /// join to ZGroup
            ZVariant::ZTuple group;

            int argsCount = virtualStack.pop()->toInt();

            group.reserve(argsCount);

            for(int i = 0; i< argsCount; ++i) {
                group.insert(0, virtualStack.pop());
            }

            temporaryList << ZSharedVariant(group);

            virtualStack.push(&temporaryList.last());
            break;
        }
        case Call: {
            QList<ZVariant> args;

            int argsCount = virtualStack.pop()->toInt();

            args.reserve(argsCount);

            for(int i = 0; i < argsCount; ++i) {
                const ZVariant *val = virtualStack.pop();

                if(val->type() == ZVariant::Tuple) {
                    args = val->toList() + args;
                } else {
                    args.insert(0, *val);
                }
            }

            ZFunction *fun = qobject_cast<ZFunction*>(virtualStack.pop()->toObject());

            if(fun) {
                const QList<ZVariant> &list = fun->call(args);
                ZVariant::ZTuple group;

                for(const ZVariant &val : list) {
                    temporaryList << val;
                    group << &temporaryList.last();
                }

                temporaryList << ZSharedVariant(group);

                virtualStack.push(&temporaryList.last());
            }

            break;
            /// TODO
        }
        case Push: {
            ValueCode *valueCode = static_cast<ValueCode*>(code);
            virtualStack.push(valueCode->value->data());
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
        case Goto: {
            i = static_cast<ValueCode*>(code)->value->data()->toInt() - 1;
            break;
        }
        case If: {
            if(!virtualStack.pop()->toBool())
                i = static_cast<ValueCode*>(code)->value->data()->toInt() - 1;

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


ZCodeParse *ZCodeParse::currentCodeParse = Q_NULLPTR;
bool ZCodeParse::yywrap = true;
QHash<const QByteArray, ZSharedVariant*> ZCodeParse::globalIdentifierHash;
QMap<QByteArray, ZSharedVariant*> ZCodeParse::stringConstantMap;
QMap<QByteArray, ZSharedVariant*> ZCodeParse::numberConstantMap;
ZSharedVariant ZCodeParse::constTrue(true);
ZSharedVariant ZCodeParse::constFalse(false);
ZSharedVariant ZCodeParse::constUndefined(ZVariant::Undefined);

ZCodeParse::ZCodeParse()
{
    parent = currentCodeParse;

    currentCodeParse = this;
}

ZCodeParse::~ZCodeParse()
{
    currentCodeParse = Q_NULLPTR;

    qDeleteAll(codeBlockList);
    qDeleteAll(codeList);
    qDeleteAll(gotoLabelMap);

    currentCodeParse = parent;
}

int ZCodeParse::eval()
{
    m_yyFlexLexer = new YYFlexLexer();

    if(parent) {
        m_yyFlexLexer = parent->m_yyFlexLexer;
        m_yyParser = parent->m_yyParser;

        yywrap = false;
    } else {
        m_yyFlexLexer = new YYFlexLexer;
        m_yyParser = new YYParser;

        m_yyParser->set_debug_level(QByteArray(getenv("DEBUG_PARSE_LEVEL")).toInt());
    }

    beginCodeBlock();

    m_yyParser->parse();

    endCodeBlock();

    qDeleteAll(codeBlockList);
    codeBlockList.clear();
    gotoLabelMap.clear();

    int result = exec();

    if(!parent) {
        delete m_yyFlexLexer;
        delete m_yyParser;
    }

    return result;
}

int ZCodeParse::eval(const char *fileName, bool *ok)
{
    FILE *fd = freopen(fileName, "r", stdin);

    if(ok)
        *ok = bool(fd);

    return eval();
}

int ZCodeParse::eval(const QByteArray &code, bool *ok)
{
    QTemporaryFile file;

    if(file.open()) {
        write(file.handle(), code.constData(), code.size());

        return eval(file.fileName().toLatin1().constData(), ok);
    }

    if(ok)
        *ok = false;

    return -1;
}

ZSharedVariantPointer *ZCodeParse::getIdentifierAddress(const QByteArray &name)
{
    ZSharedVariantPointer *val = currentCodeBlock->identifiers.value(name);

    if(val)
        return val;

    val = currentCodeBlock->undefinedIdentifier.value(name);

    if(val)
        return val;

    val = new ZSharedVariantPointer(&constUndefined);

    currentCodeBlock->undefinedIdentifier[name] = val;

    return val;
}

ZSharedVariant *ZCodeParse::getConstantAddress(const QByteArray &value, ZVariant::Type type)
{
    switch(type) {
    case ZVariant::Int: {
        ZSharedVariant *val = numberConstantMap.value(value);

        if(!val) {
            val = new ZSharedVariant(value.toInt());
            numberConstantMap[value] = val;
        }

        return val;
    }
    case ZVariant::Double: {
        ZSharedVariant *val = numberConstantMap.value(value);

        if(!val) {
            val = new ZSharedVariant(value.toDouble());
            numberConstantMap[value] = val;
        }

        return val;
    }
    case ZVariant::String: {
        ZSharedVariant *val = stringConstantMap.value(value);

        if(!val) {
            val = new ZSharedVariant(QString(value));
            stringConstantMap[value] = val;
        }

        return val;
    }
    case ZVariant::Bool:
        if(value == "true")
            return &constTrue;
        else
            return &constFalse;
    default:
        return &constUndefined;
    }
}

ZCode *ZCodeParse::createCode(const ZCode::Action &action, ZSharedVariantPointer *val)
{
    if(val) {
        ValueCode *code = new ValueCode;

        code->action = action;
        code->value = val;

        return code;
    }

    ZCode *code = new ZCode;

    code->action = action;

    return code;
}

void ZCodeParse::beginCodeBlock()
{
    CodeBlock *block = new CodeBlock;

    codeBlockList << block;

    block->parent = currentCodeBlock;

    currentCodeBlock = block;
}

void ZCodeParse::endCodeBlock()
{
    for(ZSharedVariantPointer *val_pointer : currentCodeBlock->undefinedIdentifier) {
        const QByteArray &name = currentCodeBlock->undefinedIdentifier.key(val_pointer);
        CodeBlock *block = currentCodeBlock->parent;
        ZSharedVariantPointer *val;

        while(block) {
            val = block->identifiers.value(name);

            if(val) {
                *val_pointer = val->data();
                break;
            }

            block = block->parent;
        }

        if(!val) {
            ZSharedVariant *val = globalIdentifierHash.value(name);

            if(val) {
                *val_pointer = val;
            } else {
                zError << "undefined reference:" << name;
            }
        }
    }

    currentCodeBlock->undefinedIdentifier.clear();
    currentCodeBlock = currentCodeBlock->parent;
}

Z_END_NAMESPACE

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
