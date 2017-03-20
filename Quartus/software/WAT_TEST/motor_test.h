/*
 * motor_test.h
 *
 *  Created on: Mar 1, 2017
 *      Author: Randy Baron
 */

#ifndef MOTOR_TEST_H_
#define MOTOR_TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "altera_avalon_pio_regs.h"
#include "includes.h"

void motor_test(void* pdata);
void sensor_interrupt(void * context);

/* Definition of Queue info */
#define SEM_INIT_VALUE 0
OS_EVENT *SENSOR_SEM;

/* Definition of direction info */
//2 1 PWM
#define MOTOR_FORWARD		0b011 //CW
#define MOTOR_REVERSE		0b101 //CCW
#define MOTOR_SHORTSTOP		0b111 //SHORT STOP, low voltage output
#define MOTOR_FULLSTOP	  	0b001 //FULL STOP, high impedance output

#endif /* MOTOR_TEST_H_ */
