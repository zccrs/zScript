#ifndef ZTOOL_H
#define ZTOOL_H

#include "zobject.h"

class ZTool :  public ZObject
{
public:
    explicit ZTool(ZObject *parent);

    static char charToEscape(char ch);
};

#endif // ZTOOL_H
