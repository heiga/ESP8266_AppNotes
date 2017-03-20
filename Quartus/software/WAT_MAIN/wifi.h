/*
 * wifi_test.h
 *
 *  Created on: Mar 1, 2017
 *      Author: Randy Baron
 */

#ifndef WIFI_TEST_H_
#define WIFI_TEST_H_

#include <stdlib.h>
#include <inttypes.h>

#include "includes.h"
#include "altera_avalon_uart_regs.h"
#include "wat_main.h"

void wifi_task(void* pdata);
void wifi_uart_interrupt(void * context);

#endif /* WIFI_TEST_H_ */
