#include "zsystem.h"
#include "zcode.h"

ZSystem::ZSystem(ZObject *parent)
    : ZObject(parent)
{
    Z_REGIST_SLOT(&ZSystem::eval);
}

void ZSystem::eval(QList<ZVariant> &retVals, const QList<ZVariant> &args)
{
    if(args.isEmpty())
        return;

    ZCodeParse parse;

    retVals << parse.eval(args.first().toString().toLocal8Bit());
}
