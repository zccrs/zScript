#include "zcode.h"
#include "zobject.h"

#include "zScript.tab.hpp"
#include "FlexLexer.h"

#include <QDebug>
#include <QStack>
#include <QTemporaryFile>
#include <QCoreApplication>

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
        case JoinToTuple:       return "join to tuple";
        case JoinToList:        return "join to list";
        case Call:              return "call";
        case Push:              return "push";
        case Pop:               return "pop";
        case PopAll:            return "pop all";
        case Goto:              return "goto";
        case If:                return "if";
        case Children:          return "[](get children)";
        case Append:            return "<<(append)";
        case Unknow:            return "unknow";
    }

    return "";
}

ZVariant ZCode::exec(const QList<ZCode *> &codeList)
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
            ZVariant &left_val = *virtualStack.top();

            left_val.depthCopyAssign(left_val + right_val);
            break;
        }
        case SubAssign: {
            ZVariant &right_val = *virtualStack.pop();
            ZVariant &left_val = *virtualStack.top();

            left_val.depthCopyAssign(left_val - right_val);
            break;
        }
        case MulAssign: {
            ZVariant &right_val = *virtualStack.pop();
            ZVariant &left_val = *virtualStack.top();

            left_val.depthCopyAssign(left_val * right_val);
            break;
        }
        case DivAssign: {
            ZVariant &right_val = *virtualStack.pop();
            ZVariant &left_val = *virtualStack.top();

            left_val.depthCopyAssign(left_val / right_val);
            break;
        }
        case AndAssign: {         // "&=";
            ZVariant &right_val = *virtualStack.pop();
            ZVariant &left_val = *virtualStack.top();

            left_val.depthCopyAssign(left_val & right_val);
            break;
        }
        case OrAssign: {          // "|=";
            ZVariant &right_val = *virtualStack.pop();
            ZVariant &left_val = *virtualStack.top();

            left_val.depthCopyAssign(left_val | right_val);
            break;
        }
        case XorAssign: {         // "^=";
            ZVariant &right_val = *virtualStack.pop();
            ZVariant &left_val = *virtualStack.top();

            left_val.depthCopyAssign(left_val ^ right_val);
            break;
        }
        case ModAssign: {         // "%=";
            ZVariant &right_val = *virtualStack.pop();
            ZVariant &left_val = *virtualStack.top();

            left_val.depthCopyAssign(left_val % right_val);
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

            left_val.depthCopyAssign(left_val && right_val);
            break;
        }
        case LOrAssign: {         // "||=";
            ZVariant &right_val = *virtualStack.pop();
            ZVariant &left_val = *virtualStack.top();

            left_val.depthCopyAssign(left_val || right_val);
            break;
        }
        case PrefixAddSelf: {     // "++(prefix)";
            ZVariant &left_val = *virtualStack.top();

            left_val.depthCopyAssign(1 + left_val);
            break;
        }
        case PostfixAddSelf: {   // "++(postfix)";
            ZVariant &left_val = *virtualStack.pop();
            temporaryList << left_val;
            virtualStack.push(&temporaryList.last());
            left_val.depthCopyAssign(1 + left_val);
            break;
        }
        case PrefixSubSelf: {     // "--(prefix)";
            ZVariant &left_val = *virtualStack.top();

            left_val.depthCopyAssign(-1 + left_val);
            break;
        }
        case PostfixSubSelf: {   // "--(postfix)";
            ZVariant &left_val = *virtualStack.pop();
            temporaryList << left_val;
            virtualStack.push(&temporaryList.last());
            left_val.depthCopyAssign(-1 + left_val);
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
        case JoinToTuple: {     /// join to ZTuple
            ZVariant::ZTuple tuple;

            int argsCount = virtualStack.pop()->toInt();

            tuple.reserve(argsCount);

            for(int i = 0; i< argsCount; ++i) {
                tuple.insert(0, virtualStack.pop());
            }

            temporaryList << std::move(tuple);

            virtualStack.push(&temporaryList.last());
            break;
        }
        case JoinToList: {     /// join to Variant List
            QList<ZVariant> list;

            int argsCount = virtualStack.pop()->toInt();

            list.reserve(argsCount);

            for(int i = 0; i< argsCount; ++i) {
                list.insert(0, ZVariant::copy(*virtualStack.pop()));
            }

            temporaryList << ZVariant(list);

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

            ZFunction *fun = virtualStack.pop()->toFunction();

            if(fun) {
                temporaryList << fun->call(args);
                virtualStack.push(&temporaryList.last());
            }

            break;
            /// TODO
        }
        case Push: {
            ValueCode *valueCode = code->toValueCode();
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
            i = code->toValueCode()->value->toInt() - 1;
            break;
        }
        case If: {
            if(!virtualStack.pop()->toBool())
                i = code->toValueCode()->value->toInt() - 1;

            break;
        }
        case Children: {
            const ZVariant &value = *virtualStack.pop();
            const ZVariant &target = *virtualStack.pop();

            temporaryList << target[value];
            virtualStack.push(&temporaryList.last());
            break;
        }
        case Append:{
            const ZVariant &value = *virtualStack.pop();
            ZVariant &target = *virtualStack.top();

            target << value;
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

    if(!virtualStack.isEmpty())
        return *virtualStack.pop();

    return ZCodeExecuter::constUndefined;
}

class ZUserFunction : public ZFunction
{
public:
    explicit ZUserFunction(ZCodeExecuter *e, ZObject *parent = 0)
        : ZFunction(parent), executer(e){}

    ZVariant call(const QList<ZVariant> &args) const Q_DECL_OVERRIDE
    {
        int min_count = qMin(args.count(), executer->parameterList.count());
        int i = 0;

        for(; i < min_count; ++i) {
            *executer->parameterList.at(i) = args.at(i);
        }

        for(; i < executer->parameterList.count(); ++i) {
            *executer->parameterList.at(i) = ZCodeExecuter::constUndefined;
        }

        /// sava current runtime stack
        QStack<ZVariant*> stack = ZCode::virtualStack;

        ZVariant retVal = ZCode::exec(executer->codeList);

        ZCode::virtualStack = stack;

        return retVal;
    }

private:
    ZCodeExecuter *executer;
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
    deleteAllCodeBlock();
    deleteAllCode();
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

    deleteAllCodeBlock();
    gotoLabelMap.clear();

    bool ok;
    int result = exec().toInt(&ok);

    if(!ok)
        return 0;

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

ZSharedVariantPointer ZCodeExecuter::getIdentifier(const QByteArray &name)
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

ZSharedVariantPointer ZCodeExecuter::createFunction(ZCodeExecuter *executer)
{
    return ZSharedVariantPointer(new ZSharedVariant(ZVariant(new ZUserFunction(executer))));
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
    CodeBlock *block;

    if(type == CodeBlock::NormalFor || type == CodeBlock::While) {
        block = new LoopStruceureCodeBlock;
    } else {
        block = new CodeBlock;
    }

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
                zErrorQuit;
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

    executer->deleteAllCodeBlock();
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
        deg << *var.toValueCode()->value.constData();
    } else if(var.action == ZCode::Goto) {
        deg << var.toValueCode()->value->toInt();
    } else if(var.action == ZCode::If) {
        deg << "if false goto:" << var.toValueCode()->value->toInt();
    }

    return deg;
}
QT_END_NAMESPACE

//#include "zcode.moc"
