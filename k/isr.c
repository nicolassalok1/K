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

void isr_handler(u32 ds,
                  u32 edi,
                  u32 esi,
                  u32 ebp,
                  u32 esp,
                  u32 ebx,
                  u32 edx,
                  u32 ecx,
                  u32 eax,
                  u32 int_no,
                  u32 err_code,
                  u32 eip,
                  u32 cs,
                  u32 cflags,
                  u32 useresp,
                  u32 ss)
{
  (void)ds;
  (void)edi;
  (void)esi;
  (void)ebp;
  (void)esp;
  (void)ebx;
  (void)edx;
  (void)ecx;
  (void)eax;
  (void)eip;
  (void)cs;
  (void)cflags;
  (void)useresp;
  (void)ss;
  (void)err_code;

    monitor_write(" Exception. System Halted!\n");

    if (int_no < 32)
    {
      monitor_write((char *)exception_messages[int_no]);
    }
    else {
      monitor_write("int number KO");
    }

    monitor_put('\n');
    monitor_put('\n');
}
