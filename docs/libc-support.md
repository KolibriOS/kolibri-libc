### ANSI C Support in KolibriOS
| Name | Description | Support |
|--|--|--|
| **errno.h** |  |  |
| `EDOM`   | Results from a parameter outside a function's domain. | Yes |
| `ERANGE` | Results from a result outside a function's range. | Yes |
| `errno`  | Macro set to indicate what went wrong. | Yes |
| **stddef.h** |  |  |
| `NULL`     | A macro that expands to a null pointer constant. | Yes |
| `offsetof` | A functional macro that is used to determine the byte offset of the indicated member field in the specified structure type. | Yes |
| `ptrdiff_t` | This is the signed integral type and is the result of subtracting two pointers. | Yes |
| `size_t` | This is the unsigned integral type and is the result of the `sizeof` keyword. | Yes |
| `wchar_t` | This is an integral type of the size of a wide character constant. | Yes |
| **assert.h** |  |  |
| `NDEBUG` |  | Yes |
| `assert` | The assert macro returns a void, i.e. no value. | Not implemented |
| **ctype.h** |  |  |
| `isalnum()` | Is character alphanumeric (numbers + letters)? | Yes |
| `isalpha()` | Is character alphabetic (letter)? | Yes |
| `iscntrl()` | Is character a control character? | Yes |
| `isdigit()` | Is character a decimal digit? | Yes |
| `isgraph()` | Is character a printing character (not including space)? | Yes |
| `islower()` | Is character lowercase | Yes |
| `isprint()` | Is character a printing character (including space)? | Yes |
| `ispunct()` | Is character a printing character except space, letter, digit? | Yes |
| `isspace()` | Is character a space, formfeed, newline, cr, tab, vtab? | Yes |
| `isupper()` | Is character an upper case letter? | Yes |
| `isxdigit()` | Is character a hexadecimal digit? | Yes |
| `tolower()` | Convert character to lower case. | Yes |
| `toupper()` | Convert character to upper case. | Yes |
| **locale.h** [^locale_h] |  |  |
| `LC_ALL` | Sets everything. | No |
| `LC_COLLATE` | Affects `strcoll()` and `strxfrm()` functions. | No |
| `LC_CTYPE` | Affects all character functions. | No |
| `LC_MONETARY` | Affects the monetary information provided by localeconv function. | No |
| `LC_NUMERIC` | Affects decimal-point formatting and the information provided by `localeconv()` function. | No |
| `LC_TIME` | Affects the `strftime()` function. | No |
| `NULL` | A macro that expands to a null pointer constant. | No |
| `lconv` | Structure which contains members related to the formatting of numeric values.. | No |
| `setlocale()` | Sets or reads location dependent information. | No |
| `localeconv()` | Sets or reads location dependent information. | No |
| **math.h** |  |  |
| `HUGE_VAL` | This macro is used when the result of a function may not be representable as a floating point number. | Not implemented |
| `acos()` | Returns the arc cosine of x in radians. | Not implemented |
| `asin()` | Returns the arc sine of x in radians. | Not implemented |
| `atan()` | Returns the arc tangent of x in radians. | Not implemented |
| `atan2()` | Returns the arc tangent in radians of y/x based on the signs of both values to determine the correct quadrant. | Not implemented |
| `cos()` | Returns the cosine of a radian angle x. | Not implemented |
| `sin()` | Returns the sine of a radian angle x. | Not implemented |
| `tan()` | Returns the tangent of x. | Not implemented |
| `cosh()` | Returns the hyperbolic cosine of x. | Not implemented |
| `sinh()` | Returns the hyperbolic sine of x. | Not implemented |
| `tanh()` | Returns the hyperbolic tangent of x. | Not implemented |
| `exp()` | Returns the value of e raised to the xth power. | Not implemented |
| `frexp()` | The returned value is the mantissa and the integer pointed to by exponent is the exponent. The resultant value is x = mantissa * 2 ^ exponent. | Not implemented |
| `ldexp()` | Returns x multiplied by 2 raised to the power of exponent. | Not implemented |
| `log()` | Returns the natural logarithm (base-e logarithm) of x. | Not implemented |
| `log10()` | Returns the common logarithm (base-10 logarithm) of x. | Not implemented |
| `modf()` | The returned value is the fraction component (part after the decimal), and sets integer to the integer component. | Not implemented |
| `pow()` | Returns x raised to the power of y. | Not implemented |
| `sqrt()` | Returns the square root of x. | Not implemented |
| `ceil()` | Returns the smallest integer value greater than or equal to x. | Not implemented |
| `fabs()` | Returns the absolute value of x. | Not implemented |
| `floor()` | Returns the largest integer value less than or equal to x. | Not implemented |
| `fmod()` | Returns the remainder of x divided by y. | Not implemented |
| **setjmp.h** |  |  |
| `jmp_buf` | This is an array type used for holding information for macro `setjmp` and function `longjmp()`. | Yes |
| `setjmp` | This macro saves the current environment into the variable environment for later use by the function `longjmp()`. | Yes |
| `longjmp()` | This function restores the environment saved by the most recent call to setjmp() macro in the same invocation of the program with the corresponding jmp_buf argument. | Yes |
| **signal.h**[^signal_h] |  |  |
| `sig_atomic_t` | This is of int type and is used as a variable in a signal handler.  | No |
| `SIG_DFL` | Default signal handler. | No |
| `SIG_ERR` | Represents a signal error. | No |
| `SIG_IGN` | Signal ignore. | No |
| `SIGABRT` | Abnormal program termination. | No |
| `SIGFPE` | Floating-point error like division by zero. | No|
| `SIGILL` | Illegal operation. | No |
| `SIGINT` | Interrupt signal such as ctrl-C. | No |
| `SIGSEGV` | Invalid access to storage like segment violation. | No |
| `SIGTERM` | Termination request. | No |
| `signal()` | This function sets a function to handle signal i.e. a signal handler. | No |
| `raise()` | This function causes signal sig to be generated. The sig argument is compatible with the SIG macros. | No |
| **stdarg.h** |  |  |
| `va_list` | This is a type suitable for holding information needed by the three macros `va_start()`, `va_arg()` and `va_end()`. | Yes |
| `va_start` | This macro initializes ap variable to be used with the `va_arg` and `va_end` macros. | Yes |
| `va_arg` | This macro retrieves the next argument in the parameter list of the function with type type. | Yes |
| `va_end` | This macro allows a function with variable arguments which used the `va_start` macro to return. | Yes |
| **stdio.h** |  |  |
| `_IOFBF` | Macros which expand to integral constant expressions with distinct values. | Yes |
| `_IOLBF` | Macros which expand to integral constant expressions with distinct values. | Yes |
| `_IONBF` | Macros which expand to integral constant expressions with distinct values. | Yes |
| `BUFSIZ` | This macro is an integer, which represents the size of the buffer used by the `setbuf()` function. | Not implemented |
| `EOF` | This macro is a negative integer, which indicates that the end-of-file has been reached. | Yes |
| `FILE` | This is an object type suitable for storing information for a file stream. | Not implemented |
| `FILENAME_MAX` | This macro is an integer, which represents the longest length of a char array suitable for holding the longest possible filename. | Not implemented |
| `FOPEN_MAX` | This macro is an integer, which represents the maximum number of files that the system can guarantee to be opened simultaneously. | Not implemented |
| `fpos_t` | This is an object type suitable for storing any position in a file. | Not implemented |
| `L_tmpnam` | Represents the longest length of a char array suitable for holding the longest possible temporary filename created by the `tmpnam()` function. | Not implemented |
| `NULL` | This macro is the value of a null pointer constant. | Yes |
| `SEEK_CUR` | Macros used in the fseek function to locate different positions in a file. | Not implemented |
| `SEEK_END` | Macros used in the fseek function to locate different positions in a file. | Not implemented |
| `SEEK_SET` | Macros used in the fseek function to locate different positions in a file. | Not implemented |
| `size_t` | This is the unsigned integral type and is the result of the `sizeof` keyword. | Yes |
| `stderr` | Macros pointer to `FILE` types which correspond to the standard error, standard input, and standard output streams. | Not implemented |
| `stdin` | Macros pointer to `FILE` types which correspond to the standard error, standard input, and standard output streams. | Not implemented |
| `stdout` | Macros pointer to `FILE` types which correspond to the standard error, standard input, and standard output streams. | Not implemented |
| `TMP_MAX` | This macro is the maximum number of unique filenames that the function tmpnam can generate. | Not implemented |
| `remove()` | Deletes the given filename so that it is no longer accessible. | Not implemented |
| `rename()` | Causes the filename referred to, by old_filename to be changed to new_filename. | Not implemented |
| `tmpfile()` | Creates a temporary file in binary update mode (wb+). | Not implemented |
| `tmpnam()` | Generates and returns a valid temporary filename which does not exist. | Not implemented |
| `fclose()` | Closes the stream. All buffers are flushed. | Not implemented |
| `fflush()` | Flushes the output buffer of a stream. | Not implemented |
| `fopen()` | Opens the filename pointed to by filename using the given mode. | Not implemented |
| `freopen()` | Associates a new filename with the given open stream and same time closing the old file in stream. | Not implemented |
| `setbuf()` | Defines how a stream should be buffered. | Not implemented |
| `setvbuf()` | Another function to define how a stream should be buffered. | Not implemented |
| `fprintf()` | Sends formatted output to a stream. | Not implemented |
| `fscanf()` | Reads formatted input from a stream. | Not implemented |
| `printf()` | Sends formatted output to stdout. | Not implemented |
| `scanf()` | Reads formatted input from stdin. | Not implemented |
| `sprintf()` | Sends formatted input to string. | Not implemented |
| `sscanf()` | Reads formatted input from a string. | Not implemented |
| `vfprintf()` | Sends formatted output to a stream using an argument list. | Not implemented |
| `vprintf()` | Sends formatted output to stdout using an argument list. | Not implemented |
| `vsprintf()` | Sends formatted output to a string using an argument list. | Not implemented |
| `fgetc()` | Gets the next character (an unsigned char) from the specified stream and advances the position indicator for the stream. | Not implemented |
| `fgets()` | Reads a line from the specified stream and stores it into the string pointed to by str. | Not implemented |
| `fputc()` | Writes a character (an unsigned char) specified by the argument char to the specified stream and advances the position indicator for the stream. | Not implemented |
| `fputs()` | Writes a string to the specified stream up to but not including the null character. | Not implemented |
| `getc()` | Gets the next character (an unsigned char) from the specified stream and advances the position indicator for the stream. | Not implemented |
| `getchar()` | Gets a character (an unsigned char) from stdin. | Not implemented |
| `gets()` | Reads a line from stdin and stores it into the string pointed to by, str. | Not implemented |
| `putc()` | Writes a character (an unsigned char) specified by the argument char to the specified stream and advances the position indicator for the stream. | Not implemented |
| `putchar()` | Writes a character (an unsigned char) specified by the argument char to stdout. | Not implemented |
| `puts()` | Writes a string to stdout up to but not including the null character. A newline character is appended to the output. | Not implemented |
| `ungetc()` | Pushes the character char (an unsigned char) onto the specified stream so that the next character is read. | Not implemented |
| `fread()` | Reads data from the given stream into the array pointed to by ptr. | Not implemented |
| `fwrite()` | Writes data from the array pointed to by ptr to the given stream. | Not implemented |
| `fgetpos()` | Gets the current file position of the stream and writes it to pos. | Not implemented |
| `fseek()` | Sets the file position of the stream to the given offset. The argument offset signifies the number of bytes to seek from the given whence position. | Not implemented |
| `fsetpos()` | Sets the file position of the given stream to the given position. The argument pos is a position given by the function fgetpos. | Not implemented |
| `ftell()` | Returns the current file position of the given stream. | Not implemented |
| `rewind()` | Sets the file position to the beginning of the file of the given stream. | Not implemented |
| `clearerr()` | Clears the end-of-file and error indicators for the given stream. | Not implemented |
| `feof()` | Tests the end-of-file indicator for the given stream. | Not implemented |
| `ferror()` | Tests the error indicator for the given stream. | Not implemented |
| `perror()` | Prints a descriptive error message to stderr. First the string str is printed followed by a colon and then a space. | Not implemented |
| **stdlib.h** |  |  |
| `EXIT_FAILURE` | This is the value for the exit function to return in case of failure. | Yes |
| `EXIT_SUCCESS` | This is the value for the exit function to return in case of success. | Yes |
| `MB_CUR_MAX` | This macro is the maximum number of bytes in a multi-byte character set which cannot be larger than `MB_LEN_MAX`. | Yes |
| `NULL` | This macro is the value of a null pointer constant. | Yes |
| `RAND_MAX` | This macro is the maximum value returned by the `rand()` function. | Yes |
| `div_t` | This is the structure returned by the div function. | Yes |
| `ldiv_t` | This is the structure returned by the ldiv function. | Yes |
| `size_t` | This is the unsigned integral type and is the result of the sizeof keyword. | Yes |
| `wchar_t` | This is an integer type of the size of a wide character constant. | Yes |
| `atof()` | Converts the string pointed to, by the argument str to a floating-point number (type double). | Not implemented |
| `atoi()` | Converts the string pointed to, by the argument str to an integer (type int). | Not implemented |
| `atol()` | Converts the string pointed to, by the argument str to a long integer (type long int). | Not implemented |
| `strtod()` | Converts the string pointed to, by the argument str to a floating-point number (type double). | Yes |
| `strtol()` | Converts the string pointed to, by the argument str to a long integer (type long int). | Yes |
| `strtoul()` | Converts the string pointed to, by the argument str to an unsigned long integer (type unsigned long int). | Yes |
| `rand()` | Returns a pseudo-random number in the range of 0 to `RAND_MAX`. | Not implemented |
| `srand()` | This function seeds the random number generator used by the function rand. | Not implemented |
| `calloc()` | Allocates the requested memory and returns a pointer to it. | Not implemented |
| `free()` | Deallocates the memory previously allocated by a call to calloc, malloc, or realloc. | Not implemented |
| `malloc()` | Allocates the requested memory and returns a pointer to it. | Not implemented |
| `realloc()` | Attempts to resize the memory block pointed to by ptr that was previously allocated with a call to malloc or calloc. | Not implemented |
| `abort()` | Causes an abnormal program termination. | Not implemented |
| `atexit()` | Causes the specified function to be called when the program terminates normally. | Not implemented |
| `exit()` | Causes the program to terminate normally. | Not implemented |
| `getenv()` | Searches for the environment string pointed to by name and returns the associated value to the string. | Not implemented |
| `system()` | The command specified by string is passed to the host environment to be executed by the command processor. | Not implemented |
| `bsearch()` | Performs a binary search. | Not implemented |
| `qsort()` | Sorts an array. | Not implemented |
| `abs()` | Returns the absolute value of x. | Not implemented |
| `div()` | Divides numerator by denominator. | Not implemented |
| `labs()` | Returns the absolute value of x. | Not implemented |
| `ldiv()` | Divides `long` numerator by denominator. | Not implemented |
| `mblen()` | Returns the length of a multibyte character pointed to by the argument str. | Not implemented |
| `mbtowc()` | Examines the multibyte character pointed to by the argument str. | Not implemented |
| `wctomb()` | Examines the code which corresponds to a multibyte character given by the argument wchar. | Not implemented |
| `mbstowcs()` | Converts the string of multibyte characters pointed to by the argument str to the array pointed to by pwcs. | Not implemented |
| `wcstombs()` | Converts the codes stored in the array pwcs to multibyte characters and stores them in the string str. | Not implemented |
| **string.h** |  |  |
| `NULL` | This macro is the value of a null pointer constant. | Yes |
| `size_t` | This is the unsigned integral type and is the result of the `sizeof` keyword. | Yes |
| `memcpy()` | Copies n characters from src to dest. | Yes |
| `memmove()` | Another function to copy n characters from str2 to str1. | Yes |
| `strcpy()` | Copies the string pointed to, from source to destination. | Yes |
| `strncpy()` | Copies up to n characters from the string pointed to, from source to destination. | Yes |
| `strcat()` | Appends the string pointed to, by src to the end of the string pointed to by dest. | Yes |
| `strncat()` | Appends the string pointed to, by src to the end of the string pointed to, by dest up to n characters long. | Yes |
| `memcmp()` | Compares the first n bytes of str1 and str2. | Yes |
| `strcmp()` | Compares the string pointed to, by str1 to the string pointed to by str2. | Yes |
| `strcoll()` | Compares string str1 to str2. The result is dependent on the `LC_COLLATE` setting of the location. | Yes[^strcoll] |
| `strncmp()` | Compares at most the first n bytes of str1 and str2. | Yes |
| `strxfrm()` | Transforms the first n characters of the string src into current locale and places them in the string dest. | Yes |
| `memchr()` | Searches for the first occurrence of the character c (an unsigned char) in the first n bytes of the string pointed to, by the argument str. | Yes |
| `strchr()` | Searches for the first occurrence of the character c (an unsigned char) in the string pointed to, by the argument str. | Yes |
| `strcspn()` | Calculates the length of the initial segment of str1 which consists entirely of characters not in str2. | Yes |
| `strpbrk()` | Finds the first character in the string str1 that matches any character specified in str2. | Yes |
| `strrchr()` | Searches for the last occurrence of the character c (an unsigned char) in the string pointed to by the argument str. | Yes |
| `strspn()` | Calculates the length of the initial segment of str1 which consists entirely of characters in str2. | Yes |
| `strstr()` | Finds the first occurrence of the entire string needle (not including the terminating null character) which appears in the string haystack. | Yes |
| `strtok()` | Breaks string str into a series of tokens separated by delim. | Yes |
| `memset()` | Copies the character c (an unsigned char) to the first n characters of the string pointed to, by the argument str. | Yes |
| `strerror()` | Searches an internal array for the error number errnum and returns a pointer to an error message string. | Yes[^strerror] |
| `strlen()` | Computes the length of the string str up to but not including the terminating null character. | Not implemented |
| **time.h** |  |  |
| `CLK_TCK` | This macro represents the number of processor clocks per second. | Yes |
| `NULL` | This macro is the value of a null pointer constant. | Yes |
| `clock_t` | This is a type suitable for storing the processor time. | Yes |
| `time_t` | This is a type suitable for storing the calendar time. | Yes |
| `size_t` | This is the unsigned integral type and is the result of the `sizeof` keyword. | Yes |
| `tm` | This is a structure used to hold the time and date. | Yes |
| `clock()` | Returns the processor clock time used since the beginning of an implementation defined era (normally the beginning of the program). | Not implemented |
| `difftime()` | Returns the difference of seconds between time1 and time2 (time1-time2). | Not implemented |
| `mktime()` | Converts the structure pointed to by timeptr into a `time_t` value according to the local time zone. | Not implemented |
| `time()` | Calculates the current calender time and encodes it into `time_t` format. | Not implemented |
| `asctime()` | Returns a pointer to a string which represents the day and time of the structure timeptr. | Not implemented |
| `ctime()` | Returns a string representing the localtime based on the argument timer. | Not implemented |
| `gmtime()` | The value of timer is broken up into the structure tm and expressed in Coordinated Universal Time (UTC) also known as Greenwich Mean Time (GMT). | Not implemented |
| `localtime()` | The value of timer is broken up into the structure tm and expressed in the local time zone. | Not implemented |
| `strftime()` | Formats the time represented in the structure timeptr according to the formatting rules defined in format and stored into str. | Not implemented |

