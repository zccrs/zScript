#ifndef ZCODE_H
#define ZCODE_H

#include "zvariant.h"

#include <QSet>

class yyFlexLexer;

namespace yy {
class parser;
}

typedef yyFlexLexer YYFlexLexer;
typedef yy::parser  YYParser;

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
        Unknow              //                              49
    };

    static QString actionName(quint8 action);

    static int exec(const QList<ZCode*> &codeList);

    quint8 action = Unknow;

    static QStack<ZVariant*> virtualStack;
    static ZVariant virtualRegister;
};

struct ValueCode : public ZCode
{
    ZVariant *value = Q_NULLPTR;
};

class ZCodeParse
{
public:
    ZCodeParse();
    ~ZCodeParse();

    struct Scope{
        Scope *parent = Q_NULLPTR;
        QHash<QByteArray, ZVariant*> identifiers;
    };

    inline static void registerIdentifier(const QByteArray &name, ZVariant *variant)
    {globalIdentifierHash[name] = variant;}

    /// from stdin get code
    int eval();
    int eval(const char *fileName, bool *ok = 0);
    int eval(const QByteArray &code, bool *ok = 0);

    inline int exec()
    { return ZCode::exec(codeList);}

    ZVariant *getIdentifierAddress(const QByteArray &name);

    static ZVariant *getConstantAddress(const QByteArray &value, ZVariant::Type type);

    static inline ZVariant *getConstantAddressByValue(const ZVariant &value)
    { return getConstantAddress(value.toString().toLatin1(), value.type());}

    inline void appendCode(const ZCode::Action &action, ZVariant *val = Q_NULLPTR)
    { codeList << createCode(action, val);}

    inline ZVariant *getGotoLabel(const QByteArray &name)
    {
        ZVariant *val = gotoLabelMap.value(name);

        if(!val) {
            val = new ZVariant(constUndefined);

            gotoLabelMap[name] = val;
        }

        return val;
    }

    inline QList<ZCode*> &getCodeList()
    { return codeList;}

    inline YYFlexLexer *yyFlexLexer() const
    { return m_yyFlexLexer;}

    inline void addIdentifier(const QByteArray &name)
    { undefinedIdentifier.remove(name); currentScope->identifiers[name] = new ZVariant(constUndefined);}

    void beginScope();
    void endScope();

    static ZCodeParse *currentCodeParse;
    static bool yywrap;

private:
    ZCode *createCode(const ZCode::Action &action, ZVariant *val = Q_NULLPTR);

    YYFlexLexer *m_yyFlexLexer = Q_NULLPTR;
    YYParser *m_yyParser = Q_NULLPTR;

    ZCodeParse *parent = Q_NULLPTR;

    QList<ZCode*> codeList;
    Scope *currentScope = Q_NULLPTR;
    QList<Scope*> scopeList;
    QSet<const QByteArray> undefinedIdentifier;
    QMap<QByteArray, ZVariant*> gotoLabelMap;

    static QHash<const QByteArray, ZVariant*> globalIdentifierHash;
    static QMap<QByteArray, ZVariant*> stringConstantMap;
    static QMap<QByteArray, ZVariant*> numberConstantMap;
    static ZVariant constTrue;
    static ZVariant constFalse;
    static ZVariant constUndefined;
};

Z_END_NAMESPACE

QT_BEGIN_NAMESPACE
Q_CORE_EXPORT QDebug operator<<(QDebug deg, const ZCode &var);
QT_END_NAMESPACE

#endif // ZCODE_H
