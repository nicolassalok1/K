#include "io.h"

void outb(u16 port, u8 val)
{
		(void)port;
		(void)val;

		asm volatile("outb %0, %1\n\t"
								: /* No output */
								: "a" (val), "d" (port));
}

u8 inb(u16 port)
{
	(void)port;

	u8 res;

	asm volatile("inb %1, %0\n\t"
							: "=&a" (res)
	            : "d" (port));
	return res;
}
