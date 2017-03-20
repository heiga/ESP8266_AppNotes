/*************************************************************************
* Copyright (c) 2004 Altera Corporation, San Jose, California, USA.      *
* All rights reserved. All use of this software and documentation is     *
* subject to the License Agreement located at the end of this file below.*
**************************************************************************
* Description:                                                           *
* The following is a simple hello world program running MicroC/OS-II.The * 
* purpose of the design is to be a very simple application that just     *
* demonstrates MicroC/OS-II running on NIOS II.The design doesn't account*
* for issues such as checking system call return codes. etc.             *
*                                                                        *
* Requirements:                                                          *
*   -Supported Example Hardware Platforms                                *
*     Standard                                                           *
*     Full Featured                                                      *
*     Low Cost                                                           *
*   -Supported Development Boards                                        *
*     Nios II Development Board, Stratix II Edition                      *
*     Nios Development Board, Stratix Professional Edition               *
*     Nios Development Board, Stratix Edition                            *
*     Nios Development Board, Cyclone Edition                            *
*   -System Library Settings                                             *
*     RTOS Type - MicroC/OS-II                                           *
*     Periodic System Timer                                              *
*   -Know Issues                                                         *
*     If this design is run on the ISS, terminal output will take several*
*     minutes per iteration.                                             *
**************************************************************************/

//TODO find nonvolatile way to store destination info for reset

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <io.h>
#include "altera_avalon_pio_regs.h"
#include "includes.h"

#include "camera_test.h"
#include "motor_test.h"
#include "wifi_test.h"

/* Definition of Task Stacks */
#define   TASK_STACKSIZE       2048
OS_STK    motor_test_stk[TASK_STACKSIZE];
OS_STK    camera_test_stk[TASK_STACKSIZE];
OS_STK    wifi_test_stk[TASK_STACKSIZE];

/* Definition of Task Priorities */

#define MOTOR_TEST_PRIORITY     2
#define CAMERA_TEST_PRIORITY    1
#define WIFI_TEST_PRIORITY		3

//section 7 is the UART reference
//https://www.altera.com/en_US/pdfs/literature/ug/ug_embedded_ip.pdf
//
//helpful functions for UART interfacing
//IORD(base, offset)
//IOWR(base, offset, data)



/*
 * Accept a command from the web interface and
 * active some audio-visual peripheral based on the
 * input from the web interface
 */



/* The main function creates two task and starts multi-tasking */
int main(void){
  
//	printf("START OF MAIN\n");
//
//
//	if(OSTaskCreateExt(motor_test,
//                  		NULL,
//                  		(void *)&motor_test_stk[TASK_STACKSIZE-1],
//                  		MOTOR_TEST_PRIORITY,
//                  		MOTOR_TEST_PRIORITY,
//                  		motor_test_stk,
//                  		TASK_STACKSIZE,
//                  		NULL,
//                  		0))
//	{
//		printf("Motor task creation failure\n");
//	}

	printf("START OF MOTOR\n");

	if(OSTaskCreateExt(camera_test,
                  		NULL,
                  		(void *)&camera_test_stk[TASK_STACKSIZE-1],
                  		CAMERA_TEST_PRIORITY,
                  		CAMERA_TEST_PRIORITY,
                  		camera_test_stk,
                  		TASK_STACKSIZE,
                  		NULL,
                  		0))
	{
		printf("Camera task creation failure\n");
	}

	printf("START OF CAM\n");

	if(OSTaskCreateExt(wifi_test,
                    	NULL,
                    	(void *)&wifi_test_stk[TASK_STACKSIZE-1],
                    	WIFI_TEST_PRIORITY,
                    	WIFI_TEST_PRIORITY,
                    	wifi_test_stk,
                    	TASK_STACKSIZE,
                    	NULL,
                    	0))
	{
		printf("Wifi task creation failure\n");
	}

	printf("START OF WIFI\n");

	//Semaphore
	BUTTON_SEM = OSSemCreate(SEM_INIT_VALUE);
	SENSOR_SEM = OSSemCreate(SEM_INIT_VALUE);

	//Interrupt masks
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(BUTTON_BUTTON_BASE, 0xF);
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(BUTTON_BUTTON_BASE, 0x0);
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(PROX_SENSOR_BASE, 0xF);
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PROX_SENSOR_BASE, 0x0);
//
//	//Interrupt controller
//	if(alt_ic_isr_register(BUTTON_BUTTON_IRQ_INTERRUPT_CONTROLLER_ID,
//					    	BUTTON_BUTTON_IRQ,
//					    	button_interrupt,
//					    	NULL,
//					    	NULL))
//	{
//	  printf("button interrupt failed\n");
//	}
//
//	if(alt_ic_isr_register(PROX_SENSOR_IRQ_INTERRUPT_CONTROLLER_ID,
//					    	PROX_SENSOR_IRQ,
//					    	sensor_interrupt,
//					    	NULL,
//					    	NULL))
//	{
//	  printf("proximity sensor interrupt failed\n");
//	}

	if(alt_ic_isr_register(CAM_UART_IRQ_INTERRUPT_CONTROLLER_ID,
				  	  	   CAM_UART_IRQ,
				  	  	   &cam_uart_interrupt,
				  	  	   NULL,
				  	  	   NULL))
	{
	  printf("cam interrupt failed\n");
	}
    
    if(alt_ic_isr_register(WIFI_UART_IRQ_INTERRUPT_CONTROLLER_ID,
				  	  	   WIFI_UART_IRQ,
				  	  	   &wifi_uart_interrupt,
				  	  	   NULL,
				  	  	   NULL))
	{
	  printf("wifi interrupt failed\n");
	}

	camCommandQueue = OSQCreate(camCommandBuffer, CAM_COMMAND_LENGTH*2);
	camPackageQueue = OSQCreate(camPackageBuffer, CAM_PACKAGE_LENGTH*2);
    wifiPackageQueue = OSQCreate(wifiPackageBuffer, WIFI_PACKAGE_BUFFER_LENGTH);

	printf("END OF MAIN\n");

	OSStart();

	return 0;
}

/******************************************************************************
*                                                                             *
* License Agreement                                                           *
*                                                                             *
* Copyright (c) 2004 Altera Corporation, San Jose, California, USA.           *
* All rights reserved.                                                        *
*                                                                             *
* Permission is hereby granted, free of charge, to any person obtaining a     *
* copy of this software and associated documentation files (the "Software"),  *
* to deal in the Software without restriction, including without limitation   *
* the rights to use, copy, modify, merge, publish, distribute, sublicense,    *
* and/or sell copies of the Software, and to permit persons to whom the       *
* Software is furnished to do so, subject to the following conditions:        *
*                                                                             *
* The above copyright notice and this permission notice shall be included in  *
* all copies or substantial portions of the Software.                         *
*                                                                             *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  *
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,    *
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE *
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER      *
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING     *
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER         *
* DEALINGS IN THE SOFTWARE.                                                   *
*                                                                             *
* This agreement shall be governed in all respects by the laws of the State   *
* of California and by the laws of the United States of America.              *
* Altera does not recommend, suggest or require that this reference design    *
* file be used in conjunction or combination with any other product.          *
******************************************************************************/
