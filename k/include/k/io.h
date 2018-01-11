#ifndef IO_H_
#define IO_H_

#include <k/types.h>

static inline void outb(u16 port, u8 val)
{
		(void)port;
		(void)val;

		__asm__ __volatile__ ("outb %1, %0" : : "dN" (port), "a" (val));
}

static inline u8 inb(u16 port)
{
	(void)port;

	u8 res;

	__asm__ __volatile__ ("inb %1, %0" : "=a" (res) : "dN" (port));
	return res;
}
/*
unsigned char inportb (unsigned short _port)
{
    unsigned char rv;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}

void outportb (unsigned short _port, unsigned char _data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}
*/


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
