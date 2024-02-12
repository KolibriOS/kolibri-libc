/*
 * musl as a whole is licensed under the following standard MIT license:
 * Copyright © 2005-2020 Rich Felker, et al.
 *
 * Copyright (C) KolibriOS team 2024. All rights reserved.
 * Distributed under terms of the GNU General Public License
 */

setjmp:
    mov     4(%esp), %eax
    mov     %ebx, (%eax)
    mov     %esi, 4(%eax)
    mov     %edi, 8(%eax)
    mov     %ebp, 12(%eax)
    lea     4(%esp), %ecx
    mov     %ecx, 16(%eax)
    mov     (%esp), %ecx
    mov     %ecx, 20(%eax)
    xor     %eax, %eax
    ret

longjmp:
    mov     4(%esp), %edx
    mov     8(%esp), %eax
    cmp     $1, %eax
    adc     $0, %al
    mov     (%edx), %ebx
    mov     4(%edx), %esi
    mov     8(%edx), %edi
    mov     12(%edx), %ebp
    mov     16(%edx), %esp
    jmp     *20(%edx)
