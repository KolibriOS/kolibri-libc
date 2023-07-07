#include <ctype.h>

int islower(int c)
{
    return __is[c + 1] & __LOWER;
}
