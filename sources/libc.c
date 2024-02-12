/*
 * Copyright (C) KolibriOS team 2024. All rights reserved.
 * Distributed under terms of the GNU General Public License
 */

#include <setjmp.h>
#include <sys/ksys.h>

#include "string/string.c"

#undef EXPORT
#define EXPORT(sym) {#sym, &sym}

__asm__(
    ".include \"setjmp.s\"\n\t"
    ".include \"string/string.s\"\n\t"
);

ksys_dll_t EXPORTS[] = {
    /* setjmp.h */
    EXPORT(setjmp),
    EXPORT(longjmp),
    /* string.h */
    EXPORT(memcpy),
    EXPORT(memmove),
    EXPORT(memset),
    EXPORT(strcpy),
    EXPORT(strncpy),
    EXPORT(strcat),
    EXPORT(strncat),
    EXPORT(strxfrm),
    EXPORT(memcmp),
    EXPORT(strcmp),
    EXPORT(strncmp),
    EXPORT(memchr),
    EXPORT(strchr),
    EXPORT(strcspn),
    EXPORT(strpbrk),
    EXPORT(strrchr),
    EXPORT(strspn),
    EXPORT(strstr),
    EXPORT(strtok),
    NULL
};
