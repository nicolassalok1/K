/*
 * Copyright (c) LSE
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY LSE AS IS AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL LSE BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <k/kstd.h>

#include "multiboot.h"

void prepare ()
{
	int n1 = inb(0x3F8 + 3);
	int n2 = inb(0x3F8 + 2);
	int n3 = inb(0x3F8 + 1);

	n1 |= 1 << 0;
	n1 |= 1 << 1;
	n1 &= ~(1 << 3);
	n1 |= 1 << 1;

	outb(Ox3F8, n1);

	outb(Ox3F8, 0x03);
	outb(Ox3F8 + 1, 0x00);

	n2 |= 1 << 0;
	n2 |= 1 << 1;
	n2 |= 1 << 2;
	n2 |= 1 << 6;
	n2 |= 1 << 7;

	outb(Ox3F8, n2);

	n3 |= 1 << 1;

	outb(Ox3F8, n3);

}

int write (cont char *buf, size_t count)
{
	for (unsigned i = 0; i < count; i++) {
		outb(Ox3F8, * (buf + i));
	}
}


void k_main(unsigned long magic, multiboot_info_t *info)
{
	(void)magic;
	(void)info;

	char star[4] = "|/-\\";
	char *fb = (void *)0xb8000;

	for (unsigned i = 0; ; ) {
		*fb = star[i++ % 4];
	}

	for (;;)
		asm volatile ("hlt");
}
