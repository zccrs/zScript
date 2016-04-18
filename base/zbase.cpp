#include "zbase.h"
#include "zcode.h"
#include "zconsole.h"
#include "zsystem.h"

namespace ZBase {
void initGlobalIdentifier()
{
    ZCodeParse::registerIdentifier("console", new ZVariant(new ZConsole));
    ZCodeParse::registerIdentifier("sys", new ZVariant(new ZSystem));
}
}
