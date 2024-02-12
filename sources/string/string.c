/*
 * Copyright (C) 1994-1995 DJ Delorie, see COPYING.DJ for details
 * Copyright (C) KolibriOS team 2024. All rights reserved.
 * Distributed under terms of the GNU General Public License
 */

#include <stddef.h>
#include <string.h>
#include <errno.h>

#ifndef unconst
#define unconst(__v, __t) __extension__({union { const __t __cp; __t __p; } __q; __q.__cp = __v; __q.__p; })
#endif

DLLAPI void *memcpy(void *dest, const void *src, size_t n)
{
    int d0, d1, d2;
    __asm__ __volatile__(
        "rep ; movsl\n\t"
        "testb $2,%b4\n\t"
        "je 1f\n\t"
        "movsw\n"
        "1:\ttestb $1,%b4\n\t"
        "je 2f\n\t"
        "movsb\n"
        "2:"
        : "=&c"(d0), "=&D"(d1), "=&S"(d2)
        : "0"(n / 4), "q"(n), "1"((long)dest), "2"((long)src)
        : "memory");
    return (dest);
}

DLLAPI char *strcpy(char *to, const char *from)
{
    int d0, d1, d2;
    __asm__ __volatile__(
        "1:\tlodsb\n\t"
        "stosb\n\t"
        "testb %%al,%%al\n\t"
        "jne 1b"
        : "=&S"(d0), "=&D"(d1), "=&a"(d2)
        : "0"(from), "1"(to)
        : "memory");
    return to;
}

DLLAPI char *strncpy(char *dst, const char *src, size_t n)
{
    int d0, d1, d2, d3;
    __asm__ __volatile__(
        "1:\tdecl %2\n\t"
        "js 2f\n\t"
        "lodsb\n\t"
        "stosb\n\t"
        "testb %%al,%%al\n\t"
        "jne 1b\n\t"
        "rep\n\t"
        "stosb\n"
        "2:"
        : "=&S"(d0), "=&D"(d1), "=&c"(d2), "=&a"(d3)
        : "0"(src), "1"(dst), "2"(n)
        : "memory");
    return dst;
}

DLLAPI char *strcat(char *s, const char *append)
{
    int d0, d1, d2, d3;
    __asm__ __volatile__(
        "repne\n\t"
        "scasb\n\t"
        "decl %1\n"
        "1:\tlodsb\n\t"
        "stosb\n\t"
        "testb %%al,%%al\n\t"
        "jne 1b"
        : "=&S"(d0), "=&D"(d1), "=&a"(d2), "=&c"(d3)
        : "0"(append), "1"(s), "2"(0), "3"(0xffffffff)
        : "memory");
    return s;
}

DLLAPI char *strncat(char *dst, const char *src, size_t n)
{
    int d0, d1, d2, d3;
    __asm__ __volatile__(
        "repne\n\t"
        "scasb\n\t"
        "decl %1\n\t"
        "movl %8,%3\n"
        "1:\tdecl %3\n\t"
        "js 2f\n\t"
        "lodsb\n\t"
        "stosb\n\t"
        "testb %%al,%%al\n\t"
        "jne 1b\n"
        "2:\txorl %2,%2\n\t"
        "stosb"
        : "=&S"(d0), "=&D"(d1), "=&a"(d2), "=&c"(d3)
        : "0"(src), "1"(dst), "2"(0), "3"(0xffffffff), "g"(n)
        : "memory");
    return dst;
}

size_t strlen(const char *str)
{
    int d0;
    register int __res;
    __asm__ __volatile__(
        "repne\n\t"
        "scasb\n\t"
        "notl %0\n\t"
        "decl %0"
        : "=c"(__res), "=&D"(d0)
        : "1"(str), "a"(0), "0"(0xffffffff));
    return __res;
}

DLLAPI size_t strxfrm(char *dst, const char *src, size_t n)
{
    size_t r = 0;
    int c;

    if (n != 0) {
        while ((c = *src++) != 0) {
            r++;
            if (--n == 0) {
                while (*src++ != 0)
                    r++;
                break;
            }
            *dst++ = c;
        }
        *dst = 0;
    }

    return r;
}

DLLAPI int memcmp(const void *s1, const void *s2, size_t n)
{
    if (n != 0) {
        const unsigned char *p1 = s1, *p2 = s2;
        do {
            if (*p1++ != *p2++)
                return (*--p1 - *--p2);
        } while (--n != 0);
    }
    return 0;
}

