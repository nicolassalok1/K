extern _irq_handler

_irq_common_stub:

pusha
mov ax, ds
push eax
mov ax, 0x10
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax

call _irq_handler ; Different than the ISR code

pop ebx  ; Different than the ISR code
mov ds, bx
mov es, bx
mov fs, bx
mov gs, bx
popa
add esp, 8
sti
iret


global _irq0
global _irq1
global _irq2
global _irq3
global _irq4
global _irq5
global _irq6
global _irq7
global _irq8
global _irq9
global _irq10
global _irq11
global _irq12
global _irq13
global _irq14
global _irq15


_irq0:
	cli
	push byte 0
	push byte 32
	jmp _irq_common_stub

_irq1:
	cli
	push byte 1
	push byte 33
	jmp _irq_common_stub

_irq2:
	cli
	push byte 2
	push byte 34
	jmp _irq_common_stub

_irq3:
	cli
	push byte 3
	push byte 35
	jmp _irq_common_stub

_irq4:
	cli
	push byte 4
	push byte 36
	jmp _irq_common_stub

_irq5:
	cli
	push byte 5
	push byte 37
	jmp _irq_common_stub

_irq6:
	cli
	push byte 6
	push byte 38
	jmp _irq_common_stub

_irq7:
	cli
	push byte 7
	push byte 39
	jmp _irq_common_stub

_irq8:
	cli
	push byte 8
	push byte 40
	jmp _irq_common_stub

_irq9:
	cli
	push byte 9
	push byte 41
	jmp _irq_common_stub

_irq10:
	cli
	push byte 10
	push byte 42
	jmp _irq_common_stub

_irq11:
	cli
	push byte 11
	push byte 43
	jmp _irq_common_stub

_irq12:
	cli
	push byte 12
	push byte 44
	jmp _irq_common_stub

_irq13:
	cli
	push byte 13
	push byte 45
	jmp _irq_common_stub

_irq14:
	cli
	push byte 14
	push byte 46
	jmp _irq_common_stub

_irq15:
	cli
	push byte 15
	push byte 47
	jmp _irq_common_stub
