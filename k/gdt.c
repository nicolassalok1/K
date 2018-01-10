#include "gdt.h"
#include <k/types.h>

// Internal function prototypes.

static void gdt_set_gate(s32,u32,u32,u8,u8);

gdt_entry_t gdt_entries[3];
gdt_ptr_t   gdt_ptr;

// Initialisation routine - zeroes all the interrupt service routines,
// initialises the GDT and IDT.

void init_gdt()
{
    gdt_ptr.limit = (sizeof(gdt_entry_t) * 3) - 1;
    gdt_ptr.base  = (u32)&gdt_entries;

    gdt_set_gate(0, 0, 0, 0, 0);                // Null segment
    gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Code segment
    gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Data segment
    //gdt_set_gate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); // User mode code segment
    //gdt_set_gate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); // User mode data segment

    //u32 input = (u32)&gdt_ptr;// + 4;

    asm volatile("lgdt %0\n"
                 : /* no output */
                 : "m" (gdt_ptr)
                 : "memory");

    asm volatile("movl %cr0, %eax\n\t"
                 "or 1, %eax \n\t"
                 "movl %eax, %cr0\n\t");

    asm volatile("movl %eax, %cr0\n\t");

    asm volatile("movw $0x10, %ax\n\t");
    asm volatile("movw %ax, %ds\n\t");
    asm volatile("movw %ax, %es\n\t");
    asm volatile("movw %ax, %fs\n\t");
    asm volatile("movw %ax, %gs\n\t");
    asm volatile("movw %ax, %ss\n\t");

   asm volatile("pushl $0x08\n\t"
                "pushl $1f\n\t"
                "lret \n\t"
                "1:");/*
    asm volatile("ljmp $0x08, %1\n\t"
                  "1:");*/

}

// Set the value of one GDT entry.
static void gdt_set_gate(s32 num, u32 base, u32 limit, u8 access, u8 gran)
{
    gdt_entries[num].base_low    = (base & 0xFFFF);
    gdt_entries[num].base_middle = (base >> 16) & 0xFF;
    gdt_entries[num].base_high   = (base >> 24) & 0xFF;

    gdt_entries[num].limit_low   = (limit & 0xFFFF);
    gdt_entries[num].granularity = (limit >> 16) & 0x0F;

    gdt_entries[num].granularity |= gran & 0xF0;
    gdt_entries[num].access      = access;
}
