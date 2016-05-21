#include "zsystem.h"
#include "zcode.h"

#include <QThread>
#include <QTime>

ZSystem::ZSystem(ZObject *parent)
    : ZObject(parent)
{
    Z_REGIST_SLOT(&ZSystem::eval);
    Z_REGIST_SLOT(&ZSystem::sleep);
    Z_REGIST_SLOT(&ZSystem::msleep);
    Z_REGIST_SLOT(&ZSystem::usleep);
    Z_REGIST_SLOT(&ZSystem::random);

    const QTime &time = QTime::currentTime();

    qsrand(time.msec() + time.second() * 1000);
}

void ZSystem::eval(ZVariant &retVals, const QList<ZVariant> &args)
{
    if(args.isEmpty())
        return;

    ZCodeExecuter *executer = ZCodeExecuter::beginCodeExecuter();

    retVals = executer->eval(args.first().toString().toLocal8Bit());

    executer->endCodeExecuter();

    delete executer;
}

void ZSystem::sleep(ZVariant &retVals, const QList<ZVariant> &args)
{
    Q_UNUSED(retVals)

    if(args.isEmpty())
        return;

    QThread::currentThread()->sleep(args.first().toInt());
}

void ZSystem::msleep(ZVariant &retVals, const QList<ZVariant> &args)
{
    Q_UNUSED(retVals)

    if(args.isEmpty())
        return;

    QThread::currentThread()->msleep(args.first().toInt());
}

void ZSystem::usleep(ZVariant &retVals, const QList<ZVariant> &args)
{
    Q_UNUSED(retVals)

    if(args.isEmpty())
        return;

    QThread::currentThread()->usleep(args.first().toInt());
}

void ZSystem::random(ZVariant &retVals, const QList<ZVariant> &args) const
{
    int min, max;

    if (args.count() == 2) {
        min = args.first().toInt();
        max = args.last().toInt();
    } else if (args.count() == 3) {
        qsrand(args.first().toInt());
        min = args.at(1).toInt();
        max = args.last().toInt();
    } else {
        return;
    }

    retVals = (qrand() % (max - min + 1)) + min;

    const QTime &time = QTime::currentTime();

    qsrand(time.msec() + time.second() * 1000 * retVals.toInt());
}
