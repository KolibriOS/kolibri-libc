/* 
 * Copyright (C) 1995 DJ Delorie, see COPYING.DJ for details
 *
 * Copyright (C) KolibriOS team 2024. All rights reserved.
 * Distributed under terms of the GNU General Public License
 */

memmove:
    pushl   %ebp
    movl    %esp, %ebp
    pushl   %esi
    pushl   %edi
    movl    8(%ebp), %edi
    movl    12(%ebp), %esi
    movl    16(%ebp), %ecx
    jecxz   memmove.L2
    cld
    cmpl    %esi, %edi
    jb      memmove.L3
    std
    addl    %ecx, %esi
    addl    %ecx, %edi
    decl    %esi
    decl    %edi
memmove.L3:
    rep
    movsb
memmove.L2:
    cld
    popl    %edi
    popl    %esi
    movl    8(%ebp), %eax
    leave
    ret
