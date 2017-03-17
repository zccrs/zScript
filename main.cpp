#include "zbase.h"
#include "zcode.h"

#include <QCoreApplication>
#include <QtConcurrent/QtConcurrentRun>
#include <QStack>

void begin(const char *fileName)
{
    qRegisterMetaType<ZVariant>("ZVariant");
    ZCode::virtualStack.reserve(50);

    ZBase::init();

    ZCodeExecuter *executer = ZCodeExecuter::beginCodeExecuter();

    int quitCode = executer->eval(fileName);

    ZCodeExecuter::endCodeExecuter();

    delete executer;

    qApp->exit(quitCode);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(argc > 1) {
        QtConcurrent::run(QThreadPool::globalInstance(), &begin, argv[1]);
    }

    return a.exec();;
}
