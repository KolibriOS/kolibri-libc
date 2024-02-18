/*
 * Copyright (C) KolibriOS team 2022-2024. All rights reserved.
 * Distributed under terms of the GNU General Public License
 */

#include <ctype.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>

#include "unconst.h"

double strtod(const char *s, char **sret)
{
    long double r; /* result */
    int e;         /* exponent */
    long double d; /* scale */
    int sign;      /* +- 1.0 */
    int esign;
    int i;
    int flags = 0;

    r = 0.0;
    sign = 1.0;
    e = 0;
    esign = 1;

    while ((*s == ' ') || (*s == '\t'))
        s++;

    if (*s == '+')
        s++;
    else if (*s == '-') {
        sign = -1;
        s++;
    }

    while ((*s >= '0') && (*s <= '9')) {
        flags |= 1;
        r *= 10.0;
        r += *s - '0';
        s++;
    }

    if (*s == '.') {
        d = 0.1L;
        s++;
        while ((*s >= '0') && (*s <= '9')) {
            flags |= 2;
            r += d * (*s - '0');
            s++;
            d *= 0.1L;
        }
    }

    if (flags == 0) {
        if (sret)
            *sret = unconst(s, char *);
        return 0;
    }

    if ((*s == 'e') || (*s == 'E')) {
        s++;
        if (*s == '+')
            s++;
        else if (*s == '-') {
            s++;
            esign = -1;
        }
        if ((*s < '0') || (*s > '9')) {
            if (sret)
                *sret = unconst(s, char *);
            return r;
        }

        while ((*s >= '0') && (*s <= '9')) {
            e *= 10;
            e += *s - '0';
            s++;
        }
    }

    if (esign < 0)
        for (i = 1; i <= e; i++)
            r *= 0.1L;
    else
        for (i = 1; i <= e; i++)
            r *= 10.0;

    if (sret)
        *sret = unconst(s, char *);
    return r * sign;
}

long strtol(const char *nptr, char **endptr, int base)
{
    const char *s = nptr;
    unsigned long acc;
    int c;
    unsigned long cutoff;
    int neg = 0, any, cutlim;

    /*
     * Skip white space and pick up leading +/- sign if any.
     * If base is 0, allow 0x for hex and 0 for octal, else
     * assume decimal; if base is already 16, allow 0x.
     */
    do {
        c = *s++;
    } while (isspace(c));
    if (c == '-') {
        neg = 1;
        c = *s++;
    } else if (c == '+')
        c = *s++;
    if ((base == 0 || base == 16) && c == '0' && (*s == 'x' || *s == 'X')) {
        c = s[1];
        s += 2;
        base = 16;
    }
    if (base == 0)
        base = c == '0' ? 8 : 10;

    /*
     * Compute the cutoff value between legal numbers and illegal
     * numbers.  That is the largest legal value, divided by the
     * base.  An input number that is greater than this value, if
     * followed by a legal input character, is too big.  One that
     * is equal to this value may be valid or not; the limit
     * between valid and invalid numbers is then based on the last
     * digit.  For instance, if the range for longs is
     * [-2147483648..2147483647] and the input base is 10,
     * cutoff will be set to 214748364 and cutlim to either
     * 7 (neg==0) or 8 (neg==1), meaning that if we have accumulated
     * a value > 214748364, or equal but the next digit is > 7 (or 8),
     * the number is too big, and we will return a range error.
     *
     * Set any if any `digits' consumed; make it negative to indicate
     * overflow.
     */
    cutoff = neg ? -(unsigned long)LONG_MIN : LONG_MAX;
    cutlim = cutoff % (unsigned long)base;
    cutoff /= (unsigned long)base;
    for (acc = 0, any = 0;; c = *s++) {
        if (isdigit(c))
            c -= '0';
        else if (isalpha(c))
            c -= isupper(c) ? 'A' - 10 : 'a' - 10;
        else
            break;
        if (c >= base)
            break;
        if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
            any = -1;
        else {
            any = 1;
            acc *= base;
            acc += c;
        }
    }
    if (any < 0) {
        acc = neg ? LONG_MIN : LONG_MAX;
        errno = ERANGE;
    } else if (neg)
        acc = -acc;
    if (endptr != 0)
        *endptr = any ? unconst(s, char *) - 1 : unconst(nptr, char *);
    return acc;
}

/*
 * Convert a string to an unsigned long integer.
 *
 * Ignores `locale' stuff.  Assumes that the upper and lower case
 * alphabets and digits are each contiguous.
 */
unsigned long strtoul(const char *nptr, char **endptr, int base)
{
    const char *s = nptr;
    unsigned long acc;
    int c;
    unsigned long cutoff;
    int neg = 0, any, cutlim;

    /*
     * See strtol for comments as to the logic used.
     */
    do {
        c = *s++;
    } while (isspace(c));
    if (c == '-') {
        neg = 1;
        c = *s++;
    } else if (c == '+')
        c = *s++;
    if ((base == 0 || base == 16) && c == '0' && (*s == 'x' || *s == 'X')) {
        c = s[1];
        s += 2;
        base = 16;
    }
    if (base == 0)
        base = c == '0' ? 8 : 10;
    cutoff = (unsigned long)ULONG_MAX / (unsigned long)base;
    cutlim = (unsigned long)ULONG_MAX % (unsigned long)base;
    for (acc = 0, any = 0;; c = *s++) {
        if (isdigit(c))
            c -= '0';
        else if (isalpha(c))
            c -= isupper(c) ? 'A' - 10 : 'a' - 10;
        else
            break;
        if (c >= base)
            break;
        if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
            any = -1;
        else {
            any = 1;
            acc *= base;
            acc += c;
        }
    }
    if (any < 0) {
        acc = ULONG_MAX;
        errno = ERANGE;
    } else if (neg)
        acc = -acc;
    if (endptr != 0)
        *endptr = any ? unconst(s, char *) - 1 : unconst(nptr, char *);
    return acc;
}

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
