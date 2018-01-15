//
// isr.h -- Interface and structures for high level interrupt service routines.
//          Part of this code is modified from Bran's kernel development tutorials.
//          Rewritten for JamesM's kernel development tutorials.
//

#ifndef ISR_H
#define ISR_H


#include <k/types.h>
#include <stdio.h>

typedef struct registers
{
    u32 ds;                  // Data segment selector
    u32 edi, esi, ebp, esp, ebx, edx, ecx, eax; // Pushed by pusha.
    u32 int_no, err_code;    // Interrupt number and error code (if applicable)
    u32 eip, cs, eflags, useresp, ss; // Pushed by the processor automatically.
} registers_t;

void isr_handler(u32 ds, u32 edi, u32 esi, u32 ebp, u32 esp,
                  u32 ebx, u32 edx, u32 ecx, u32 eax, u32 int_no,
                  u32 err_code, u32 eip, u32 cs, u32 cflags,
                  u32 useresp, u32 ss);


#endif				/* !LIBVGA_H */
