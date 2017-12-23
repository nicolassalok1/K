#include "idt.h"
#include "string.h"

idt_entry_t idt_entries[256];
idt_ptr_t   idt_ptr;


void idt_set_gate(u8 num, u32 base, u16 sel, u8 flags)
{
    idt_entries[num].base_lo = base & 0xFFFF;
    idt_entries[num].base_hi = (base >> 16) & 0xFFFF;

    idt_entries[num].sel     = sel;
    idt_entries[num].always0 = 0;
    // We must uncomment the OR below when we get to using user-mode.
    // It sets the interrupt gate's privilege level to 3.
    idt_entries[num].flags   = flags /* | 0x60 */;
}

void init_idt()
{
    idt_ptr.limit = sizeof(idt_entry_t) * 256 -1;
    idt_ptr.base  = (u32)&idt_entries;

    memset(&idt_entries, 0, sizeof(idt_entry_t)*256);

    idt_set_gate( 0, (u32)_isr0 , 0x08, 0x8E);
    idt_set_gate( 1, (u32)_isr1 , 0x08, 0x8E);
    idt_set_gate( 2, (u32)_isr2 , 0x08, 0x8E);
    idt_set_gate( 3, (u32)_isr3 , 0x08, 0x8E);
    idt_set_gate( 4, (u32)_isr4 , 0x08, 0x8E);
    idt_set_gate( 5, (u32)_isr5 , 0x08, 0x8E);
    idt_set_gate( 6, (u32)_isr6 , 0x08, 0x8E);
    idt_set_gate( 7, (u32)_isr7 , 0x08, 0x8E);
    idt_set_gate( 8, (u32)_isr8 , 0x08, 0x8E);
    idt_set_gate( 9, (u32)_isr9 , 0x08, 0x8E);
    idt_set_gate(10, (u32)_isr10, 0x08, 0x8E);
    idt_set_gate(11, (u32)_isr11, 0x08, 0x8E);
    idt_set_gate(12, (u32)_isr12, 0x08, 0x8E);
    idt_set_gate(13, (u32)_isr13, 0x08, 0x8E);
    idt_set_gate(14, (u32)_isr14, 0x08, 0x8E);
    idt_set_gate(15, (u32)_isr15, 0x08, 0x8E);
    idt_set_gate(16, (u32)_isr16, 0x08, 0x8E);
    idt_set_gate(17, (u32)_isr17, 0x08, 0x8E);
    idt_set_gate(18, (u32)_isr18, 0x08, 0x8E);
    idt_set_gate(19, (u32)_isr19, 0x08, 0x8E);
    idt_set_gate(20, (u32)_isr20, 0x08, 0x8E);
    idt_set_gate(21, (u32)_isr21, 0x08, 0x8E);
    idt_set_gate(22, (u32)_isr22, 0x08, 0x8E);
    idt_set_gate(23, (u32)_isr23, 0x08, 0x8E);
    idt_set_gate(24, (u32)_isr24, 0x08, 0x8E);
    idt_set_gate(25, (u32)_isr25, 0x08, 0x8E);
    idt_set_gate(26, (u32)_isr26, 0x08, 0x8E);
    idt_set_gate(27, (u32)_isr27, 0x08, 0x8E);
    idt_set_gate(28, (u32)_isr28, 0x08, 0x8E);
    idt_set_gate(29, (u32)_isr29, 0x08, 0x8E);
    idt_set_gate(30, (u32)_isr30, 0x08, 0x8E);
    idt_set_gate(31, (u32)_isr31, 0x08, 0x8E);

    asm volatile("lidt %0\n"
                : /* no output */
                 : "m" (idt_ptr)
                 : "memory");
}
