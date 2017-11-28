#include "io.h"
#include "write.h"

void prepare ()
{
	int n1 = inb(0x3F8 + 3);
	int n2 = inb(0x3F8 + 2);
	int n3 = inb(0x3F8 + 1);

	n1 |= 1 << 0;
	n1 |= 1 << 1;
	n1 &= ~(1 << 3);

	outb(0x3F8, n1);

	outb(0x3F8, 0x03);
	outb(0x3F8 + 1, 0x00);

	n2 |= 1 << 0;
	n2 |= 1 << 1;
	n2 |= 1 << 2;
	n2 |= 1 << 6;
	n2 |= 1 << 7;

	outb(0x3F8, n2);

	n3 |= 1 << 1;

	outb(0x3F8, n3);

}

int write (const char *buf, size_t count)
{
	for (unsigned i = 0; i < count; i++) {
		outb(0x3F8, * (buf + i));
	}
	return count;
}
