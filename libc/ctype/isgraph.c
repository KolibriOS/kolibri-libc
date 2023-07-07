#include <ctype.h>

int isgraph(int c)
{
    return __is[c + 1] & __GRAPH;
}
