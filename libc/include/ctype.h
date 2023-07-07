#ifndef _CTYPE_H_
#define _CTYPE_H_

#include <stddef.h>

#define __ALNUM  1
#define __ALPHA  2
#define __CNTRL  4
#define __DIGIT  8
#define __GRAPH  16
#define __LOWER  32
#define __PRINT  64
#define __PUNCT  128
#define __BLANK  256
#define __UPPER  512
#define __XDIGIT 1024

extern const unsigned short __is[129];

DLLAPI int isalnum(int c);  /* 'a'-'z', 'A'-'Z', '0'-'9' */
DLLAPI int isalpha(int c);  /* 'a'-'z', 'A'-'Z' */
DLLAPI int iscntrl(int c);  /* 0-31, 127 */
DLLAPI int isdigit(int c);  /* '0'-'9' */
DLLAPI int isgraph(int c);  /* '!'-'~' */
DLLAPI int islower(int c);  /* 'a'-'z' */
DLLAPI int isprint(int c);  /* ' '-'~' */
DLLAPI int ispunct(int c);  /* !alnum && !cntrl && !space */
DLLAPI int isspace(int c);  /* HT, LF, VT, FF, CR, ' ' */
DLLAPI int isupper(int c);  /* 'A'-'Z' */
DLLAPI int isxdigit(int c); /* '0'-'9', 'a'-'f', 'A'-'F' */
DLLAPI int tolower(int c);  /* return lower-case equivalent */
DLLAPI int toupper(int c);  /* return upper-case equivalent */

#define isascii(c) (!((c) & (~0x7f))) /* is ASCII character */
#define toascii(c) ((c) & 0x7f)       /* converts a value to an ASCII range */

#endif
