/*
 * Copyright (c) Byteduck 2016-2020. All rights reserved.
 * Copyright (C) KolibriOS team 2024. All rights reserved.
 * Distributed under terms of the GNU General Public License
*/

#include <ctype.h>

static const char __ctype[256] = {
    _C, _C, _C, _C, _C, _C, _C, _C,
    _C, _C | _S, _C | _S, _C | _S, _C | _S, _C | _S, _C, _C,
    _C, _C, _C, _C, _C, _C, _C, _C,
    _C, _C, _C, _C, _C, _C, _C, _C,
    (char)(_S | _B), _P, _P, _P, _P, _P, _P, _P,
    _P, _P, _P, _P, _P, _P, _P, _P,
    _N, _N, _N, _N, _N, _N, _N, _N,
    _N, _N, _P, _P, _P, _P, _P, _P,
    _P, _U | _X, _U | _X, _U | _X, _U | _X, _U | _X, _U | _X, _U,
    _U, _U, _U, _U, _U, _U, _U, _U,
    _U, _U, _U, _U, _U, _U, _U, _U,
    _U, _U, _U, _P, _P, _P, _P, _P,
    _P, _L | _X, _L | _X, _L | _X, _L | _X, _L | _X, _L | _X, _L,
    _L, _L, _L, _L, _L, _L, _L, _L,
    _L, _L, _L, _L, _L, _L, _L, _L,
    _L, _L, _L, _P, _P, _P, _P, _C
};

int isalnum(int c)
{
    return __ctype[(unsigned char)(c)] & (_U | _L | _N);
}

int isalpha(int c)
{
    return __ctype[(unsigned char)(c)] & (_U | _L);
}

int isblank(int c)
{
    return __ctype[(unsigned char)(c)] & (_B) || (c == '\t');
}

int iscntrl(int c)
{
    return __ctype[(unsigned char)(c)] & (_C);
}

int isdigit(int c)
{
    return __ctype[(unsigned char)(c)] & (_N);
}

int isgraph(int c)
{
    return __ctype[(unsigned char)(c)] & (_P | _U | _L | _N);
}

int islower(int c)
{
    return (__ctype[(unsigned char)(c)] & (_U | _L)) == _L;
}

int isprint(int c)
{
    return __ctype[(unsigned char)(c)] & (_P | _U | _L | _N | _B);
}

int ispunct(int c)
{
    return __ctype[(unsigned char)(c)] & (_P);
}

int isspace(int c)
{
    return __ctype[(unsigned char)(c)] & (_S);
}

int isupper(int c)
{
    return (__ctype[(unsigned char)(c)] & (_U | _L)) == _U;
}

int isxdigit(int c)
{
    return __ctype[(unsigned char)(c)] & (_N | _X);
}

int tolower(int c)
{
    return c >= 'A' && c <= 'Z' ? c | 0x20 : c;
}

int toupper(int c)
{
    return c >= 'a' && c <= 'z' ? c & ~0x20 : c;
}
