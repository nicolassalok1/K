#include "isr.h"
#include "write.h"


void isr_handler(registers_t* r)
{
    if (r->err_code < 32)
    {
        printf("%d", &r->err_code);
        printf("Exception. System Halted!\n");
        for (;;);
    }
}
