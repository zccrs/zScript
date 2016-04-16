#ifndef ZCODE_H
#define ZCODE_H

#include "zvariant.h"

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
        Comma,              // ,                            43      remove
        Call,               // ()                           44
        Push,       // push target value to stack   45
        Pop,                // pop stack                    46
        PopAll,             // clear stack                  47
        Unknow              //                              48
    };

    static QString actionName(quint8 action);
    static void registerIdentifier(const QByteArray &name, ZVariant *variant);

    static int exec(const QList<ZCode*> &codeList);
    inline static int exec()
    {return exec(codeList);}

    quint8 action = Unknow;

    static QStack<ZVariant*> virtualStack;
    static ZVariant virtualRegister;
    static QList<ZCode*> codeList;
    static QHash<QByteArray, ZVariant*> globalIdentifierHash;
};

struct ValueCode : public ZCode
{
    ZVariant *value = Q_NULLPTR;
};

Z_END_NAMESPACE

QT_BEGIN_NAMESPACE
Q_CORE_EXPORT QDebug operator<<(QDebug deg, const ZCode &var);
QT_END_NAMESPACE

#endif // ZCODE_H
