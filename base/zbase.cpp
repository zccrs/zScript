#include "zbase.h"
#include "zcode.h"
#include "zconsole.h"
#include "zsystem.h"

namespace ZBase {
void initGlobalIdentifier()
{
    ZCodeParse::registerIdentifier("console", new ZSharedVariant(new ZConsole));
    ZCodeParse::registerIdentifier("sys", new ZSharedVariant(new ZSystem));
}
}
