#ifndef PIT_H
#define PIT_H

#include <stdio.h>
#include "isr.h"
#include "io.h"
#include "irq.h"

void timer_phase(int hz);
void timer_install();
void timer_handler();
void timer_wait(int ticks);

#endif
