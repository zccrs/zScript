#ifndef ZCODE_H
#define ZCODE_H

#include "zvariant.h"

#include <QDebug>

class yyFlexLexer;

namespace yy {
class parser;
}

typedef yyFlexLexer YYFlexLexer;
typedef yy::parser  YYParser;
typedef QExplicitlySharedDataPointer<ZSharedVariant> ZSharedVariantPointer;

Z_BEGIN_NAMESPACE

struct ValueCode;
struct ZCode
{
    enum Action
    {
        LeftAssign,         // =                            0
        RightAssign,        // =                            1
        Add,                // +                            2
        Sub,                // -                            3
        Mul,                // *                            4
        Div,                // /                            5
        Abs,                // +                            6
        Minus,              // -                            7
        And,                // &                            8
        Or,                 // |                            9
        Xor,                // ^                            10
        Contrary,           // ~                            10
        Mod,                // %                            12
        Not,                // !                            13
        AddAssign,          // +=                           14
        SubAssign,          // -=                           15
        MulAssign,          // *=                           16
        DivAssign,          // /=                           17
        AndAssign,          // &=                           18
        OrAssign,           // |=                           19
        XorAssign,          // ^=                           20
        ModAssign,          // %=                           21
        NotAssign,          // !=                           22        remove
        Less,               // <                            23
        Greater,            // >                            24
        New,                // new                          25
        Delete,             // delete                       26
        Throw,              // throw                        27
        EQ,                 // ==                           28
        STEQ,               // ===                          29
        NEQ,                // !=                           30
        STNEQ,              // !==                          31
        LE,                 // <=                           32
        GE,                 // >=                           33
        LAnd,               // &&                           34
        LOr,                // ||                           35
        LAndAssign,         // &&=                          36
        LOrAssign,          // ||=                          37
        PrefixAddSelf,      // ++                           38
        PostfixAddSelf,     // ++                           39
        PrefixSubSelf,      // --                           40
        PostfixSubSelf,     // --                           41
        Get,                // .                            42
        JoinToTuple,        // join                         43      join to tuple
        JoinToList,         // join                         44      join to list
        Call,               // ()                           45
        Push,               // push target value to stack   46
        Pop,                // pop stack                    47
        PopAll,             // clear stack                  48
        Goto,               // goto code index              49
        If,                 // if                           50
        Children,           // get children(X[])            51
        Append,             // << add children to last      52
        Switch,             // switch                       53
        Unknow              //                              54
    };

    static QString actionName(quint8 action);

    static ZVariant exec(const QList<ZCode*> &codeList);

    quint8 action = Unknow;

    static QStack<ZVariant*> virtualStack;

    inline bool isValueCode() const
    {return action == Push || action == Goto || action == If;}

    inline const ValueCode *toValueCode() const;
    inline ValueCode *toValueCode();
};

struct ValueCode : public ZCode
{
    ZSharedVariantPointer value;
};

const ValueCode *ZCode::toValueCode() const
{ return static_cast<const ValueCode*>(this);}
ValueCode *ZCode::toValueCode()
{ return static_cast<ValueCode*>(this);}

class ZCodeExecuter
{
public:
    ~ZCodeExecuter();

    struct LoopStructureCodeBlock;
    struct SwitchCodeBlock;
    struct CodeBlock{
        enum Type {
            Normal = 0x01,
            Function = 0x02,
            While = 0x04,
            NormalFor = 0x08,
            LoopStructure = While | NormalFor,
            If = 0x10,
            Switch = 0x20
        };

        /// 代码块第一条指令的index
        int beginCodeIndex;

        Type type = Normal;
        CodeBlock *parent = Q_NULLPTR;

        QMap<QByteArray, ZSharedVariantPointer> identifiers;
        QMap<QByteArray, ZSharedVariantPointer> undefinedIdentifier;

        /// 临时指令列表
        QList<ZCode*> tmpCodeList;

        inline bool isLoopStructure() const
        { return (type | LoopStructure) == LoopStructure;}

        inline const LoopStructureCodeBlock *toLoopStructureCodeBlock() const
        { return static_cast<const LoopStructureCodeBlock*>(this);}
        inline LoopStructureCodeBlock *toLoopStructureCodeBlock()
        { return static_cast<LoopStructureCodeBlock*>(this);}

        inline const SwitchCodeBlock *toSwitchCodeBlock() const
        { return static_cast<const SwitchCodeBlock*>(this);}
        inline SwitchCodeBlock *toSwitchCodeBlock()
        { return static_cast<SwitchCodeBlock*>(this);}
    };

    /// 循环结构的代码块
    struct LoopStructureCodeBlock : public CodeBlock {
        LoopStructureCodeBlock() {
            breakIndex = new ZSharedVariant();
            continueIndex = new ZSharedVariant();
        }

        /// 循环中的if指令的index
        int ifInstructionIndex;
        /// 执行break语句时要goto到的指令的位置
        ZSharedVariantPointer breakIndex;
        /// 执行containue语句时要goto到的指令的位置
        ZSharedVariantPointer continueIndex;
    };

    /// switch结构的代码块
    struct SwitchCodeBlock : public CodeBlock {
        SwitchCodeBlock() {
            breakIndex = new ZSharedVariant();
        }

        /// 执行break语句时要goto到的指令的位置
        ZSharedVariantPointer breakIndex;
    };

    inline static void registerIdentifier(const QByteArray &name, ZSharedVariant *variant)
    {globalIdentifierHash[name] = variant;}

