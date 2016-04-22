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

struct ZCode
{
    enum Action
    {
        LeftAssign,         // =                            0
        RightAssign,        // =
        Add,                // +                            1
        Sub,                // -                            2
        Mul,                // *                            3
        Div,                // /                            4
        Abs,                // +                            5
        Minus,              // -                            6
        And,                // &                            7
        Or,                 // |                            8
        Xor,                // ^                            9
        Contrary,           // ~                            10
        Mod,                // %                            11
        Not,                // !                            12
        AddAssign,          // +=                           13
        SubAssign,          // -=                           14
        MulAssign,          // *=                           15
        DivAssign,          // /=                           16
        AndAssign,          // &=                           17
        OrAssign,           // |=                           18
        XorAssign,          // ^=                           19
        ContraryAssign,     // ~=                           20        remove
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
        LAndAssign,         // ||=                          36
        LOrAssign,          // $$=                          37
        PrefixAddSelf,      // ++                           38
        PostfixAddSelf,     // ++                           39
        PrefixSubSelf,      // --                           40
        PostfixSubSelf,     // --                           41
        Get,                // .                            42
        Join,               // ,                            43     join variant
        Call,               // ()                           44
        Push,               // push target value to stack   45
        Pop,                // pop stack                    46
        PopAll,             // clear stack                  47
        Goto,               // goto code index              48
        If,                 // if                           49
        Unknow              //                              50
    };

    static QString actionName(quint8 action);

    static ZVariant exec(const QList<ZCode*> &codeList);

    quint8 action = Unknow;

    static QStack<ZVariant*> virtualStack;
};

struct ValueCode : public ZCode
{
    ZSharedVariantPointer value;
};

class ZCodeExecuter
{
public:
    ~ZCodeExecuter();

    struct CodeBlock{
        enum Type {
            Normal,
            Function,
            While,
            If
        };

        int beginCodeIndex;

        quint8 type = Normal;
        CodeBlock *parent = Q_NULLPTR;

        QMap<QByteArray, ZSharedVariantPointer> identifiers;
        QMap<QByteArray, ZSharedVariantPointer> undefinedIdentifier;
    };

    inline static void registerIdentifier(const QByteArray &name, ZSharedVariant *variant)
    {globalIdentifierHash[name] = variant;}

    /// from stdin get code
    int eval();
    int eval(const char *fileName, bool *ok = 0);
    int eval(const QByteArray &code, bool *ok = 0);

    inline ZVariant exec()
    { return ZCode::exec(codeList);}

    ZSharedVariantPointer getIdentifier(const QByteArray &name);

    static ZSharedVariant *createConstant(const QByteArray &value, ZVariant::Type type);

    static inline ZSharedVariant *createConstantByValue(const ZVariant &value)
    { return createConstant(value.toString().toLatin1(), value.type());}

    inline void     appendCode(const ZCode::Action &action)
    { codeList << createCode(action, ZSharedVariantPointer());}

    inline void appendCode(const ZCode::Action &action, ZSharedVariant *val)
    { codeList << createCode(action, ZSharedVariantPointer(val));}

    inline void appendCode(const ZCode::Action &action, const ZSharedVariantPointer &val)
    { codeList << createCode(action, val);}

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

    inline QVector<ZSharedVariant*> &getParameterList()
    { return parameterList;}

    void beginCodeBlock(CodeBlock::Type type = CodeBlock::Normal);
    void endCodeBlock();

    static ZCodeExecuter *beginCodeExecuter();
    static ZCodeExecuter *endCodeExecuter();

    static ZCodeExecuter *currentCodeExecuter;
    static YYFlexLexer *yyFlexLexer;
    static bool yywrap;

private:
    ZCodeExecuter();

    ZCode *createCode(const ZCode::Action &action, const ZSharedVariantPointer &val);


    ZCodeExecuter *parent = Q_NULLPTR;

    QList<ZCode*> codeList;
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
