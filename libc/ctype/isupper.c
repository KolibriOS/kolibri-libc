#include <ctype.h>

int isupper(int c)
{
    return __is[c + 1] & __UPPER;
}
