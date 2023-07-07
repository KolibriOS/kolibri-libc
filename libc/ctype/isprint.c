#include <ctype.h>

int isprint(int c)
{
    return __is[c + 1] & __PRINT;
}
