#include <ctype.h>

int isspace(int c)
{
    return __is[c + 1] & __BLANK;
}
