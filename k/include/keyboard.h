#ifndef KEY_H
#define KEY_H

#include <stdio.h>
#include "isr.h"
#include "io.h"

void keyboard_handler(registers_t *r);
void keyboard_install();

#endif
