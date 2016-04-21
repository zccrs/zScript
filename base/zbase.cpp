#include "zbase.h"
#include "zcode.h"
#include "zconsole.h"
#include "zsystem.h"

namespace ZBase {
void initGlobalIdentifier()
{
    ZCodeExecuter::registerIdentifier("console", new ZSharedVariant(new ZConsole));
    ZCodeExecuter::registerIdentifier("sys", new ZSharedVariant(new ZSystem));
}
}
