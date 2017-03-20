/*
 * interrupt_peripherals.h
 *
 *  Created on: Mar 8, 2017
 *      Author: Randy Baron
 */

#ifndef INTERRUPT_PERIPHERALS_H_
#define INTERRUPT_PERIPHERALS_H_

#include <stdlib.h>
#include <inttypes.h>

#include "includes.h"
#include "altera_avalon_pio_regs.h"

void button_interrupt(void * context);
void sensor_interrupt(void * context);

#endif /* INTERRUPT_PERIPHERALS_H_ */
