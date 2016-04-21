#include "zcode.h"
#include "zobject.h"

#include "zScript.tab.hpp"
#include "FlexLexer.h"

#include <QDebug>
#include <QStack>
#include <QTemporaryFile>

#include <unistd.h>

Z_BEGIN_NAMESPACE

QStack<ZVariant*> ZCode::virtualStack;

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
    QList<ZVariant> temporaryList;

    temporaryList.reserve(10);

    for(int i = 0; i < codeList.count(); ++i) {
        ZCode *code = codeList.value(i);

        zDebug << i <<*code;

        switch(code->action) {
        case LeftAssign: {
            const ZVariant &right_val = *virtualStack.pop();

            virtualStack.top()->depthCopyAssign(right_val);
            break;
        }
        case RightAssign: {
            ZVariant &left_val = *virtualStack.pop();
            const ZVariant &right_val = *virtualStack.pop();

            left_val.depthCopyAssign(right_val);
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

            temporaryList << std::move(group);

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

                temporaryList << group;

                virtualStack.push(&temporaryList.last());
            }

            break;
            /// TODO
        }
        case Push: {
            ValueCode *valueCode = static_cast<ValueCode*>(code);
            virtualStack.push(valueCode->value.data());
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
            i = static_cast<ValueCode*>(code)->value->toInt() - 1;
            break;
        }
        case If: {
            if(!virtualStack.pop()->toBool())
                i = static_cast<ValueCode*>(code)->value->toInt() - 1;

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

class ZUserFunction : public ZFunction
{
public:
    explicit ZUserFunction(const QList<ZCode*> &codes, ZObject *parent = 0)
        : ZFunction(parent), codeList(codes){}

    QList<ZVariant> call(const QList<ZVariant> &args) const Q_DECL_OVERRIDE
    {
        Q_UNUSED(args);

        ZCode::exec(codeList);

        return QList<ZVariant>();
    }

private:
    QList<ZCode*> codeList;
};

ZCodeExecuter *ZCodeExecuter::currentCodeExecuter = Q_NULLPTR;
YYFlexLexer *ZCodeExecuter::yyFlexLexer = Q_NULLPTR;
bool ZCodeExecuter::yywrap = true;
QHash<const QByteArray, ZSharedVariant*> ZCodeExecuter::globalIdentifierHash;
QMap<QByteArray, ZVariant*> ZCodeExecuter::stringConstantMap;
QMap<QByteArray, ZVariant*> ZCodeExecuter::numberConstantMap;
ZVariant ZCodeExecuter::constTrue(true);
ZVariant ZCodeExecuter::constFalse(false);
ZVariant ZCodeExecuter::constUndefined;

ZCodeExecuter::ZCodeExecuter()
{

}

ZCodeExecuter::~ZCodeExecuter()
{
    qDeleteAll(codeBlockList);
    qDeleteAll(codeList);
    qDeleteAll(gotoLabelMap);
}

int ZCodeExecuter::eval()
{
    beginCodeBlock();

    YYFlexLexer *yyFlexLexer = new YYFlexLexer;
    YYParser *yyParser = new YYParser;

    yyParser->set_debug_level(QByteArray(getenv("DEBUG_PARSE_LEVEL")).toInt());

    this->yyFlexLexer = yyFlexLexer;

    yyParser->parse();

    this->yyFlexLexer = Q_NULLPTR;

    delete yyFlexLexer;
    delete yyParser;

    endCodeBlock();

    qDeleteAll(codeBlockList);
    codeBlockList.clear();
    gotoLabelMap.clear();

    int result = exec();

    return result;
}

int ZCodeExecuter::eval(const char *fileName, bool *ok)
{
    FILE *fd = freopen(fileName, "r", stdin);

    if(ok)
        *ok = bool(fd);

    return eval();
}

int ZCodeExecuter::eval(const QByteArray &code, bool *ok)
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

ZSharedVariantPointer ZCodeExecuter::getIdentifierAddress(const QByteArray &name)
{
    ZSharedVariantPointer val = currentCodeBlock->identifiers.value(name);

    if(val)
        return val;

    val = currentCodeBlock->undefinedIdentifier.value(name);

    if(val)
        return val;

    val = new ZSharedVariant();

    currentCodeBlock->undefinedIdentifier[name] = val;

    return val;
}

ZSharedVariant *ZCodeExecuter::createConstant(const QByteArray &value, ZVariant::Type type)
{
    switch(type) {
    case ZVariant::Int: {
        ZVariant *val = numberConstantMap.value(value);

        if(!val) {
            val = new ZVariant(value.toInt());
            numberConstantMap[value] = val;
        }

        return new ZSharedVariant(*val);
    }
    case ZVariant::Double: {
        ZVariant *val = numberConstantMap.value(value);

        if(!val) {
            val = new ZVariant(value.toDouble());
            numberConstantMap[value] = val;
        }

        return new ZSharedVariant(*val);
    }
    case ZVariant::String: {
        ZVariant *val = stringConstantMap.value(value);

        if(!val) {
            val = new ZVariant(QString(value));
            stringConstantMap[value] = val;
        }

        return new ZSharedVariant(*val);
    }
    case ZVariant::Bool:
        if(value == "true")
            return new ZSharedVariant(constTrue);
        else
            return new ZSharedVariant(constFalse);
    default:
        return new ZSharedVariant(constUndefined);
    }
}

ZSharedVariantPointer ZCodeExecuter::createFunction(const ZCodeExecuter *executer)
{
    return ZSharedVariantPointer(new ZSharedVariant(ZVariant(new ZUserFunction(executer->codeList, 0))));
}

ZCode *ZCodeExecuter::createCode(const ZCode::Action &action, const ZSharedVariantPointer &val)
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

void ZCodeExecuter::beginCodeBlock(CodeBlock::Type type)
{
    CodeBlock *block = new CodeBlock;

    codeBlockList << block;

    block->type = type;
    block->beginCodeIndex = codeList.count();
    block->parent = currentCodeBlock;

    currentCodeBlock = block;
}

void ZCodeExecuter::endCodeBlock()
{
    for(ZSharedVariantPointer &val_pointer : currentCodeBlock->undefinedIdentifier) {
        const QByteArray &name = currentCodeBlock->undefinedIdentifier.key(val_pointer);
        CodeBlock *block = currentCodeBlock->parent;

        while(block) {
            ZSharedVariantPointer val = block->identifiers.value(name);

            if(val) {
                *val_pointer.data() = *val.constData();
                break;
            }

            block = block->parent;
        }

        if(!block) {
            ZSharedVariant *val = globalIdentifierHash.value(name);

            if(val) {
                *val_pointer.data() = *val;
            } else {
                zError << "undefined reference:" << name;
            }
        }
    }

    currentCodeBlock->undefinedIdentifier.clear();
    currentCodeBlock = currentCodeBlock->parent;
}

ZCodeExecuter *ZCodeExecuter::beginCodeExecuter()
{
    ZCodeExecuter *executer = new ZCodeExecuter();

    executer->parent = currentCodeExecuter;

    if(currentCodeExecuter) {
        executer->currentCodeBlock = currentCodeExecuter->currentCodeBlock;

        yywrap = false;
    }

    currentCodeExecuter = executer;

    return executer;
}

ZCodeExecuter *ZCodeExecuter::endCodeExecuter()
{
    ZCodeExecuter *executer = currentCodeExecuter;

    if(!executer)
        return executer;

    qDeleteAll(executer->codeBlockList);
    executer->codeBlockList.clear();
    executer->gotoLabelMap.clear();

    currentCodeExecuter = executer->parent;

    return executer;
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

//#include "zcode.moc"
