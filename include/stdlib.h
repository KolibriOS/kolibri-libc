/*
 * Copyright (C) KolibriOS team 2021-2024. All rights reserved.
 * Distributed under terms of the GNU General Public License
 */

#ifndef _STDLIB_H_
#define _STDLIB_H_

#include <stddef.h>
#include <limits.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define MB_CUR_MAX   1
#define RAND_MAX     INT_MAX

/*
 * Max and Min
 * This is not defined by the ANSI C standard
 */
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

/* String conversion function */
DLLAPI int atoi(const char *nptr);
DLLAPI long int atol(const char *nptr);
DLLAPI double strtod(const char *nptr, char **endptr);
DLLAPI long int strtol(const char *nptr, char **endptr, int base);
DLLAPI unsigned long int strtoul(const char *nptr, char **endptr, int base);

/* Pseudo random sequence generation function */
DLLAPI int rand();
DLLAPI void srand(unsigned int seed);

/* Memory management functions */
DLLAPI void *malloc(size_t size);
DLLAPI void *calloc(size_t num, size_t size);
DLLAPI void *realloc(void *ptr, size_t newsize);
DLLAPI void free(void *ptr);

/* Communication with the environment */
DLLAPI void abort();
DLLAPI void exit(int status);
DLLAPI int atexit(void (*func)(void));
DLLAPI char *getenv(const char *name);
DLLAPI int system(const char *string);

/* Searching and sorting utilities */
DLLAPI void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
DLLAPI void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));

/* Integer arithmetic */
DLLAPI int abs(int j);
DLLAPI long int labs(long int j);

typedef struct {
    int quot;
    int rem;
} div_t;

DLLAPI div_t div(int numer, int denom);

typedef struct {
    long int quot;
    long int rem;
} ldiv_t;

DLLAPI ldiv_t ldiv(long int numer, long int denom);

#endif // _STDLIB_H_
