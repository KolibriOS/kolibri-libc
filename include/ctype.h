/*
 * Copyright (c) Byteduck 2016-2020. All rights reserved.
 * Copyright (C) KolibriOS team 2024. All rights reserved.
 * Distributed under terms of the GNU General Public License
 */

#ifndef _CTYPE_H_
#define _CTYPE_H_

#include <stddef.h>

#define _U 01
#define _L 02
#define _N 04
#define _S 010
#define _P 020
#define _C 040
#define _X 0100
#define _B 0200

DLLAPI int isalnum(int c);
DLLAPI int isalpha(int c);
DLLAPI int isblank(int c);
DLLAPI int iscntrl(int c);
DLLAPI int isdigit(int c);
DLLAPI int isgraph(int c);
DLLAPI int islower(int c);
DLLAPI int isprint(int c);
DLLAPI int ispunct(int c);
DLLAPI int isspace(int c);
DLLAPI int isupper(int c);
DLLAPI int isxdigit(int c);
DLLAPI int tolower(int c);
DLLAPI int toupper(int c);

#endif // _CTYPE_H_
