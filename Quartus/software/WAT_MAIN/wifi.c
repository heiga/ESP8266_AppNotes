/*
 * wifi_test.c
 *
 *  Created on: Mar 1, 2017
 *      Author: Randy Baron
 */

#include "wifi.h"

void wifi_task(void* pdata){
	uint8_t err;
    uint8_t wifiReceive;

	while (1){

        wifiReceive = (uint8_t) OSQPend(wifiPackageQueue, 0, &err);
	}
}

void wifi_uart_interrupt(void * context){
    uint8_t read = 0;

    while(!(IORD_ALTERA_AVALON_UART_STATUS(WIFI_UART_BASE) & ALTERA_AVALON_UART_STATUS_RRDY_MSK));
    read = IORD_ALTERA_AVALON_UART_RXDATA(WIFI_UART_BASE);
    
    OSQPost(wifiPackageQueue, (void*) read);
}
