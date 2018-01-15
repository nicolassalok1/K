#include "io.h"

void outb(u16 port, u8 val)
{
		(void)port;
		(void)val;

		__asm__ __volatile__("out %%al, %%dx" : : "a" (val), "d" (port));
}

u8 inb(u16 port)
{
	u8 res;

	__asm__("in %%dx, %%al" : "=a" (res) : "d" (port));

	return res;
}
