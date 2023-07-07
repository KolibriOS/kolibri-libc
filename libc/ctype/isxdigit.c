#include <ctype.h>

int isdigit(int c)
{
    return __is[c + 1] & __XDIGIT;
}
