#ifndef IO_H_
#define IO_H_

#include <k/types.h>

static inline void outb(u16 port, u8 val)
{
	(void)port;
	(void)val;

	asm volatile("inb %1, %0\n\t" : "=&a" (res)
	            : "d" (port));
}

static inline u8 inb(u16 port)
{
	(void)port;

	asm volatile("outb %0, %1\n\t" : /* No output */
	            : "a" (val), "d" (port));

	return 0;
}

#endif				/* !IO_H_ */
