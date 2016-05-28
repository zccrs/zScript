#include "zbase.h"
#include "zcode.h"
#include "zconsole.h"
#include "zsystem.h"

#include <QList>

#define TYPE_TRANSITION(Type)\
    class Z##Type : public ZFunction\
    {\
    public:\
        explicit Z##Type(ZObject *parent = 0)\
            : ZFunction(parent)\
        {}\
        ZVariant call(const QList<ZVariant> &args) const Q_DECL_OVERRIDE\
        {\
            if (args.isEmpty())\
                return ZVariant::Undefined;\
            return args.first().to##Type();\
        }\
    };

#define REGISTER_FUNCTION(Type, Fun) {\
    const QList<QString> list = QString(#Fun).split("::");\
    if (list.count() == 2)\
        ZCodeExecuter::registerFunction(Type, list.last().toLatin1(), new ZMethod(&Fun));\
    else\
        ZCodeExecuter::registerFunction(Type, #Fun, new ZMethod(&Fun));}

namespace ZBase {

TYPE_TRANSITION(Int)
TYPE_TRANSITION(Double)
TYPE_TRANSITION(Bool)
TYPE_TRANSITION(String)

namespace String {
    ZVariant toInt(const QList<ZVariant> &args)
    {
        ZVariant::ZTuple retVals;

        bool ok;

        int base = 10;

        if (args.count() > 1) {
            base = args.at(1).toInt(&ok);

            if (!ok)
                base = 10;
        }

        retVals << new ZVariant(args.first().toString().toInt(&ok, base));
        retVals << new ZVariant(ok);

        return retVals;
    }

    ZVariant append(const QList<ZVariant> &args)
    {
        QString string = args.first().toString();

        for (int i = 1; i < args.count(); ++i)
            string.append(args.at(i).toString());

        args.first().depthCopyAssign(string);

        return args.first();
    }

    ZVariant at(const QList<ZVariant> &args)
    {
        if (args.count() < 2)
            return ZVariant();

        return QString(args.first().toString().at(args.at(1).toInt()));
    }

    ZVariant contains(const QList<ZVariant> &args)
    {
        if (args.count() < 2)
            return ZVariant();

        const ZVariant &variant = args.first();

        return variant.toString().contains(args.at(1).toString());
    }

    ZVariant count(const QList<ZVariant> &args)
    {
        return args.first().toString().count();
    }

    ZVariant endsWith(const QList<ZVariant> &args)
    {
        if (args.count() < 2)
            return ZVariant();

        return args.first().toString().endsWith(args.at(1).toString());
    }

    ZVariant indexOf(const QList<ZVariant> &args)
    {
        if (args.count() < 2)
            return ZVariant();

        const ZVariant &variant = args.first();

        return variant.toString().indexOf(args.at(1).toString());
    }

    ZVariant insert(const QList<ZVariant> &args)
    {
        if (args.count() < 3)
            return ZVariant();

        ZVariant variant = args.first();

        variant.depthCopyAssign(variant.toString().insert(args.at(1).toInt(), args.at(2).toString()));

        return args.first();
    }

    ZVariant isEmpty(const QList<ZVariant> &args)
    {
        return args.first().toString().isEmpty();
    }

    ZVariant isNull(const QList<ZVariant> &args)
    {
        return args.first().toString().isNull();
    }

    ZVariant lastIndexOf(const QList<ZVariant> &args)
    {
        if (args.count() < 2)
            return ZVariant();

        return args.first().toString().lastIndexOf(args.at(1).toString());
    }

    ZVariant left(const QList<ZVariant> &args)
    {
        if (args.count() < 2)
            return ZVariant();

        return args.first().toString().left(args.at(1).toInt());
    }

    ZVariant length(const QList<ZVariant> &args)
    {
        return args.first().toString().length();
    }

    ZVariant mid(const QList<ZVariant> &args)
    {
        if (args.count() == 2)
            return args.first().toString().mid(args.at(1).toInt());
        else if (args.count() > 2)
            return args.first().toString().mid(args.at(1).toInt(), args.at(2).toInt());

        return ZVariant();
    }

    ZVariant prepend(const QList<ZVariant> &args)
    {
        if (args.count() < 2)
            return ZVariant();

        QString string = args.first().toString();

        string.prepend(args.at(1).toString());

        args.first().depthCopyAssign(string);

        return args.first();
    }

    ZVariant remove(const QList<ZVariant> &args)
    {
        QString string = args.first().toString();

        if (args.count() == 2)
            string.remove(args.at(1).toString());
        else if (args.count() > 2)
            string.remove(args.at(1).toInt(), args.at(2).toInt());

        args.first().depthCopyAssign(string);

        return args.first();
    }

    ZVariant replace(const QList<ZVariant> &args)
    {
        QString string = args.first().toString();

        if (args.count() == 3)
            string.replace(args.at(1).toString(), args.at(2).toString());
        else if (args.count() > 3)
            string.replace(args.at(1).toInt(), args.at(2).toInt(), args.at(3).toString());

        args.first().depthCopyAssign(string);

        return args.first();
    }

    ZVariant right(const QList<ZVariant> &args)
    {
        if (args.count() < 2)
            return ZVariant();

        return args.first().toString().right(args.at(1).toInt());
    }

    ZVariant split(const QList<ZVariant> &args)
    {
        if (args.count() < 2)
            return ZVariant();

        QList<ZVariant> list;

        for (const QString &str : args.first().toString().split(args.at(1).toString())) {
            list << str;
        }

        return list;
    }

    ZVariant startsWith(const QList<ZVariant> &args)
    {
        if (args.count() < 2)
            return ZVariant();

        return args.first().toString().startsWith(args.at(1).toString());
    }
}// end namespace String

namespace List {
    ZVariant append(const QList<ZVariant> &args)
    {
        QList<ZVariant> list = args.first().toList();

        for (int i = 1; i < args.count(); ++i)
            list.append(args.at(i));

        args.first().depthCopyAssign(list);

        return ZVariant();
    }

    ZVariant at(const QList<ZVariant> &args)
    {
        if (args.count() < 2)
            return ZVariant();

        return args.first().toList().at(args.at(1).toInt());
    }

    ZVariant contains(const QList<ZVariant> &args)
    {
        if (args.count() < 2)
            return ZVariant();

        const ZVariant &variant = args.first();

        return variant.toList().contains(args.at(1));
    }

    ZVariant count(const QList<ZVariant> &args)
    {
        return args.first().toList().count();
    }

    ZVariant indexOf(const QList<ZVariant> &args)
    {
        if (args.count() < 2)
            return ZVariant();

        const ZVariant &variant = args.first();

        return variant.toList().indexOf(args.at(1));
    }

    ZVariant insert(const QList<ZVariant> &args)
    {
        if (args.count() > 2) {
            QList<ZVariant> list = args.first().toList();

            list.insert(args.at(1).toInt(), args.at(2));
            args.first().depthCopyAssign(list);
        }

        return ZVariant();
    }

    ZVariant isEmpty(const QList<ZVariant> &args)
    {
        return args.first().toList().isEmpty();
    }

    ZVariant lastIndexOf(const QList<ZVariant> &args)
    {
        if (args.count() < 2)
            return ZVariant();

        return args.first().toList().lastIndexOf(args.at(1));
    }

    ZVariant length(const QList<ZVariant> &args)
    {
        return args.first().toList().length();
    }

    ZVariant mid(const QList<ZVariant> &args)
    {
        if (args.count() < 3)
            return ZVariant();

        return args.first().toList().mid(args.at(1).toInt(), args.at(2).toInt());
    }

    ZVariant prepend(const QList<ZVariant> &args)
    {
        if (args.count() > 1) {
            QList<ZVariant> list = args.first().toList();

            list.prepend(args.at(1));
            args.first().depthCopyAssign(list);
        }

        return args.first();
    }

    ZVariant removeAll(const QList<ZVariant> &args)
    {
        if (args.count() > 1) {
            QList<ZVariant> list = args.first().toList();

            list.removeAll(args.at(1));
            args.first().depthCopyAssign(list);
        }

        return args.first();
    }

    ZVariant removeAt(const QList<ZVariant> &args)
    {
        if (args.count() > 1) {
            QList<ZVariant> list = args.first().toList();

            list.removeAt(args.at(1).toInt());
            args.first().depthCopyAssign(list);
        }

        return args.first();
    }

    ZVariant removeOne(const QList<ZVariant> &args)
    {
        if (args.count() > 1) {
            QList<ZVariant> list = args.first().toList();

            list.removeOne(args.at(1));
            args.first().depthCopyAssign(list);
        }

        return args.first();
    }

    ZVariant replace(const QList<ZVariant> &args)
    {
        if (args.count() > 2) {
            QList<ZVariant> list = args.first().toList();

            list.replace(args.at(1).toInt(), args.at(2));
            args.first().depthCopyAssign(list);
        }

        return ZVariant();
    }

    ZVariant join(const QList<ZVariant> &args)
    {
        if (args.count() < 2)
            return ZVariant();

        QString string;
        const QString separator = args.at(1).toString();

        for (const ZVariant &item : args.first().toList()) {
            string.append(separator).append(item.toString());
        }

        return string.mid(string.count());
    }
}// end namespace List

void init()
{
    ZCodeExecuter::registerIdentifier("console", new ZSharedVariant(new ZConsole));
    ZCodeExecuter::registerIdentifier("sys", new ZSharedVariant(new ZSystem));
    ZCodeExecuter::registerIdentifier("int", new ZSharedVariant(new ZInt));
    ZCodeExecuter::registerIdentifier("double", new ZSharedVariant(new ZDouble));
    ZCodeExecuter::registerIdentifier("bool", new ZSharedVariant(new ZBool));
    ZCodeExecuter::registerIdentifier("string", new ZSharedVariant(new ZString));

    REGISTER_FUNCTION(ZVariant::String, String::toInt);
    REGISTER_FUNCTION(ZVariant::String, String::append);
    REGISTER_FUNCTION(ZVariant::String, String::at);
    REGISTER_FUNCTION(ZVariant::String, String::contains);
    REGISTER_FUNCTION(ZVariant::String, String::count);
    REGISTER_FUNCTION(ZVariant::String, String::endsWith);
    REGISTER_FUNCTION(ZVariant::String, String::indexOf);
    REGISTER_FUNCTION(ZVariant::String, String::insert);
    REGISTER_FUNCTION(ZVariant::String, String::isEmpty);
    REGISTER_FUNCTION(ZVariant::String, String::isNull);
    REGISTER_FUNCTION(ZVariant::String, String::lastIndexOf);
    REGISTER_FUNCTION(ZVariant::String, String::left);
    REGISTER_FUNCTION(ZVariant::String, String::length);
    REGISTER_FUNCTION(ZVariant::String, String::mid);
    REGISTER_FUNCTION(ZVariant::String, String::prepend);
    REGISTER_FUNCTION(ZVariant::String, String::remove);
    REGISTER_FUNCTION(ZVariant::String, String::replace);
    REGISTER_FUNCTION(ZVariant::String, String::right);
    REGISTER_FUNCTION(ZVariant::String, String::split);
    REGISTER_FUNCTION(ZVariant::String, String::startsWith);

    REGISTER_FUNCTION(ZVariant::List, List::append);
    REGISTER_FUNCTION(ZVariant::List, List::at);
    REGISTER_FUNCTION(ZVariant::List, List::contains);
    REGISTER_FUNCTION(ZVariant::List, List::count);
    REGISTER_FUNCTION(ZVariant::List, List::indexOf);
    REGISTER_FUNCTION(ZVariant::List, List::insert);
    REGISTER_FUNCTION(ZVariant::List, List::isEmpty);
    REGISTER_FUNCTION(ZVariant::List, List::lastIndexOf);
    REGISTER_FUNCTION(ZVariant::List, List::length);
    REGISTER_FUNCTION(ZVariant::List, List::mid);
    REGISTER_FUNCTION(ZVariant::List, List::prepend);
    REGISTER_FUNCTION(ZVariant::List, List::removeAll);
    REGISTER_FUNCTION(ZVariant::List, List::removeAt);
    REGISTER_FUNCTION(ZVariant::List, List::removeOne);
    REGISTER_FUNCTION(ZVariant::List, List::replace);
    REGISTER_FUNCTION(ZVariant::List, List::join);
}
}// end namespace ZBase
