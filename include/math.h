/* Copyright (C) KolibriOS team 2024. All rights reserved. */
/* Distributed under terms of the GNU General Public License */

#ifndef _MATH_H_
#define _MATH_H_

#include <stddef.h>

/* Trig functions */
DLLAPI double sin(double x);
DLLAPI double cos(double x);
DLLAPI double tan(double x);

/* Inverse tring functions */
DLLAPI double asin(double x);
DLLAPI double acos(double x);
DLLAPI double atan(double x);

/* Arctan(y/x) */
DLLAPI double atan2(double y, double x);

/* Hyperbolic trig functions */
DLLAPI double sinh(double x);
DLLAPI double cosh(double x);
DLLAPI double tanh(double x);

/* Exponentials & logs */
DLLAPI double exp(double x);
DLLAPI double log(double y);
DLLAPI double log10(double x);

/* Exponentials & logs (2 power) */
DLLAPI double ldexp(double x, int exp);
DLLAPI double frexp(double x, int *pexp);

/* Division & remainder */
DLLAPI double modf(double x, double *pint);
DLLAPI double fmod(double x, double y);

/* Powers */
DLLAPI double pow(double x, double y);
DLLAPI double sqrt(double _x);

/* Rounding */
DLLAPI double ceil(double x);
DLLAPI double fabs(double x);
DLLAPI double floor(double x);

#endif // _MATH_H_
