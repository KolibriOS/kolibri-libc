/*
 * Copyright (C) KolibriOS team 2021-2024. All rights reserved.
 * Distributed under terms of the GNU General Public License
 */

#ifndef _TIME_H_
#define _TIME_H_

#include <stddef.h>

#define CLK_TCK 100

typedef unsigned long int clock_t;
typedef unsigned long int time_t;

struct tm {
    int tm_sec;   /* seconds after the minute	0-61*/
    int tm_min;   /* minutes after the hour	0-59 */
    int tm_hour;  /* hours since midnight	0-23 */
    int tm_mday;  /* day of the month	1-31 */
    int tm_mon;   /* months since January	0-11 */
    int tm_year;  /* years since 1900 */
    int tm_wday;  /* days since Sunday	0-6		*/
    int tm_yday;  /* days since January 1	0-365 	*/
    int tm_isdst; /* Daylight Saving Time flag	*/
};

/* Time manipulation functions */
DLLAPI clock_t clock();
DLLAPI double difftime(time_t end, time_t beginning);
DLLAPI time_t mktime(struct tm *timeptr);
DLLAPI time_t time(time_t *timer);

/* Time conversion functions */
DLLAPI char *asctime(const struct tm *tm);
DLLAPI char *ctime(const time_t *timer);
DLLAPI struct tm *gmtime(const time_t *timer);
DLLAPI struct tm *localtime(const time_t *timer);
DLLAPI size_t strftime(char *s, size_t maxsize, const char *format, const struct tm *timeptr);

#endif // _TIME_H_
