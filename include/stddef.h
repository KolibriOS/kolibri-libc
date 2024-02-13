/*
 * Copyright (C) KolibriOS team 2021-2024. All rights reserved.
 * Distributed under terms of the GNU General Public License
 */

#ifndef _STDDEF_H_
#define _STDDEF_H_

typedef __SIZE_TYPE__ size_t;
typedef __PTRDIFF_TYPE__ ssize_t;
typedef __WCHAR_TYPE__ wchar_t;
typedef __PTRDIFF_TYPE__ ptrdiff_t;
typedef __PTRDIFF_TYPE__ intptr_t;
typedef __SIZE_TYPE__ uintptr_t;

#ifndef NULL
#define NULL ((void *)0)
#endif

#ifdef _BUILD_LIBC
#define DLLAPI static
#else
#define DLLAPI __attribute__((dllimport))
#endif

#define offsetof(type, field) ((size_t) & ((type *)0)->field)

/* Macros for calling conventions */
#ifndef __cdecl
#define __cdecl __attribute__((cdecl))
#endif

#ifndef __stdcall
#define __stdcall __attribute__((stdcall))
#endif

#ifndef __fastcall
#define __fastcall __attribute__((fastcall))
#endif

#ifndef __packed
#define __packed __attribute__((packed))
#endif

#endif // _STDDEF_H_
