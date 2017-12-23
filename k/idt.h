#include <k/types.h>
// A struct describing an interrupt gate.

void init_idt();

struct idt_entry_struct
{
    u16 base_lo;             // The lower 16 bits of the address to jump to when this interrupt fires.
    u16 sel;                 // Kernel segment selector.
    u8  always0;             // This must always be zero.
    u8  flags;               // More flags. See documentation.
    u16 base_hi;             // The upper 16 bits of the address to jump to.
} __attribute__((packed));

typedef struct idt_entry_struct idt_entry_t;

// A struct describing a pointer to an array of interrupt handlers.
// This is in a format suitable for giving to 'lidt'.
struct idt_ptr_struct
{
    u16 limit;
    u32 base;                // The address of the first element in our idt_entry_t array.
} __attribute__((packed));

typedef struct idt_ptr_struct idt_ptr_t;

// These extern directives let us access the addresses of our ASM ISR handlers.
extern void _isr0 ();
extern void _isr1 ();
extern void _isr2 ();
extern void _isr3 ();
extern void _isr4 ();
extern void _isr5 ();
extern void _isr6 ();
extern void _isr7 ();
extern void _isr8 ();
extern void _isr9 ();
extern void _isr10();
extern void _isr11();
extern void _isr12();
extern void _isr13();
extern void _isr14();
extern void _isr15();
extern void _isr16();
extern void _isr17();
extern void _isr18();
extern void _isr19();
extern void _isr20();
extern void _isr21();
extern void _isr22();
extern void _isr23();
extern void _isr24();
extern void _isr25();
extern void _isr26();
extern void _isr27();
extern void _isr28();
extern void _isr29();
extern void _isr30();
extern void _isr31();