### Codes for Formatted I/O: "%-+ 0w.pmc"

| Code | Desription | Support |
|--|--|--|
| `-` | The result of the conversion will be left-justified within the field. | Not implemented |
| `+` | The result of a signed conversion will always begin with a plus or minus sign. | Not implemented |
| `space` |  If the first character of a signed conversion is not a sign, or if a signed conversion results in no characters, a space will be prepended to the result. If the space and + flags both appear, the space flag will be ignored. | Not implemented |
| `#` | The result is to be converted to an "alternate form". For `o` conversion, it increases the precision to force the first digit of the result to be a zero. For `x`, `X` conversion, a nonzero result will have 0x (or 0X ) prepended to it. For `e` , `E` , `f`, `g` and `G` conversions, the result will always contain a decimal-point character, even if no digits follow it (normally, a decimal-point character appears in the result of these conversions only if a digit follows it). For `g` and `G` conversions, trailing zeros will not be removed from the result. For other conversions, the behavior is undefined. | Not implemented |
| `0` | For `d`, `i`, `o`, `u`, `x`, `X`, `e`, `E`, `f`, `g` and `G` conversions, leading zeros (following any indication of sign or base) are used to pad to the field width; no space padding is performed. If the `0` and `-` flags both appear, the `0` flag will be ignored. For `d`, `i`, `o`, `u`, `x` and `X` conversions, if a precision is specified, the `0` flag will be ignored. For other conversions, the behavior is undefined. | Not implemented |
| `d`, `i`, `o`, `u`, `x`, `X` | The int argument is converted to signed decimal (`d` or `i`), unsigned octal (`o`), unsigned decimal (`u`), or unsigned hexadecimal notation (`x` or `X`); the letters abcdef are used for `x` conversion and the letters ABCDEF for `X` conversion. The precision specifies the minimum number of digits to appear; if the value being converted can be represented in fewer digits, it will be expanded with leading zeros. The default precision is 1. The result of converting a zero value with an explicit precision of zero is no characters. | Not implemented |
| `f` | The double argument is converted to decimal notation in the style [-]ddd.ddd , where the number of digits after the decimal-point character is equal to the precision specification. If the precision is missing, it is taken as 6; if the precision is explicitly zero, no decimal-point character appears. If a decimal-point character appears, at least one digit appears before it. The value is rounded to the appropriate number of digits. | Not implemented |
| `e`, `E` |  The double argument is converted in the style [-]d.ddde+-dd , where there is one digit before the decimal-point character (which is nonzero if the argument is nonzero) and the number of digits after it is equal to the precision; if the precision is missing, it is taken as 6; if the precision is zero, no decimal-point character appears. The value is rounded to the appropriate number of digits. The `E` conversion specifier will produce a number with E instead of e introducing the exponent. The exponent always contains at least two digits. If the value is zero, the exponent is zero. | Not implemented |
| `g`, `G` | The double argument is converted in style `f` or `e` (or in style `E` in the case of a `G` conversion specifier), with the precision specifying the number of significant digits. If an explicit precision is zero, it is taken as 1. The style used depends on the value converted; style e will be used only if the exponent resulting from such a conversion is less than -4 or greater than or equal to the precision. Trailing zeros are removed from the fractional portion of the result; a decimal-point character appears only if it is followed by a digit. | Not implemented|
| `c` | The int argument is converted to an unsigned char , and the resulting character is written. | Not implemented |
| `s` | The argument shall be a pointer to an array of character type. Characters from the array are written up to (but not including) a terminating null character; if the precision is specified, no more than that many characters are written. If the precision is not specified or is greater than the size of the array, the array shall contain a null character. | Not implemented |
| `p` | The argument shall be a pointer to void . The value of the pointer is converted to a sequence of printable characters, in an implementation-defined manner. | Not implemented |
| `n` |  The argument shall be a pointer to an integer into which is written the number of characters written to the output stream so far by this call to fprintf . No argument is converted. | Not implemented |
| `%` | A % is written. No argument is converted. The complete conversion specification shall be %%. | Not implemented |


[^locale_h]: `locale.h` is not supported due to redundancy and further complexity of the code.
[^signal_h]: `signal.h` is not supported. KolibriOS does not support any signals.
[^strcoll]: `locale.h` is not supported, but does not depend on `LC_COLLATE`, alias ​​to `strcmp()`.
[^strerror]: Implemented, what is in the ANSI C, but needs to be implemented for KolibriOS errors.

