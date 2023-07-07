#include <ctype.h>

int iscntrl(int c)
{
    return __is[c + 1] & __CNTRL;
}
