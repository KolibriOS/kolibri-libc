#include <ctype.h>

int isalpha(int c)
{
    return __is[c + 1] & __ALPHA;
}
