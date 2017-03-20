/*
 * wifi_test.h
 *
 *  Created on: Mar 1, 2017
 *      Author: Randy Baron
 */

#ifndef WIFI_TEST_H_
#define WIFI_TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "altera_avalon_pio_regs.h"
#include "altera_avalon_uart_regs.h"
#include "includes.h"

void wifi_test(void* pdata);
void wifi_uart_interrupt(void * context);

/* Definition of Queue info */

/*Definition of internal WiFi queues*/
#define WIFI_PACKAGE_BUFFER_LENGTH     1
OS_EVENT* wifiPackageQueue;
void* wifiPackageBuffer[WIFI_PACKAGE_BUFFER_LENGTH];

/*Definition of internal WiFi queues*/
#define SEM_INIT_VALUE 0
#define WIFI_MOTOR_CW                  49
#define WIFI_MOTOR_CCW                 50
#define WIFI_MOTOR_STOP                51

#endif /* WIFI_TEST_H_ */
