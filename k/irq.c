#include "irq.h"


void *irq_routines[16] =
{
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
};

/* This installs a custom IRQ handler for the given IRQ */
void irq_install_handler(int irq, void (*handler)(registers_t *r))
{
    irq_routines[irq] = handler;
}

/* This clears the handler for a given IRQ */
void irq_uninstall_handler(int irq)
{
    irq_routines[irq] = 0;
}

/* Normally, IRQs 0 to 7 are mapped to entries 8 to 15. This
*  is a problem in protected mode, because IDT entry 8 is a
*  Double Fault! Without remapping, every time IRQ0 fires,
*  you get a Double Fault Exception, which is NOT actually
*  what's happening. We send commands to the Programmable
*  Interrupt Controller (PICs - also called the 8259's) in
*  order to make IRQ0 to 15 be remapped to IDT entries 32 to
*  47 */
void irq_remap(void)
{
    outb(0x20, 0x11);
    outb(0xA0, 0x11);
    outb(0x21, 0x20);
    outb(0xA1, 0x28);
    outb(0x21, 0x04);
    outb(0xA1, 0x02);
    outb(0x21, 0x01);
    outb(0xA1, 0x01);
    outb(0x21, 0x0);
    outb(0xA1, 0x0);
}

/* We first remap the interrupt controllers, and then we install
*  the appropriate ISRs to the correct entries in the IDT. This
*  is just like installing the exception handlers */
void irq_install()
{
    irq_remap();

    idt_set_gate(0, (unsigned)_irq0, 0x08, 0x8E);
    idt_set_gate(1, (unsigned)_irq1, 0x08, 0x8E);
    idt_set_gate(2, (unsigned)_irq2, 0x08, 0x8E);
    idt_set_gate(3, (unsigned)_irq3, 0x08, 0x8E);
    idt_set_gate(4, (unsigned)_irq4, 0x08, 0x8E);
    idt_set_gate(5, (unsigned)_irq5, 0x08, 0x8E);
    idt_set_gate(6, (unsigned)_irq6, 0x08, 0x8E);
    idt_set_gate(7, (unsigned)_irq7, 0x08, 0x8E);
    idt_set_gate(8, (unsigned)_irq8, 0x08, 0x8E);
    idt_set_gate(9, (unsigned)_irq9, 0x08, 0x8E);
    idt_set_gate(10, (unsigned)_irq10, 0x08, 0x8E);
    idt_set_gate(11, (unsigned)_irq11, 0x08, 0x8E);
    idt_set_gate(12, (unsigned)_irq12, 0x08, 0x8E);
    idt_set_gate(13, (unsigned)_irq13, 0x08, 0x8E);
    idt_set_gate(14, (unsigned)_irq14, 0x08, 0x8E);
    idt_set_gate(15, (unsigned)_irq15, 0x08, 0x8E);
}

/* Each of the IRQ ISRs point to this function, rather than
*  the 'fault_handler' in 'isrs.c'. The IRQ Controllers need
*  to be told when you are done servicing them, so you need
*  to send them an "End of Interrupt" command (0x20). There
*  are two 8259 chips: The first exists at 0x20, the second
*  exists at 0xA0. If the second controller (an IRQ from 8 to
*  15) gets an interrupt, you need to acknowledge the
*  interrupt at BOTH controllers, otherwise, you only send
*  an EOI command to the first controller. If you don't send
*  an EOI, you won't raise any more IRQs */
void _irq_handler(registers_t *r)
{
    /* This is a blank function pointer */
    void (*handler)(registers_t *r);

    /* Find out if we have a custom handler to run for this
    *  IRQ, and then finally, run it */
    handler = irq_routines[r->int_no - 32];
    if (handler )
    {
        handler(r);
    }

    /* If the IDT entry that was invoked was greater than 40
    *  (meaning IRQ8 - 15), then we need to send an EOI to
    *  the slave controller */
    if (r->err_code >= 40)
    {
        outb(0xA0, 0x20);
    }

    /* In either case, we need to send an EOI to the master
    *  interrupt controller too */
    outb(0x20, 0x20);
}
