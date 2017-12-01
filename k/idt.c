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

//put idt_entries

    asm volatile("lidt %0\n"
                : /* no output */
                 : "m" (idt_ptr)
                 : "memory");
}
