/*
 * Copyright (C) KolibriOS team 2021-2024. All rights reserved.
 * Distributed under terms of the GNU General Public License
 */

#ifndef _ERRNO_H_
#define _ERRNO_H_

#include <stddef.h>

#ifdef _BUILD_LIBC
static int __errno;
#define errno __errno
#else
extern int *__errno;
#define errno (*__errno)
#endif


#define EDOM   50 // Numerical argument out of domain
#define ERANGE 51 // Result too large

#endif // _ERRNO_H_
