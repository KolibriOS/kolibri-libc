#include <ctype.h>

int isalnum(int c)
{
    return __is[c + 1] & __ALNUM;
}
