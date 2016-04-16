#include "ztool.h"

ZTool::ZTool(ZObject *parent)
    : ZObject(parent)
{

}

char ZTool::charToEscape(char ch)
{
    switch (ch) {
    case 'a':
        return '\a';
    case 'b':
        return '\b';
    case 'f':
        return 'f';
    case 'n':
        return '\n';
    case 'r':
        return '\r';
    case 't':
        return '\t';
    case 'v':
        return '\v';
    case '0':
        return '\0';
    default:
        return ch;
    }
}
