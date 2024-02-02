/*
 * Copyright (C) KolibriOS team 2024. All rights reserved.
 * Distributed under terms of the GNU General Public License
 */

#include <sys/ksys.h>

#include "string/string.c"

#undef EXPORT
#define EXPORT(sym) {#sym, &sym}

__asm__(
    ".include \"string/string.s\"\n\t"
);

ksys_dll_t EXPORTS[] = {
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
    EXPORT(strcoll),
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
