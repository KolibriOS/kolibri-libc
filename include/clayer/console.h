/*
 * Copyright (C) KolibriOS team 2024. All rights reserved.
 * Distributed under terms of the GNU General Public License
 */

#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <stddef.h>

void DLLAPI __stdcall con_init(int wnd_width, unsigned wnd_height, int scr_width, int scr_height, const char* title);
void DLLAPI __stdcall con_exit(int b_close_window);
void DLLAPI __stdcall con_write_asciiz(const char* str);

#endif // _CONSOLE_H_
