#include "zconsole.h"

#include <iostream>

Z_BEGIN_NAMESPACE

ZConsole::ZConsole(ZObject *parent)
    : ZObject(parent)
{
    Z_REGIST_SLOT(&ZConsole::log);
}

void ZConsole::log(ZVariant &retVals, const QList<ZVariant> &args) const
{
    Q_UNUSED(retVals)

    if(args.isEmpty())
        return;

    for(int i = 0; i < args.count() - 1; ++i)
        zStandardPrint << variantToString(args.at(i)).toStdString() << " ";

    if(!args.isEmpty())
        zStandardPrint << variantToString(args.last()).toStdString() << std::endl;

    return;
}

QString ZConsole::variantToString(const ZVariant &val) const
{
    switch (val.type()) {
    case ZVariant::Object:
        return "[Object]";
    case ZVariant::Function:
        return "[Function]";
    case ZVariant::Undefined:
        return "undefined";
    case ZVariant::Tuple: {
        QString str = "<";
        const ZVariant::ZTuple &tuple = val.toTuple();

        for(int i = 0; i < tuple.count() - 1; ++i) {
            str.append(variantToString(*tuple.value(i))).append(", ");
        }

        if(tuple.isEmpty())
            return str.append(">");

        return str.append(variantToString(*tuple.last())).append(">");
    }
    case ZVariant::List: {
        QString str = "[";
        const QList<ZVariant> &list = val.toList();

        for(int i = 0; i < list.count() - 1; ++i) {
            str.append(variantToString(list.value(i))).append(", ");
        }

        if(list.isEmpty())
            return str.append("]");

        return str.append(variantToString(list.last())).append("]");
    }
    default:
        return val.toString();
    }
}

Z_END_NAMESPACE
