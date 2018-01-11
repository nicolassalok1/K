#include "isr.h"
#include "monitor.h"
#include "io.h"


const char *exception_messages[] =
{
  "Division By Zero Exception",
  "Debug Exception",
  "Maskable Interrupt Exception",
  "Breakpoint Exception",
  "Into Detected Overflow Exception",
  "Out of Bounds Exception",
  "Invalid Opcode Exception",
  "Coprocessor Exception",
  "Double Fault Exception",
  "Coprocessor Segment Overrun Exception",
  "Bad TSS Exception",
  "Segment Not Present Exception",
  "Stack Fault Exception",
  "General Protection Fault Exception",
  "Page Fault Exception",
  "Unknown Interrupt Exception",
  "Coprocessor Fault Exception",
  "Alignment Check Exception",
  "Machine Check Exception",
  "Reserved Exception",
  "Reserved Exception",
  "Reserved Exception",
  "Reserved Exception",
  "Reserved Exception",
  "Reserved Exception",
  "Reserved Exception",
  "Reserved Exception",
  "Reserved Exception",
  "Reserved Exception",
  "Reserved Exception",
  "Reserved Exception"
};

void isr_handler(registers_t* r)
{
    monitor_write(" Exception. System Halted!\n");

    if (r->int_no < 32)
    {
        monitor_write((char *)exception_messages[r->int_no]);

        monitor_put('\n');
    }
}
