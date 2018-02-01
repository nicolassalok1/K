#ifndef PIT_H
#define PIT_H

#include <stdio.h>
#include "isr.h"
#include "io.h"
#include "irq.h"

void timer_install();
void timer_handler();

#endif
