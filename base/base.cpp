#include "base.h"
#include "zcode.h"

#include "zconsole.h"

namespace Base {
void initGlobalIdentifier()
{
    ZCode::registerIdentifier("console", new ZVariant(new ZConsole));
}
}
