/*
 * camera_test.c
 *
 *  Created on: Mar 1, 2017
 *      Author: Randy Baron
 */

#include "camera.h"

/*
 * For this test it is assumed that the operator has minimum
 * two monotone images ready. Upon a BUTTON being pressed the
 * camera will take a picture and output the average color
 * value to the terminal. Operator will switch the image and
 * press the button again. A different average color should
 * appear in the terminal. Repeat as needed.
 */
void camera_task(void* pdata){

	uint32_t *leds = GREEN_LEDS_BASE;

	uint8_t q = 0;
	uint8_t z = 0;

	uint8_t err;
	uint8_t findCommand;
	uint32_t moveCommand;

	uint8_t cam_reply = 0;
	uint16_t bit_count = 0;
	uint16_t packet_count = 0;
	uint16_t last_packet_bit_count = 0;

	uint8_t sync_delay = CAM_INIT_SYNC_DELAY;
	bool synced = FALSE;

	while (1){

		findCommand = (uint8_t) OSQPend(findCommandQueue, 0, &err);

		/*
		* Synchronise with camera
		* Documentation mentions this will take 25-60 attempts
		* Recommends an increasing delay between attempts
		* with an initial time of 5ms
		*/

		useData = FALSE;
		for (q=0; q < CAM_MAX_ATTEMPTS; q++){
			//Assume false until proven otherwise
			synced = FALSE;

			//Send the sync command
			for (z=0; z < CAM_COMMAND_LENGTH; z++){
				while(!(IORD_ALTERA_AVALON_UART_STATUS(CAM_UART_BASE) & ALTERA_AVALON_UART_STATUS_TRDY_MSK));
				IOWR_ALTERA_AVALON_UART_TXDATA(CAM_UART_BASE, CAM_SYNC[z]);
			}

			//Wait the recommended sync time as per doc
			OSTimeDlyHMSM(0, 0, 0, sync_delay);

			cam_reply = (uint8_t)OSQAccept(camCommandQueue, &err);
			if (cam_reply == CAM_ACK_SYNC[0]){
				synced = TRUE;
				////printf("Receiving %x", cam_reply);
				for (z=1; z < CAM_COMMAND_LENGTH; z++){
					cam_reply = (uint8_t)OSQPend(camCommandQueue, 0, &err);
					if ((cam_reply != CAM_ACK_SYNC[z]) && (z != CAM_ACK_IGNORE)){
						//printf("Got %x expected %x\n", cam_reply, CAM_ACK_SYNC[z]);
						synced = FALSE;
						break;
					}else{
						//printf(" %x", cam_reply);
					}
				}
				//printf("\n");
			}

			if (synced){
				break;
			}else{
				sync_delay++;
			}
		}

		if (synced){
			//printf("Cam synced after %i attempts\n", sync_delay);
			*leds = *leds ^ 0xFF;
		}else{
			//printf("Cam sync failure after %i attempts\n", sync_delay);
			//return;
		}

		//Send ACK to camera to ACK its SYNC
		for (z=0; z < CAM_COMMAND_LENGTH; z++){
			while(!(IORD_ALTERA_AVALON_UART_STATUS(CAM_UART_BASE) & ALTERA_AVALON_UART_STATUS_TRDY_MSK));
			IOWR_ALTERA_AVALON_UART_TXDATA(CAM_UART_BASE, CAM_ACK_SYNC[z]);
		}

		//Turn on camera
		//printf("INIT ");
		if(!cam_send_command(CAM_INIT, CAM_ACK_INIT, CAM_COMMAND_LENGTH, camCommandQueue)){
			//printf("Error at grab\n");
		}

		//Send package size into to camera
		//printf("SIZE ");
		if(!cam_send_command(CAM_SIZE, CAM_ACK_SIZE, CAM_COMMAND_LENGTH, camCommandQueue)){
			//printf("Error at grab\n");
		}

		//Tell camera to take picture
		//printf("SNAP ");
		if(!cam_send_command(CAM_SNAP, CAM_ACK_SNAP, CAM_COMMAND_LENGTH, camCommandQueue)){
			//printf("Error at grab\n");
		}

		//Tell camera to start sending the picture
		//printf("GRAB ");
		if(!cam_send_command(CAM_GRAB, CAM_ACK_GRAB, CAM_COMMAND_LENGTH, camCommandQueue)){
			//printf("Error at grab\n");
		}

		//Receive the package count, not an ACK and needs special parsing
		//printf ("DATA ");
		cam_reply = (uint8_t)OSQPend(camCommandQueue, 0, &err);
		if (cam_reply == CAM_DATA[0]){
			//printf("receiving %x", cam_reply);
			for (z = 1; z < CAM_DATA_START; z++){
				cam_reply = (uint8_t)OSQPend(camCommandQueue, 0, &err);
				if ((cam_reply != CAM_DATA[z])){
					//printf("got %x expected %x\n", cam_reply, CAM_DATA[z]);
				}else{
					//printf(" %x", cam_reply);
				}
			}
			//The last three packages will contain the packet count
			//Need to account for the byte offsets and get a single
			//integer value that contains the total number of bits
			//that will be sent by the camera

			bit_count = 0;
			cam_reply = (uint8_t)OSQPend(camCommandQueue, 0, &err);
			//printf(" %x", cam_reply);
			bit_count = cam_reply;

			cam_reply = (uint8_t)OSQPend(camCommandQueue, 0, &err);
			//printf(" %x", cam_reply);
			bit_count = bit_count + (0x100 * cam_reply);

			cam_reply = (uint8_t)OSQPend(camCommandQueue, 0, &err);
			//printf(" %x", cam_reply);
			bit_count = bit_count + (0x10000 * cam_reply);
			//printf("\nBit count of %i\n", bit_count);

			//Determine the number of packets based on the given bit values
			packet_count = bit_count / CAM_BITS_PER_PACKAGE;
			last_packet_bit_count = bit_count % CAM_BITS_PER_PACKAGE;
			//printf("Expecting %i normal packets with final one being %i bits\n", packet_count, last_packet_bit_count);
		}else{
			//printf("got %x expected %x\n", cam_reply, CAM_DATA[0]);
		}

		//Receive data packets

		//Pass into image processing algorithm
		//NOTE this is currently located in localtest
		//as the library it depends on has not been added
		//the result will be parsed into the 32 bit moveCommand

		//Give instructions to motor
		OSQPost(moveCommandQueue, (void*) moveCommand);
	}
}

