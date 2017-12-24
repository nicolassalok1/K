#ifndef IO_H_
#define IO_H_

#include <k/types.h>

static inline void outb(u16 port, u8 val)
{
		(void)port;
		(void)val;

		asm volatile("outb %0, %1\n\t"
								: /* No output */
								: "a" (val), "d" (port));
}

static inline u8 inb(u16 port)
{
	(void)port;

	u8 res;

	asm volatile("inb %1, %0\n\t"
							: "=&a" (res)
	            : "d" (port));
	return res;
}

void scroll(void);

/* Updates the hardware cursor: the little blinking line
*  on the screen under the last character pressed! */
void move_csr(void);

/* Clears the screen */
void cls();

/* Puts a single character on the screen */
void putch(unsigned char c);

/* Sets the forecolor and backcolor that we will use */
void settextcolor(unsigned char forecolor, unsigned char backcolor);

/* Sets our text-mode VGA pointer, then clears the screen for us */
void init_video(void);

#endif				/* !IO_H_ */
