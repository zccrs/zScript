#include "zbase.h"
#include "zcode.h"
#include "zconsole.h"
#include "zsystem.h"

namespace ZBase {
void initGlobalIdentifier()
{
    ZCodeExecuter::registerIdentifier("console", new ZVariant(new ZConsole));
    ZCodeExecuter::registerIdentifier("sys", new ZVariant(new ZSystem));
}
}
