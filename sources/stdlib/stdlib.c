/*
 * Copyright (C) KolibriOS team 2022-2024. All rights reserved.
 * Distributed under terms of the GNU General Public License
 */

#include <ctype.h>
#include <stdlib.h>

double atof(const char *ascii)
{
    return strtod(ascii, 0);
}

int atoi(const char *s)
{
    int sign, n;
    while (isspace(*s))
        ++s;
    sign = 1;

    switch (*s) {
    case '-':
        sign = -1;
    case '+':
        ++s;
    }

    n = 0;
    while (isdigit(*s))
        n = 10 * n + *s++ - '0';
    return (sign * n);
}

long atol(const char *s)
{
    long n = 0;
    int neg = 0;
    while (isspace(*s))
        s++;
    switch (*s) {
    case '-':
        neg = 1;
    case '+':
        s++;
    }
    /* Compute n as a negative number to avoid overflow on LONG_MIN */
    while (isdigit(*s))
        n = 10 * n - (*s++ - '0');
    return neg ? n : -n;
}

static unsigned long long seed;

void srand(unsigned s)
{
    seed = s - 1;
}

int rand(void)
{
    seed = 6364136223846793005ULL * seed + 1;
    return seed >> 33;
}

int abs(int a)
{
    return a > 0 ? a : -a;
}

long labs(long a)
{
    return a > 0 ? a : -a;
}

div_t div(int num, int den)
{
    return (div_t) { num / den, num % den };
}

ldiv_t ldiv(long num, long den)
{
    return (ldiv_t) { num / den, num % den };
}
