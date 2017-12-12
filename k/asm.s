extern isr_handler

isr_common_stub:
  pusha

  mov ax, ds
  push eax

  mov ax, 0x10
  mov ds, ax
  mov es, ax
  mov fs, ax
  mov gs, ax

  call isr_handler

  pop ebx
  mov ds, bx
  mov es, bx
  mov fs, bx
  mov gs, bx

  popa
  add esp, 8
  sti
  iret


  global isr0;

  isr0:
    cli
    push byte 0
    push byte 0
    jmp isr_common_stub