DLLAPI int strcmp(const char *s1, const char *s2)
{
    int d0, d1;
    register int res;
    __asm__ __volatile__(
        "1:\tlodsb\n\t"
        "scasb\n\t"
        "jne 2f\n\t"
        "testb %%al,%%al\n\t"
        "jne 1b\n\t"
        "xorl %%eax,%%eax\n\t"
        "jmp 3f\n"
        "2:\tsbbl %%eax,%%eax\n\t"
        "orb $1,%%al\n"
        "3:"
        : "=a"(res), "=&S"(d0), "=&D"(d1)
        : "1"(s1), "2"(s2));
    return res;
}

DLLAPI int strncmp(const char *s1, const char *s2, size_t n)
{
    register int res;
    int d0, d1, d2;
    __asm__ __volatile__(
        "1:\tdecl %3\n\t"
        "js 2f\n\t"
        "lodsb\n\t"
        "scasb\n\t"
        "jne 3f\n\t"
        "testb %%al,%%al\n\t"
        "jne 1b\n"
        "2:\txorl %%eax,%%eax\n\t"
        "jmp 4f\n"
        "3:\tsbbl %%eax,%%eax\n\t"
        "orb $1,%%al\n"
        "4:"
        : "=a"(res), "=&S"(d0), "=&D"(d1), "=&c"(d2)
        : "1"(s1), "2"(s2), "3"(n));
    return res;
}

DLLAPI void *memchr(const void *s, int c, size_t n)
{
    int d0;
    register void *res;
    if (!n)
        return NULL;
    __asm__ __volatile__(
        "repne\n\t"
        "scasb\n\t"
        "je 1f\n\t"
        "movl $1,%0\n"
        "1:\tdecl %0"
        : "=D"(res), "=&c"(d0)
        : "a"(c), "0"(s), "1"(n));
    return res;
}

DLLAPI char *strrchr(const char *s, int c)
{
    char cc = c;
    const char *sp = (char *)0;
    while (*s) {
        if (*s == cc)
            sp = s;
        s++;
    }
    if (cc == 0)
        sp = s;
    return unconst(sp, char *);
}

DLLAPI size_t strcspn(const char *s1, const char *s2)
{
    const char *p, *spanp;
    char c, sc;

    for (p = s1;;) {
        c = *p++;
        spanp = s2;
        do {
            if ((sc = *spanp++) == c)
                return p - 1 - s1;
        } while (sc != 0);
    }
}

DLLAPI char *strpbrk(const char *s1, const char *s2)
{
    const char *scanp;
    int c, sc;

    while ((c = *s1++) != 0) {
        for (scanp = s2; (sc = *scanp++) != 0;)
            if (sc == c)
                return unconst(s1 - 1, char *);
    }
    return 0;
}

DLLAPI char *strchr(const char *s, int c)
{
    char cc = c;
    const char *sp = (char *)0;
    while (*s) {
        if (*s == cc)
            sp = s;
        s++;
    }
    if (cc == 0)
        sp = s;
    return unconst(sp, char *);
}

DLLAPI size_t strspn(const char *s1, const char *s2)
{
    const char *p = s1, *spanp;
    char c, sc;

cont:
    c = *p++;
    for (spanp = s2; (sc = *spanp++) != 0;)
        if (sc == c)
            goto cont;
    return (p - 1 - s1);
}

DLLAPI char *strstr(const char *s, const char *find)
{
    char c, sc;
    size_t len;

    if ((c = *find++) != 0) {
        len = strlen(find);
        do {
            do {
                if ((sc = *s++) == 0)
                    return 0;
            } while (sc != c);
        } while (strncmp(s, find, len) != 0);
        s--;
    }
    return unconst(s, char *);
}

DLLAPI char *strtok(char *s, const char *delim)
{
    const char *spanp;
    int c, sc;
    char *tok;
    static char *last;

    if (s == NULL && (s = last) == NULL)
        return (NULL);

    /*
     * Skip (span) leading delimiters (s += strspn(s, delim), sort of).
     */
cont:
    c = *s++;
    for (spanp = delim; (sc = *spanp++) != 0;) {
        if (c == sc)
            goto cont;
    }

    if (c == 0) { /* no non-delimiter characters */
        last = NULL;
        return (NULL);
    }
    tok = s - 1;

    /*
     * Scan token (scan for delimiters: s += strcspn(s, delim), sort of).
     * Note that delim must have one NUL; we stop if we see that, too.
     */
    for (;;) {
        c = *s++;
        spanp = delim;
        do {
            if ((sc = *spanp++) == c) {
                if (c == 0)
                    s = NULL;
                else
                    s[-1] = 0;
                last = s;
                return (tok);
            }
        } while (sc != 0);
    }
}

DLLAPI char *strerror(int err)
{
    char *msg;
    switch (err) {
    case 0:
        msg = "No errors";
        break;
    case EDOM:
        msg = "Numerical argument out of domain";
        break;
    case ERANGE:
        msg = "Result too large";
        break;
    default:
        msg = "Unknown error";
        break;
    }
    return msg;
}
