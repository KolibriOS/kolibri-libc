/*
 * Copyright (C) KolibriOS team 2021-2024. All rights reserved.
 * Distributed under terms of the GNU General Public License
 */

#ifndef _ASSERT_H_
#define _ASSERT_H_

#include <stdlib.h>

#ifdef NDEBUG
#define assert(x) (void)0
#else
DLLAPI void __assert_fail(const char *expr, const char *file, int line, const char *func);
#define assert(x) ((void)((x) || (__assert_fail(#x, __FILE__, __LINE__, __func__), 0)))
#endif

#endif // _ASSERT_H_
