/*
 * Copyright (C) KolibriOS team 2021-2024. All rights reserved.
 * Distributed under terms of the GNU General Public License
 */

#ifndef _ERRNO_H_
#define _ERRNO_H_

#include <stddef.h>

#ifdef _BUILD_LIBC
extern int __errno;
#define errno __errno
#else
extern int* __errno;
#define errno *__errno
#endif

#define ENOTSUP   2  // Function is not supported
#define EUNKNFS   3  // Unknown file system
#define ENOTFOUND 5  // File not found
#define EEOF      6  // End of file
#define EFAULT    7  // Pointer lies outside of application memory
#define EDQUOT    8  // Disk is full
#define EFS       9  // File system error
#define EACCES    10 // Access denied
#define EDEV      11 // Device error
#define ENOMEMFS  12 // File system requires more memory

#define ENOMEM   30 // Not enough memory
#define ENOEXEC  31 // Is not executable
#define EPROCLIM 32 // Too many processes
#define EINVAL   33 // Invalid argument

#define EDOM   50 // Numerical argument out of domain
#define ERANGE 51 // Result too large
#define EILSEQ 52 // Illegal byte sequence

/*
 * UNIX-like errno
 */
#define ENOTDIR   80
#define EBADF     81
#define EIO       82
#define EISDIR    83
#define ENOENT    84
#define EOVERFLOW 85
#define EMFILE    86
#define EEXIST    87

#endif // _ERRNO_H_
