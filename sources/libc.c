/*
 * Copyright (C) KolibriOS team 2024. All rights reserved.
 * Distributed under terms of the GNU General Public License
 */

static int __errno;

#include <setjmp.h>
#include <stddef.h>
#include <sys/ksys.h>

#include "ctype.c"
#include "string/string.c"
#include "stdlib/strtod.c"
#include "stdlib/strtol.c"
#include "stdlib/strtoul.c"

#undef EXPORT
#define EXPORT(sym) {#sym, &sym}

__asm__(
    ".include \"setjmp.s\"\n\t"
    ".include \"string/memmove.s\"\n\t"
    ".include \"string/memset.s\"\n\t"
);

ksys_dll_t EXPORTS[] = {
    /* errno.h */
    EXPORT(__errno),
    /* ctype.h */
    EXPORT(isalnum),
    EXPORT(isalpha),
    EXPORT(isblank),
    EXPORT(iscntrl),
    EXPORT(isdigit),
    EXPORT(isgraph),
    EXPORT(islower),
    EXPORT(isprint),
    EXPORT(ispunct),
    EXPORT(isspace),
    EXPORT(isupper),
    EXPORT(isxdigit),
    EXPORT(tolower),
    EXPORT(toupper),
    /* setjmp.h */
    EXPORT(setjmp),
    EXPORT(longjmp),
    /* stdlib.h */
    EXPORT(strtod),
    EXPORT(strtol),
    EXPORT(strtoul),
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
