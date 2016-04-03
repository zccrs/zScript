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
#include <QDebug>

QT_BEGIN_NAMESPACE
class QObject;
QT_END_NAMESPACE

class Variant
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

    Variant(Type type = Undefined);
    Variant(int val);
    Variant(double val);
    Variant(bool val);
    Variant(const char *val);
    Variant(const Variant &other);
    Variant(const QString &val);
    Variant(QLatin1String val);
    template <typename T>
    Variant(const QList<T> &val);
    Variant(const QList<Variant> &val);
    Variant(QObject * const object);
    ~Variant();

    Type type() const;
    const char *typeName() const;

    int toInt(bool *ok = 0) const;
    double toDouble(bool *ok = 0) const;
    bool toBool() const;
    QString toString() const;
    QList<Variant> toList() const;
    QObject *toObject() const;

private:
    class VariantData : public QSharedData
    {
        QVariant variant;
        Variant::Type type;

        friend class Variant;
    };

    QSharedDataPointer<VariantData> data;
};

Q_DECLARE_METATYPE(Variant)

Q_CORE_EXPORT QDebug operator<<(QDebug deg, const Variant &var);

/// int
Variant operator +(const int var1, const Variant &var2);
Variant operator -(const int var1, const Variant &var2);
Variant operator *(const int var1, const Variant &var2);
Variant operator /(const int var1, const Variant &var2);
Variant operator &&(const int var1, const Variant &var2);
Variant operator ||(const int var1, const Variant &var2);
Variant operator &(const int var1, const Variant &var2);
Variant operator |(const int var1, const Variant &var2);
Variant operator ^(const int var1, const Variant &var2);

/// double
Variant operator +(const double &var1, const Variant &var2);
Variant operator -(const double &var1, const Variant &var2);
Variant operator *(const double &var1, const Variant &var2);
Variant operator /(const double &var1, const Variant &var2);

inline Variant operator &&(const double &var1, const Variant &var2)
{return (int)var1 && var2;}

inline Variant operator ||(const double &var1, const Variant &var2)
{return (int)var1 || var2;}

inline Variant operator &(const double &var1, const Variant &var2)
{return (int)var1 & var2;}

inline Variant operator |(const double &var1, const Variant &var2)
{return (int)var1 | var2;}

inline Variant operator ^(const double &var1, const Variant &var2)
{return (int)var1 ^ var2;}

/// string
Variant operator +(const QString &var1, const Variant &var2);
Variant operator -(const QString &var1, const Variant &var2);
Variant operator *(const QString &var1, const Variant &var2);
Variant operator /(const QString &var1, const Variant &var2);

inline Variant operator &&(const QString &/*var1*/, const Variant &/*var2*/)
{return Variant::NaN;}

inline Variant operator ||(const QString &/*var1*/, const Variant &/*var2*/)
{return Variant::NaN;}

inline Variant operator &(const QString &/*var1*/, const Variant &/*var2*/)
{return Variant::NaN;}

inline Variant operator |(const QString &/*var1*/, const Variant &/*var2*/)
{return Variant::NaN;}

inline Variant operator ^(const QString &/*var1*/, const Variant &/*var2*/)
{return Variant::NaN;}

#define OPERATOR(OP) \
    inline Variant operator OP (const Variant &var1, const Variant &var2)\
    {\
        switch(var1.type()) {\
        case Variant::Int:\
            return var1.toInt() OP var2;\
        case Variant::Double:\
            return var1.toDouble() OP var2;\
        case Variant::String:\
            return var1.toString() OP var2;\
        case Variant::Bool:\
            return (int)var1.toBool() OP var2;\
        default: break;\
        }\
        return Variant::NaN;\
    }

#define OPERATOR_ASS(OP) \
    inline Variant &operator OP##=(Variant &var1, const Variant &var2)\
    {return var1 = var1 OP var2;}

OPERATOR(+)
OPERATOR(-)
OPERATOR(*)
OPERATOR(/)
OPERATOR(&&)
OPERATOR(||)
OPERATOR(&)
OPERATOR(|)
OPERATOR(^)

OPERATOR_ASS(+)
OPERATOR_ASS(-)
OPERATOR_ASS(*)
OPERATOR_ASS(/)
OPERATOR_ASS(&)
OPERATOR_ASS(|)
OPERATOR_ASS(^)

inline Variant &operator ++(Variant &var, int)
{return var = 1 + var;}

inline Variant &operator --(Variant &var, int)
{return var = 1 - var;}

inline Variant &operator ++(Variant &var)
{return var = 1 + var;}

inline Variant &operator --(Variant &var)
{return var = 1 - var;}

Variant operator !(const Variant &var);

QByteArray readFile(const QString &fileName);

struct TreeNode
{
    Variant value;
    QByteArray name;
};

#endif // GLOBAL_H
