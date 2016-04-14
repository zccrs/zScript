#ifndef GLOBAL_H
#define GLOBAL_H

#define zDebug qDebug().noquote() << __FILE__ << __LINE__ << __FUNCTION__ << "[Debug]:"
#define zError qCritical().noquote() << "[Error]:"
#define zInfo qInfo().noquote() << "[Info]:"
#define zWarning qWarning().noquote() << "[Warning]:"
#define zPrint qDebug().noquote()
#define zStandardPrint std::cout
#define zExit(code) exit(code)
#define zErrorQuit zExit(-1)
#define zQuit zExit(0)

#include <QSharedDataPointer>
#include <QObject>
#include <QDebug>

namespace Global {

class ZObject;

class ZVariant
{
public:
    enum Type {
        Int = QMetaType::Int,
        Double = QMetaType::Double,
        Bool = QMetaType::Bool,
        String = QMetaType::QString,
        List = QMetaType::QVariantList,
        Object = QMetaType::PointerToQObject,
        Undefined = QMetaType::UnknownType,
        NaN = QMetaType::User + 1,
        Null = QMetaType::User + 2
    };

    ZVariant(Type type = Undefined);
    ZVariant(int val);
    ZVariant(double val);
    ZVariant(bool val);
    ZVariant(const char *val);
    ZVariant(const ZVariant &other);
    ZVariant(ZVariant &&other);
    ZVariant(const QString &val);
    ZVariant(QLatin1String val);
    template <typename T>
    ZVariant(const QList<T> &val);
    ZVariant(const QList<ZVariant> &val);
    ZVariant(ZObject * const object);
    ZVariant(const QVariant &val);
    ~ZVariant();

    Type type() const;
    const char *typeName() const;

    int toInt(bool *ok = 0) const;
    double toDouble(bool *ok = 0) const;
    bool toBool() const;
    QString toString() const;
    QList<ZVariant> toList() const;
    ZObject *toObject() const;
    QVariant toQVariant() const;

    inline ZVariant& operator=(const ZVariant &other)
    { data = other.data; return *this;}
    inline ZVariant& operator=(ZVariant &&other)
    { qSwap(data, other.data); return *this;}
    inline bool operator==(const ZVariant &v) const
    { return data->variant == v.data->variant; }
    inline bool operator!=(const ZVariant &v) const
    { return data->variant != v.data->variant; }
    inline bool operator<(const ZVariant &v) const
    { return data->variant < v.data->variant; }
    inline bool operator<=(const ZVariant &v) const
    { return data->variant <= v.data->variant; }
    inline bool operator>(const ZVariant &v) const
    { return data->variant > v.data->variant; }
    inline bool operator>=(const ZVariant &v) const
    { return data->variant >= v.data->variant; }
    inline bool operator&&(const ZVariant &v) const
    { return toBool() && v.toBool();}
    inline bool operator||(const ZVariant &v) const
    { return toBool() || v.toBool();}
    inline bool operator!() const
    { return !toBool();}
    inline ZVariant operator-() const
    {
        switch(data->type) {
        case Double:
            return -toDouble();
        case Int:
        case Bool:
            return -toInt();
        case String:
            return toString().toLower();
        default: return NaN;
        }
    }
    inline ZVariant operator+() const
    {
        switch(data->type) {
        case Double:
            return qAbs(toDouble());
        case Int:
        case Bool:
            return qAbs(toInt());
        case String:
            return toString().toUpper();
        default: return NaN;
        }
    }

private:
    class VariantData : public QSharedData
    {
        QVariant variant;
        ZVariant::Type type;

        friend class ZVariant;
    };

    QSharedDataPointer<VariantData> data;
};

QT_BEGIN_NAMESPACE
Q_CORE_EXPORT QDebug operator<<(QDebug deg, const ZVariant &var);
QT_END_NAMESPACE

/// int
ZVariant operator +(const int var1, const ZVariant &var2);
ZVariant operator -(const int var1, const ZVariant &var2);
ZVariant operator *(const int var1, const ZVariant &var2);
ZVariant operator /(const int var1, const ZVariant &var2);
ZVariant operator &(const int var1, const ZVariant &var2);
ZVariant operator |(const int var1, const ZVariant &var2);
ZVariant operator ^(const int var1, const ZVariant &var2);
ZVariant operator %(const int var1, const ZVariant &var2);

/// double
ZVariant operator +(const double &var1, const ZVariant &var2);
ZVariant operator -(const double &var1, const ZVariant &var2);
ZVariant operator *(const double &var1, const ZVariant &var2);
ZVariant operator /(const double &var1, const ZVariant &var2);

inline ZVariant operator &(const double &var1, const ZVariant &var2)
{return (int)var1 & var2;}

inline ZVariant operator |(const double &var1, const ZVariant &var2)
{return (int)var1 | var2;}

inline ZVariant operator ^(const double &var1, const ZVariant &var2)
{return (int)var1 ^ var2;}

inline ZVariant operator %(const double &var1, const ZVariant &var2)
{return (int)var1 ^ var2;}

/// string
ZVariant operator +(const QString &var1, const ZVariant &var2);
ZVariant operator -(const QString &var1, const ZVariant &var2);
ZVariant operator *(const QString &var1, const ZVariant &var2);
ZVariant operator /(const QString &var1, const ZVariant &var2);
ZVariant operator &(const QString &var1, const ZVariant &var2);
ZVariant operator |(const QString &var1, const ZVariant &var2);
ZVariant operator ^(const QString &var1, const ZVariant &var2);
ZVariant operator %(const QString &var1, const ZVariant &var2);

#define OPERATOR(OP) \
    inline ZVariant operator OP (const ZVariant &var1, const ZVariant &var2)\
    {\
        switch(var1.type()) {\
        case ZVariant::Int:\
            return var1.toInt() OP var2;\
        case ZVariant::Double:\
            return var1.toDouble() OP var2;\
        case ZVariant::String:\
            return var1.toString() OP var2;\
        case ZVariant::Bool:\
            return (int)var1.toBool() OP var2;\
        default: break;\
        }\
        return ZVariant::NaN;\
    }

#define OPERATOR_ASS(OP) \
    inline ZVariant &operator OP##=(ZVariant &var1, const ZVariant &var2)\
    {return var1 = var1 OP var2;}

OPERATOR(+)
OPERATOR(-)
OPERATOR(*)
OPERATOR(/)
OPERATOR(&)
OPERATOR(|)
OPERATOR(^)
OPERATOR(%)

OPERATOR_ASS(+)
OPERATOR_ASS(-)
OPERATOR_ASS(*)
OPERATOR_ASS(/)
OPERATOR_ASS(&)
OPERATOR_ASS(|)
OPERATOR_ASS(^)
OPERATOR_ASS(%)

inline ZVariant &operator ++(ZVariant &var, int)
{return var = 1 + var;}

inline ZVariant &operator --(ZVariant &var, int)
{return var = -1 + var;}

inline ZVariant &operator ++(ZVariant &var)
{return var = 1 + var;}

inline ZVariant &operator --(ZVariant &var)
{return var = -1 + var;}

ZVariant operator ~(const ZVariant &var);

class ZObject : public QObject
{
    Q_OBJECT

public:
    explicit ZObject(ZObject *parent = 0);

