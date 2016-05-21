#include "zbase.h"
#include "zcode.h"
#include "zconsole.h"
#include "zsystem.h"

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

namespace ZBase {

TYPE_TRANSITION(Int)
TYPE_TRANSITION(Double)
TYPE_TRANSITION(Bool)
TYPE_TRANSITION(String)

void initGlobalIdentifier()
{
    ZCodeExecuter::registerIdentifier("console", new ZSharedVariant(new ZConsole));
    ZCodeExecuter::registerIdentifier("sys", new ZSharedVariant(new ZSystem));
    ZCodeExecuter::registerIdentifier("int", new ZSharedVariant(new ZInt));
    ZCodeExecuter::registerIdentifier("double", new ZSharedVariant(new ZDouble));
    ZCodeExecuter::registerIdentifier("bool", new ZSharedVariant(new ZBool));
    ZCodeExecuter::registerIdentifier("string", new ZSharedVariant(new ZString));
}
}
