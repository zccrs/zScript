#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QFileInfo>
#include <QRegularExpression>
#include <QDebug>

#include "global.h"

QByteArray preproccess(const QByteArray &source)
{
    QByteArray re;

    re.reserve(source.size());

    for(QByteArray array : source.split('\n')) {
        if(array.isEmpty())
            continue;

        array = QString(array).replace(QRegularExpression("(?<!var|new|delete|function|throw)\\s"), "").toLatin1();

        int i = -1;

        while(++i < array.count()) {
            QChar ch = array.at(i);

            switch (ch.toLatin1()) {
            case '\'':/// intentional
            case '"':{
                int j = i;

                while(++j < array.count()) {
                    QChar tmp_ch = array.at(j);

                    switch (tmp_ch.toLatin1()) {
                    case '\\':
                        ++j;
                        break;
                    case '\'':
                    case '"':/// intentional
                        if(tmp_ch == ch)
                            goto next;
                        break;
                    default:
                        break;
                    }
                }

next:

                re.append(array.mid(i, j - i + 2));

                i = j + 1;

                break;
            }
            case '/':{
                if(i + 1 < array.size() && array.at(i + 1) == '/') {
                    i = array.count();
                } else {
                    re.append(ch);
                }

                break;
            }
            case '\\':
                break;
            default:
                re.append(ch);
                break;
            }
        }

        if(!array.endsWith(';') && !array.endsWith('{')
                && !array.endsWith('}') && !array.endsWith('\\')
                && !array.endsWith(',') && !re.endsWith(';'))
            re.append(';');
    }

    return re;
}

QByteArray readFile(const QString &fileName)
{
    QFile file(fileName);
    QByteArray re;

    if(file.open(QIODevice::ReadOnly)) {
        re = file.readAll();
        file.close();
    }

    return re;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(a.arguments().count() > 1) {
        QFileInfo info(a.arguments().value(1));

        if(!info.exists()) {
            zError << info.absoluteFilePath() << "is not exists";
            zErrorQuit;
        }

        zPrint << preproccess(readFile(info.absoluteFilePath()));
    } else {
        QTextStream input_stream(stdin);

        zPrint << preproccess(input_stream.readAll().toLocal8Bit());
    }
}
