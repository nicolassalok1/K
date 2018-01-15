#include "pit.h"
#include "monitor.h"

void timer_phase(int hz)
{
    int divisor = 1193180 / hz;       /* Calculate our divisor */
    outb(0x43, 0x36);             /* Set our command byte 0x36 */
    outb(0x40, divisor & 0xFF);   /* Set low byte of divisor */
    outb(0x40, divisor >> 8);     /* Set high byte of divisor */
}

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

void timer_wait(int ticks)
{
    unsigned long eticks;

    eticks = timer_ticks + ticks;
    while(timer_ticks < eticks);
}
