/*
 * Copyright (C) KolibriOS team 2021-2024. All rights reserved.
 * Distributed under terms of the GNU General Public License
 */

#ifndef _STRING_H_
#define _STRING_H_

#include <stddef.h>

/* Memory manipulation */
DLLAPI void *memcpy(void *dest, const void *src, size_t n);
DLLAPI void *memmove(void *dest, const void *src, size_t n);
DLLAPI void *memset(void *dest, int c, size_t n);

/* String manipulation */
DLLAPI char *strcpy(char *dest, const char *src);
DLLAPI char *strncpy(char *dest, const char *src, size_t n);
DLLAPI char *strcat(char *dest, const char *src);
DLLAPI char *strncat(char *dest, const char *src, size_t n);
DLLAPI size_t strxfrm(char *dest, const char *src, size_t n);

/* Comparison */
DLLAPI int memcmp(const void *a, const void *b, size_t n);
DLLAPI int strcmp(const char *s1, const char *s2);
#define strcoll(s1, s2) strcmp(s1, s2)
DLLAPI int strncmp(const char *s1, const char *s2, size_t n);

/* Search */
DLLAPI void *memchr(const void *s, int c, size_t n);
DLLAPI char *strchr(const char *s, int c);
DLLAPI size_t strcspn(const char *s1, const char *s2);
DLLAPI char *strpbrk(const char *s1, const char *s2);
DLLAPI char *strrchr(const char *s, int c);
DLLAPI size_t strspn(const char *s1, const char *s2);
DLLAPI char *strstr(const char *s1, const char *s2);
DLLAPI char *strtok(char *s1, const char *s2);

/* Misc */
DLLAPI char *strerror(int errnum);
DLLAPI size_t strlen(const char *s);

#endif // _STRING_H_