    ZVariant property(const char *name) const;

public slots:
    void setProperty(const char *name, const ZVariant &value);
    void addFunctionProperty(const char *name);

private slots:
    void initFunctionProperty();
};

class ZFunction : public ZObject
{
    Q_OBJECT

public:
    explicit ZFunction(ZObject *target, const char *name, ZObject *parent = 0);

public slots:
    QList<ZVariant> call(const QList<ZVariant> &args) const;

private:
    ZObject *m_target;
    QByteArray m_methodName;
};

struct Code;

struct Node
{
    enum OperatorType
    {
        Assign,             // =
        Add,                // +
        Sub,                // -
        Mul,                // *
        Div,                // /
        Abs,                // +
        Minus,              // -
        And,                // &
        Or,                 // |
        Xor,                // ^
        Contrary,           // ~
        Mod,                // %
        Not,                // !
        Less,               // <
        Greater,            // >
        New,                // new
        Delete,             // delete
        Throw,              // throw
        EQ,                 // ==
        STEQ,               // ===
        NEQ,                // !=
        STNEQ,              // !==
        LE,                 // <=
        GE,                 // >=
        LAnd,               // &&
        LOr,                // ||
        PrefixAddSelf,      // ++
        PostfixAddSelf,     // ++
        PrefixSubSelf,      // --
        PostfixSubSelf,     // --
        Get,                // .
        Comma,              // ,
        Call,               // ()
        Variant,
        Constant,
        Unknow
    };

    struct Children{
        Node *left = Q_NULLPTR;
        Node *right = Q_NULLPTR;
    };

//    union Data{
//        Children *nodeChildrens = Q_NULLPTR;
//        Node *nodeChildren = Q_NULLPTR;
//        Code *codeChildren = Q_NULLPTR;
//        ZVariant *value = Q_NULLPTR;
//    };

    OperatorType nodeType = Unknow;
    //Data data;

    Node(OperatorType t, Node *l = Q_NULLPTR, Node *r = Q_NULLPTR);
    ~Node();

    void recursion();
};

class CodeData : public QSharedData
{
public:
    QSharedDataPointer<CodeData> parent;
    QHash<QByteArray, ZVariant*> identifiersHash;

    ZVariant variantValue(const QByteArray &name) const;
};

struct Code
{
    QList<Node*> nodeList;
    QSharedDataPointer<CodeData> data;
    Code(Code *parent = Q_NULLPTR);

    inline const CodeData *constData() const
    {return data.constData();}

    ZVariant variantValue(const QByteArray &name) const
    {return data->variantValue(name);}

    void exec() const;
};

class ZConsole : public ZObject
{
    Q_OBJECT

public:
    explicit ZConsole(ZObject *parent = 0);

public slots:
    QList<ZVariant> log(const QList<ZVariant> &args) const;
};

struct ZCode
{
    enum Action
    {
        Assign,             // =                            0
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
        ContraryAssign,     // ~=                           20
        ModAssign,          // %=                           21
        NotAssign,          // !=                           22
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
        Comma,              // ,                            43
        Call,               // ()                           44
        Push,               // push target value to stack   45
        Pop,                // pop stack                    46
        PopAll,             // clear stack                  47
        Variant,            //                              48
        Constant,           //                              49
        Unknow              //                              50
    };

    static QString actionName(const Action &action);

    Action action = Unknow;
    ZVariant *target;
};

QT_BEGIN_NAMESPACE
Q_CORE_EXPORT QDebug operator<<(QDebug deg, const ZCode &var);
QT_END_NAMESPACE

extern QStack<ZVariant*> virtualStack;
extern ZVariant virtualRegister;
extern QList<ZCode*> codeList;

}/// namespace Global end

Q_DECLARE_METATYPE(Global::ZVariant)

#endif // GLOBAL_H
