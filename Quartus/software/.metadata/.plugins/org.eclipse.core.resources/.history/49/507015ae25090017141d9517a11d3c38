/*
 * wifi_test.c
 *
 *  Created on: Mar 1, 2017
 *      Author: Randy Baron
 */

#include "wifi_test.h"
#include "motor_test.h"

void wifi_test(void* pdata){
	uint8_t err;

    uint8_t wifiReceive;

	while (1){
		  //do stuff
		// OSSemPend(BUTTON_SEM, 0, &err);
		printf("Hello from wifi\n");

        wifiReceive = (uint8_t) OSQPend(wifiPackageQueue, 0, &err);
        printf("Received form Wifi: %d \n", wifiReceive);
        motorCommand(wifiReceive);
	}
	//OSTimeDlyHMSM(0, 0, 0, CAM_WAIT_MS);
}

void wifi_uart_interrupt(void * context){
    uint8_t read = 0;
    printf("Hello from wifi interrupt\n");
    while(!(IORD_ALTERA_AVALON_UART_STATUS(WIFI_UART_BASE) & ALTERA_AVALON_UART_STATUS_RRDY_MSK));
    read = IORD_ALTERA_AVALON_UART_RXDATA(WIFI_UART_BASE);
    
    OSQPost(wifiPackageQueue, (void*) read);
}

void motorCommand(uint8_t input) {
    if (input == WIFI_MOTOR_CW) {
		IOWR_ALTERA_AVALON_PIO_DATA(MOTOR_L_BASE, MOTOR_FORWARD);
		IOWR_ALTERA_AVALON_PIO_DATA(MOTOR_R_BASE, MOTOR_FORWARD);
    }
    if (input == WIFI_MOTOR_CCW) {
        IOWR_ALTERA_AVALON_PIO_DATA(MOTOR_L_BASE, MOTOR_REVERSE);
		IOWR_ALTERA_AVALON_PIO_DATA(MOTOR_R_BASE, MOTOR_REVERSE);
    }
    if (input == WIFI_MOTOR_STOP) {
        IOWR_ALTERA_AVALON_PIO_DATA(MOTOR_L_BASE, MOTOR_SHORTSTOP);
		IOWR_ALTERA_AVALON_PIO_DATA(MOTOR_R_BASE, MOTOR_SHORTSTOP);
    }
}
