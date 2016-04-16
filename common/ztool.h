#ifndef ZTOOL_H
#define ZTOOL_H

#include "zobject.h"

#include <QTextStream>

Z_BEGIN_NAMESPACE

class ZTool : public ZObject
{
public:
    explicit ZTool(ZObject *parent);

    static char charToEscape(char ch);
    /// \XXX
    static QString octStringHandler(QTextStream &stream, QString *errorString = 0);
    /// \xXX
    static QString utf8StringHandler(QTextStream &stream, QString *errorString = 0);
    /// \uXXXX
    static QString utf16StringHandler(QTextStream &stream, QString *errorString = 0);
    /// \u{XXX...}
    static QString ucs4StringHandler(QTextStream &stream, QString *errorString = 0);

    static QByteArray stringEscapeHandler(QTextStream &stream, const char *endWith = 0, QString *errorString = 0);
    inline static QByteArray stringEscapeHandler(const QByteArray &array)
    {
        QTextStream stream(array);

        return stringEscapeHandler(stream);
    }
};

Z_END_NAMESPACE

#endif // ZTOOL_H
