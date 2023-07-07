#include <ctype.h>

int ispunct(int c)
{
    return __is[c + 1] & __PUNCT;
}
