#include "ztool.h"

#include <QVector>
#include <QDebug>

Z_BEGIN_NAMESPACE

ZTool::ZTool(ZObject *parent)
    : ZObject(parent)
{

}

char ZTool::charToEscape(char ch)
{
    switch (ch) {
    case 'a':
        return '\a';
    case 'b':
        return '\b';
    case 'f':
        return '\f';
    case 'n':
        return '\n';
    case 'r':
        return '\r';
    case 't':
        return '\t';
    case 'v':
        return '\v';
    case '0':
        return '\0';
    default:
        return ch;
    }
}

QString ZTool::octStringHandler(QTextStream &stream, QString *errorString)
{
    QString array;

    while(!stream.atEnd()) {
        QString str = stream.read(4);

        if(str.count() != 4 || str.at(0) != '\\' || !str.at(1).isNumber()) {
            stream.seek(stream.pos() - 4);

            return array;
        }

        bool ok;

        quint8 ch = str.right(3).toUShort(&ok, 8);

        if(!ok) {
            if(errorString) {
                *errorString = QObject::tr("The unexpected symbol: ") + str;
            }

            return array;
        }

        array.append(ch);
    }

    return array;
}

QString ZTool::utf8StringHandler(QTextStream &stream, QString *errorString)
{
    QString array;

    while(!stream.atEnd()) {
        QString str = stream.read(4);

        if(str.count() != 4 || str.at(0) != '\\' || str.at(1) != 'x') {
            stream.seek(stream.pos() - 4);

            return array;
        }

        bool ok;

        quint8 ch = str.right(2).toUShort(&ok, 16);

        if(!ok) {
            if(errorString) {
                *errorString = QObject::tr("The unexpected symbol: ") + str;
            }

            return array;
        }

        array.append(ch);
    }

    return array;
}

QString ZTool::utf16StringHandler(QTextStream &stream, QString *errorString)
{
    QVector<quint16> array;

    while(!stream.atEnd()) {
        QString str = stream.read(6);

        if(str.count() != 6 || str.at(0) != '\\' || str.at(1) != 'u' || str.at(2) == '{') {
            stream.seek(stream.pos() - 6);

            return QString::fromUtf16(array.constData(), array.size());
        }

        bool ok;

        quint16 ch = str.right(4).toUShort(&ok, 16);

        if(!ok) {
            if(errorString) {
                *errorString = QObject::tr("The unexpected symbol: ") + str;
            }

            return QString::fromUtf16(array.constData(), array.size());
        }

        array << ch;
    }

    return QString::fromUtf16(array.constData(), array.size());
}

QString ZTool::ucs4StringHandler(QTextStream &stream, QString *errorString)
{
    QVector<quint32> array;

    while(!stream.atEnd()) {
        QString str = stream.read(3);

        if(str.count() != 3 || str.at(0) != '\\' || str.at(1) != 'u' || str.at(2) != '{') {
            stream.seek(stream.pos() - 3);

            return QString::fromUcs4(array.constData(), array.size());
        }

        char ch;

        while(!stream.atEnd()) {
            stream >> ch;

            if(ch == '}')
                break;

            str.append(ch);
        }

        if(ch != '}') {
            if(errorString) {
                *errorString = QObject::tr("The unexpected symbol: ") + str + ch;
            }

            return QString::fromUcs4(array.constData(), array.size());
        }

        bool ok;

        quint32 hex = str.mid(3).toUInt(&ok, 16);

        if(!ok) {
            if(errorString) {
                *errorString = QObject::tr("The unexpected symbol: ") + str;
            }

            return QString::fromUcs4(array.constData(), array.size());
        }

        array << hex;
    }

    return QString::fromUcs4(array.constData(), array.size());
}

QByteArray ZTool::stringEscapeHandler(QTextStream &stream, const char *endWith, QString *errorString)
{
    QByteArray str;

    while(!stream.atEnd()) {
        char ch;

        stream >> ch;

        if(endWith && ch == *endWith)
            break;

        if(ch == '\n' || ch == '\r') {
            if(errorString)
                *errorString = QObject::tr("The unexpected symbol: ") + ch;

            return str;
        }

        if(ch == '\\') {
            char next_ch;

            stream >> next_ch;

            switch(next_ch) {
            case 'x':{
                qint64 pos = stream.pos() - 2;

                stream.seek(pos);

                str.append(utf8StringHandler(stream, errorString));

                if(pos == stream.pos()) {
                    if(errorString)
                        *errorString = QObject::tr("The unexpected symbol: ") + next_ch;

                    stream.seek(pos + 2);

                    return str;
                }

                if(errorString && !errorString->isEmpty()) {
                    return str;
                }

                break;
            }
            case 'u': {
                char next_ch;

                stream >> next_ch;

                qint64 pos = stream.pos() - 3;

                stream.seek(pos);

                if(next_ch == '{') {
                    str.append(ucs4StringHandler(stream, errorString));
                } else {
                    str.append(utf16StringHandler(stream, errorString));
                }

                if(pos == stream.pos()) {
                    if(errorString)
                        *errorString = QObject::tr("The unexpected symbol: ") + next_ch;

                    stream.seek(pos + 3);

                    return str;
                }

                if(errorString && !errorString->isEmpty()) {
                    return str;
                }

                break;
            }
            default: {
                QChar ch(next_ch);

                if(ch.isNumber()) {
                    qint64 pos = stream.pos() - 1;

                    stream.seek(stream.pos() - 1);

                    str.append(octStringHandler(stream, errorString));

                    if(pos == stream.pos()) {
                        if(errorString)
                            *errorString = QObject::tr("The unexpected symbol: ") + next_ch;

                        stream.seek(pos + 1);

                        return str;
                    }

                    if(errorString && !errorString->isEmpty()) {
                        return str;
                    }
                } else {
                    str.append(charToEscape(next_ch));
                }
                break;
            }
            }
        } else {
            str.append(ch);
        }
    }

    return str;
}

Z_END_NAMESPACE
