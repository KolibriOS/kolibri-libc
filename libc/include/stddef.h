#ifndef _STDDEF_H_
#define _STDDEF_H_

typedef __SIZE_TYPE__ size_t;
typedef __PTRDIFF_TYPE__ ssize_t;
typedef __WCHAR_TYPE__ wchar_t;
typedef __PTRDIFF_TYPE__ ptrdiff_t;
typedef __PTRDIFF_TYPE__ intptr_t;
typedef __SIZE_TYPE__ uintptr_t;

#ifndef NULL
#define NULL ((void*)0)
#endif

#define __CONCAT(x,y)	x ## y
#define __STRING(x)	#x

#define DLLAPI

#define offsetof(type, field) ((size_t) & ((type*)0)->field)

#ifndef __stdcall
#define __stdcall __attribute__((stdcall))
#endif

#ifndef __cdecl
#define __cdecl __attribute__((cdecl))
#endif

#endif /* _STDDEF_H_ */