    /// from stdin get code
    int eval(std::istream &s);
    int eval(const char *fileName, bool *ok = 0);
    int eval(const QByteArray &code);

    inline ZVariant exec()
    { return ZCode::exec(codeList);}

    ZSharedVariantPointer getIdentifier(const QByteArray &name);

    static ZSharedVariant *createConstant(const QByteArray &value, ZVariant::Type type);

    static inline ZSharedVariant *createConstantByValue(const ZVariant &value)
    { return createConstant(value.toString().toLatin1(), value.type());}

    inline void     appendCode(const ZCode::Action &action)
    {if(enableTmpCodeList) currentCodeBlock->tmpCodeList << createCode(action, ZSharedVariantPointer());
        else codeList << createCode(action, ZSharedVariantPointer());}

    inline void appendCode(const ZCode::Action &action, ZSharedVariant *val)
    { if(enableTmpCodeList) currentCodeBlock->tmpCodeList << createCode(action, ZSharedVariantPointer(val));
        else codeList << createCode(action, ZSharedVariantPointer(val));}

    inline void appendCode(const ZCode::Action &action, const ZSharedVariantPointer &val)
    { if(enableTmpCodeList) currentCodeBlock->tmpCodeList << createCode(action, val);
        else codeList << createCode(action, val);}

    inline ZSharedVariant *getGotoLabel(const QByteArray &name)
    {
        ZSharedVariant *val = gotoLabelMap.value(name);

        if(!val) {
            val = new ZSharedVariant();

            gotoLabelMap[name] = val;
        }

        return val;
    }

    inline QList<ZCode*> &getCodeList()
    { return codeList;}

    inline QList<ZCode*> &getTmpCodeList()
    { return currentCodeBlock->tmpCodeList;}

    inline ZSharedVariant *addIdentifier(const QByteArray &name)
    {
        ZSharedVariantPointer val = currentCodeBlock->undefinedIdentifier.take(name);

        if(!val) {
            val = new ZSharedVariant();
        }

        addIdentifier(name, val);

        return val.data();
    }

    inline void addIdentifier(const QByteArray &name, const ZSharedVariantPointer &val)
    {
        if(currentCodeBlock->identifiers.contains(name)) {
            zWarning << "Symbol has been defined:" << name;

            return;
        }

        currentCodeBlock->identifiers[name] = val;
    }

    static ZSharedVariantPointer createFunction(ZCodeExecuter *executer);

    inline CodeBlock *getCodeBlock() const
    { return currentCodeBlock;}

    inline CodeBlock *getCodeBlockByType(CodeBlock::Type type, CodeBlock *startBlock) const
    {
        if(!startBlock)
            return startBlock;

        CodeBlock *block = startBlock;

        while(block) {
            if((block->type | type) == type) {
                return block;
            }

            block = block->parent;
        }

        return block;
    }

    inline QVector<ZSharedVariant*> &getParameterList()
    { return parameterList;}

    void beginCodeBlock(CodeBlock::Type type = CodeBlock::Normal);
    void endCodeBlock();

    /// 设置是否将指令保存到临时列表（tmpCodeList）
    inline void setEnableTmpCodeList(bool enable)
    { enableTmpCodeList = enable;}

    static ZCodeExecuter *beginCodeExecuter();
    static ZCodeExecuter *endCodeExecuter();

    static ZCodeExecuter *currentCodeExecuter;
    static YYFlexLexer *yyFlexLexer;

private:
    ZCodeExecuter();

    ZCode *createCode(const ZCode::Action &action, const ZSharedVariantPointer &val);

    inline void deleteAllCodeBlock()
    {
        for(int i = 0; i < codeBlockList.count(); ++i) {
            CodeBlock *block = codeBlockList.at(i);

            if(block->isLoopStructure()) {
                delete block->toLoopStructureCodeBlock();
            } else if(block->type == CodeBlock::Switch) {
                delete block->toSwitchCodeBlock();
            } else {
                delete block;
            }
        }

        codeBlockList.clear();
    }

    inline void deleteAllCode()
    {
        for(int i = 0; i < codeList.count(); ++i) {
            ZCode *code = codeList.at(i);

            if(code->isValueCode()) {
                delete code->toValueCode();
            } else {
                delete code;
            }
        }

        codeList.clear();
    }

    ZCodeExecuter *parent = Q_NULLPTR;

    /// 指令列表
    QList<ZCode*> codeList;

    ///　是否启用临时指令列表
    bool enableTmpCodeList = false;

    CodeBlock *currentCodeBlock = Q_NULLPTR;
    QList<CodeBlock*> codeBlockList;
    QMap<QByteArray, ZSharedVariant*> gotoLabelMap;
    /// function object parameter tmp list
    QVector<ZSharedVariant*> parameterList;

    static QHash<const QByteArray, ZSharedVariant*> globalIdentifierHash;
    static QMap<QByteArray, ZVariant*> stringConstantMap;
    static QMap<QByteArray, ZVariant*> numberConstantMap;
    static ZVariant constTrue;
    static ZVariant constFalse;
    static ZVariant constUndefined;

    friend class ZUserFunction;
    friend class ZCode;
};

Z_END_NAMESPACE

QT_BEGIN_NAMESPACE
Q_CORE_EXPORT QDebug operator<<(QDebug deg, const ZCode &var);
QT_END_NAMESPACE

#endif // ZCODE_H