bool cam_send_command(uint8_t* to_send, uint8_t* to_recieve, uint16_t size, OS_EVENT* used_queue){

	uint8_t z;
	uint8_t err;
	uint8_t cam_reply;

	//Flush queue so we know we have an empty one
	OSQFlush(used_queue);
	for (z = 0; z < size; z++){
		while(!(IORD_ALTERA_AVALON_UART_STATUS(CAM_UART_BASE) & ALTERA_AVALON_UART_STATUS_TRDY_MSK));
		IOWR_ALTERA_AVALON_UART_TXDATA(CAM_UART_BASE, to_send[z]);
	}

	cam_reply = (uint8_t)OSQPend(used_queue, 0, &err);
	if (cam_reply == to_recieve[0]){
		//printf("receiving %x", cam_reply);
		for (z = 1; z < size; z++){
			cam_reply = (uint8_t)OSQPend(used_queue, 0, &err);
			if ((cam_reply != to_recieve[z]) && (z != CAM_ACK_IGNORE)){
				//printf("got %x expected %x\n", cam_reply, to_recieve[z]);
				return FALSE;
			}else{
				//printf(" %x", cam_reply);
			}
		}
		//printf("\n");
	}else{
		//printf("got %x expected %x\n", cam_reply, to_recieve[0]);
		return FALSE;
	}

	return TRUE;
}

void cam_uart_interrupt(void * context){
	uint8_t read = 0;

	while(!(IORD_ALTERA_AVALON_UART_STATUS(CAM_UART_BASE) & ALTERA_AVALON_UART_STATUS_RRDY_MSK));
	read = IORD_ALTERA_AVALON_UART_RXDATA(CAM_UART_BASE);

	if (useData){
		OSQPost(camPackageQueue, (void*) read);
	}else{
		OSQPost(camCommandQueue, (void*) read);
	}
}
