#include "zbase.h"
#include "zcode.h"

#include <QCoreApplication>
#include <QtConcurrent/QtConcurrentRun>

void begin(const char *fileName)
{
    qRegisterMetaType<ZVariant>("ZVariant");

    ZBase::initGlobalIdentifier();

    ZCodeParse codeParse;

    qApp->exit(codeParse.eval(fileName));
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(argc > 1) {
        QtConcurrent::run(QThreadPool::globalInstance(), &begin, argv[1]);
    }

    return a.exec();;
}
