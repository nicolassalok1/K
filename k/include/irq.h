#ifndef IRQ_H
#define IRQ_H

#include "isr.h"
#include "io.h"
#include "idt.h"
/* These are own ISRs that point to our special IRQ handler
*  instead of the regular 'fault_handler' function */
extern void _irq0();
extern void _irq1();
extern void _irq2();
extern void _irq3();
extern void _irq4();
extern void _irq5();
extern void _irq6();
extern void _irq7();
extern void _irq8();
extern void _irq9();
extern void _irq10();
extern void _irq11();
extern void _irq12();
extern void _irq13();
extern void _irq14();
extern void _irq15();

/* This array is actually an array of function pointers. We use
*  this to handle custom IRQ handlers for a given IRQ */


void irq_install_handler(int irq, void (*handler)(registers_t *r));
void irq_uninstall_handler(int irq);
void irq_remap(void);
void irq_install();
void _irq_handler(u32 ds, u32 edi, u32 esi, u32 ebp, u32 esp,
                  u32 ebx, u32 edx, u32 ecx, u32 eax, u32 int_no,
                  u32 err_code, u32 eip, u32 cs, u32 cflags,
                  u32 useresp, u32 ss);
#endif
