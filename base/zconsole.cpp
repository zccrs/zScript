#include "zconsole.h"

#include <iostream>

Z_BEGIN_NAMESPACE

ZConsole::ZConsole(ZObject *parent)
    : ZObject(parent)
{
    Z_REGIST_SLOT(&ZConsole::log);
}

void ZConsole::log(QList<ZVariant> &retVals, const QList<ZVariant> &args) const
{
    Q_UNUSED(retVals)

    if(args.isEmpty())
        return;

    for(int i = 0; i < args.count() - 1; ++i)
        zStandardPrint << args.at(i).toString().toStdString() << " ";

    zStandardPrint << args.last().toString().toStdString() << std::endl;

    return;
}

Z_END_NAMESPACE
