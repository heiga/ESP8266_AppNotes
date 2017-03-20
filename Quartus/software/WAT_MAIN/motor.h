/*
 * motor_test.h
 *
 *  Created on: Mar 1, 2017
 *      Author: Randy Baron
 */

#ifndef MOTOR_TEST_H_
#define MOTOR_TEST_H_

#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>

#include "includes.h"
#include "altera_avalon_pio_regs.h"
#include "wat_main.h"

void motor_task(void* pdata);

/* Redefine stdbool to use proper constant names */
#define TRUE   true
#define FALSE  false

/* Definition of direction info */
//2 1 PWM
#define MOTOR_FORWARD		0b011 //CW
#define MOTOR_REVERSE		0b101 //CCW
#define MOTOR_SHORTSTOP		0b111 //SHORT STOP, low voltage output
#define MOTOR_FULLSTOP	  	0b001 //FULL STOP, high impedance output

#endif /* MOTOR_TEST_H_ */
