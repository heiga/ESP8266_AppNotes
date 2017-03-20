/*
 * interrupt_peripherals.c
 *
 *  Created on: Mar 8, 2017
 *      Author: Randy Baron
 */

#include "camera.h"
#include "motor.h"
#include "wifi.h"
#include "interrupt_peripherals.h"

void sensor_interrupt(void * context){
	printf("sensor\n");

	//clear interrupt
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PROX_SENSOR_BASE, 1);
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(PROX_SENSOR_BASE, 0xF);
}

void button_interrupt(void * context){
	printf("button\n");
	OSTimeDlyHMSM(0, 0, 0, 400);

	//clear interrupt
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(BUTTON_BUTTON_BASE, 1);
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(BUTTON_BUTTON_BASE, 0xF);
}
