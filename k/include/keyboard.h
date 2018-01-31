#ifndef KEY_H
#define KEY_H

#include <stdio.h>
#include "isr.h"
#include "io.h"

void keyboard_handler();
void keyboard_install();
void handle_key (unsigned char scancode);

#endif
