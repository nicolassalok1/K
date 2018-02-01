#include "pit.h"
#include "monitor.h"

unsigned long timer_ticks = 0;

void timer_handler()
{
    timer_ticks++;

    if (timer_ticks % 18 == 0)
    {
        monitor_write("One second has passed\n");
    }
}

void timer_install()
{
    irq_install_handler(0, timer_handler);
}
