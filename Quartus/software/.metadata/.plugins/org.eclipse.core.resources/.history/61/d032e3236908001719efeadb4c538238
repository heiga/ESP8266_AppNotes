/*
 * camera_test.c
 *
 *  Created on: Mar 1, 2017
 *      Author: Randy Baron
 */

#include "camera_test.h"

/*
 * For this test it is assumed that the operator has minimum
 * two monotone images ready. Upon a BUTTON being pressed the
 * camera will take a picture and output the average color
 * value to the terminal. Operator will switch the image and
 * press the button again. A different average color should
 * appear in the terminal. Repeat as needed.
 */
void camera_test(void* pdata){

	uint32_t *leds = GREEN_LEDS_BASE;

	uint16_t q = 0;
	uint16_t z = 0;
	uint8_t err;

	uint8_t cam_reply = 0;
	uint16_t bit_count = 0;
	uint16_t packet_count = 0;
	uint16_t last_packet_byte_count = 0;

	bool isGoodPacket = FALSE;
	uint32_t checksum = 0;
	uint32_t tempsum = 0;
	uint16_t data_length = 0;
	uint8_t cam_data_ack[CAM_COMMAND_LENGTH];
	FILE* picture;

	uint8_t sync_delay = CAM_INIT_SYNC_DELAY;
	bool synced = FALSE;

//	printf("Starting to open...");
//	picture = fopen(CAM_PICTURE_OUTPUT, "a");
//	printf(" and done\n");

	for(q = 0; q< CAM_COMMAND_LENGTH; q++){
		cam_data_ack[q] = CAM_ACK_DATA[q];
	}

	//Reset to deal with any junk transmissions
	for (z = 0; z < CAM_COMMAND_LENGTH; z++){
		while(!(IORD_FIFOED_AVALON_UART_STATUS(CAM_UART_BASE) & FIFOED_AVALON_UART_STATUS_TRDY_MSK));
		IOWR_FIFOED_AVALON_UART_TXDATA(CAM_UART_BASE, CAM_REST[z]);
	}

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
			while(!(IORD_FIFOED_AVALON_UART_STATUS(CAM_UART_BASE) & FIFOED_AVALON_UART_STATUS_TRDY_MSK));
			IOWR_FIFOED_AVALON_UART_TXDATA(CAM_UART_BASE, CAM_SYNC[z]);
		}

		//Wait the recommended sync time as per doc
		OSTimeDlyHMSM(0, 0, 0, sync_delay);

		cam_reply = (uint8_t)OSQAccept(camCommandQueue, &err);
		if (cam_reply == CAM_ACK_SYNC[0]){
			synced = TRUE;
			printf("Receiving %x", cam_reply);
			for (z=1; z < CAM_COMMAND_LENGTH; z++){
				cam_reply = (uint8_t)OSQPend(camCommandQueue, 0, &err);
				if ((cam_reply != CAM_ACK_SYNC[z]) && (z != CAM_ACK_IGNORE)){
					printf("Got %x expected %x\n", cam_reply, CAM_ACK_SYNC[z]);
					synced = FALSE;
					break;
				}else{
					printf(" %x", cam_reply);
				}
			}
			printf("\n");
		}

		if (synced){
			break;
		}else{
			sync_delay++;
		}
	}

	if (synced){
		printf("Cam synced after %i attempts\n", sync_delay);
		*leds = *leds ^ 0xFF;
	}else{
		printf("Cam sync failure after %i attempts\n", sync_delay);
		//return;
	}

	//Send ACK to camera to ACK its SYNC
	for (z=0; z < CAM_COMMAND_LENGTH; z++){
		while(!(IORD_FIFOED_AVALON_UART_STATUS(CAM_UART_BASE) & FIFOED_AVALON_UART_STATUS_TRDY_MSK));
		IOWR_FIFOED_AVALON_UART_TXDATA(CAM_UART_BASE, CAM_ACK_SYNC[z]);
	}

	//Recommended by doc
	OSTimeDlyHMSM(0, 0, 2, 0);

	//Turn on camera
	printf("INIT ");
	if(!cam_send_command(CAM_INIT, CAM_ACK_INIT, CAM_COMMAND_LENGTH, camCommandQueue)){
		printf("Error at init\n");
	}

	//Send package size into to camera
	printf("SIZE ");
	if(!cam_send_command(CAM_SIZE, CAM_ACK_SIZE, CAM_COMMAND_LENGTH, camCommandQueue)){
		printf("Error at size\n");
	}

	//Tell camera to take picture
	printf("SNAP ");
	if(!cam_send_command(CAM_SNAP, CAM_ACK_SNAP, CAM_COMMAND_LENGTH, camCommandQueue)){
		printf("Error at snap\n");
	}

	//Tell camera to start sending the picture
	printf("GRAB ");
	if(!cam_send_command(CAM_GRAB, CAM_ACK_GRAB, CAM_COMMAND_LENGTH, camCommandQueue)){
		printf("Error at grab\n");
	}

	//Receive the package count, not an ACK and needs special parsing
	printf ("PARSE ");
	cam_reply = (uint8_t)OSQPend(camCommandQueue, 0, &err);
	if (cam_reply == CAM_DATA[0]){
		printf("receiving %x", cam_reply);
		for (z = 1; z < CAM_DATA_START; z++){
			cam_reply = (uint8_t)OSQPend(camCommandQueue, 0, &err);
			if ((cam_reply != CAM_DATA[z])){
				printf("got %x expected %x\n", cam_reply, CAM_DATA[z]);
			}else{
				printf(" %x", cam_reply);
			}
		}
		//The last three packages will contain the packet count
		//Need to account for the byte offsets and get a single
		//integer value that contains the total number of bits
		//that will be sent by the camera

		bit_count = 0;
		cam_reply = (uint8_t)OSQPend(camCommandQueue, 0, &err);
		printf(" %x", cam_reply);
		bit_count = cam_reply;

		cam_reply = (uint8_t)OSQPend(camCommandQueue, 0, &err);
		printf(" %lx", cam_reply);
		bit_count = bit_count + (0x100 * cam_reply);

		cam_reply = (uint8_t)OSQPend(camCommandQueue, 0, &err);
		printf(" %x", cam_reply);
		bit_count = bit_count + (0x10000 * cam_reply);
		printf("\nByte count of %i\n", bit_count);

		//Determine the number of packets based on the given bit values
		packet_count = (bit_count / (CAM_PACKAGE_LENGTH - 6)) + 1;
		last_packet_byte_count = bit_count % (CAM_PACKAGE_LENGTH - 6);
		printf("Expecting %i total packets with final one being %i bits\n", packet_count, last_packet_byte_count);
	}else{
		printf("got %x expected %x\n", cam_reply, CAM_DATA[0]);
	}

	//TODO clean up numbers here once operational
	//Receive data, start with normal packets
	useData = TRUE;
	synced = TRUE;
	q = 0;
	printf("DATA STARTING\n");
	while(q < packet_count){

		//Prepare for next iteration
		isGoodPacket = TRUE;
		checksum = 0;
		tempsum = 0;
		//TODO fix this if the self recovery from NAK is built in
		if (q == (packet_count - 1)){
			data_length = last_packet_byte_count;
		}else{
			data_length = CAM_PACKAGE_LENGTH - 2;
		}

		OSQFlush(camPackageQueue);

		//Indicate which packet we intend to receive
		cam_data_ack[4] = q;
		for (z = 0; z < CAM_COMMAND_LENGTH; z++){
			while(!(IORD_FIFOED_AVALON_UART_STATUS(CAM_UART_BASE) & FIFOED_AVALON_UART_STATUS_TRDY_MSK));
			IOWR_FIFOED_AVALON_UART_TXDATA(CAM_UART_BASE, cam_data_ack[z]);
		}

		//First two bytes are ID, make sure they match the ID we want
		for(z = 0; z < 2; z++){
			if(isGoodPacket){
				cam_reply = (uint8_t)OSQPend(camPackageQueue, MAX_TIME, &err);
				if(err == OS_TIMEOUT){
					printf("TIMEOUT AT ID\n");
					isGoodPacket = FALSE;
				}else{
					if((cam_reply != (1 + cam_data_ack[z+4])) && (cam_reply != 0)){
						isGoodPacket = FALSE;
						printf("Packet %i ID expected %x but got %x\n", q, cam_data_ack[z+4], cam_reply);
					}
				}
			}
		}
		if (isGoodPacket){
			printf("ID checked\n");
			printf("Packet %i has size of ", q);
		}

		//Next two bytes are data size, print it out until I decide what to do with it
		//Should be LOWER_BYTE UPPER_BYTE of data size and should equal PACKAGE_LENGTH - 6
		//until of course we hit the final packet so it might be a good dea to use this
		//as the loop counter for data parsing loop
		for(z = 0; z < 2; z++){
			if(isGoodPacket){
				cam_reply = (uint8_t)OSQPend(camPackageQueue, MAX_TIME, &err);
				if(err == OS_TIMEOUT){
					printf("TIMEOUT AT SIZE\n");
					isGoodPacket = FALSE;
				}else{
					//TODO add parsing of data size
					printf("%x ", cam_reply);
				}
			}
		}
		printf("\n");

		for(z = 4; z < data_length; z++){
			if(isGoodPacket){
				cam_reply = (uint8_t)OSQPend(camPackageQueue, MAX_TIME, &err);
				if(err == OS_TIMEOUT){
					printf("TIMEOUT AT DATA on byte %i\n", z);
					isGoodPacket = FALSE;
					cam_reply = 0x00;
				}else{
					checksum = checksum + cam_reply;
				}
			}else{
				cam_reply = 0x00;
			}
			//putc(cam_reply, picture);
		}

		//Next two bytes are checksum
		for (z = 0; z < 2; z++){
			if(isGoodPacket){
				cam_reply = (uint8_t)OSQPend(camPackageQueue, MAX_TIME, &err);
				if(err == OS_TIMEOUT){
					printf("TIMEOUT AT CHECKSUM");
					isGoodPacket = FALSE;
				}else{
					tempsum = tempsum + (cam_reply << (8*z));
				}
			}
		}

		if (checksum != tempsum){
			printf("Invalid checksum, got %x expected %x\n", checksum, tempsum);
			//isGoodPacket = FALSE;
		}

		if(isGoodPacket){
			printf("Packet %i good\n", q);
			q++;
		}else{
			printf("Packet %i bad, moving on\n", q);
			//OSTimeDlyHMSM(0, 0, 1, 0);
			q++;
			synced = FALSE;
		}
	}

	if (synced){
		printf("Camera done perfect\n");
	}else{
		printf("Camera done with err\n");
	}

	for (z = 0; z < CAM_COMMAND_LENGTH; z++){
		while(!(IORD_FIFOED_AVALON_UART_STATUS(CAM_UART_BASE) & FIFOED_AVALON_UART_STATUS_TRDY_MSK));
		IOWR_FIFOED_AVALON_UART_TXDATA(CAM_UART_BASE, CAM_ACK_DEND[z]);
	}

	fclose(picture);

	while (1){
		//wait for button push
		//OSSemPend(FREQ_SEM, 0, &err);

		OSTimeDlyHMSM(0, 0, 1, 0);
	}
}

bool cam_send_command(uint8_t* to_send, uint8_t* to_recieve, uint16_t size, OS_EVENT* used_queue){

	uint8_t z;
	uint8_t err;
	uint8_t cam_reply;

	//Flush queue so we know we have an empty one
	OSQFlush(used_queue);
	for (z = 0; z < size; z++){
		while(!(IORD_FIFOED_AVALON_UART_STATUS(CAM_UART_BASE) & FIFOED_AVALON_UART_STATUS_TRDY_MSK));
		IOWR_FIFOED_AVALON_UART_TXDATA(CAM_UART_BASE, to_send[z]);
	}

	cam_reply = (uint8_t)OSQPend(used_queue, 0, &err);
	if (cam_reply == to_recieve[0]){
		printf("receiving %x", cam_reply);
		for (z = 1; z < size; z++){
			cam_reply = (uint8_t)OSQPend(used_queue, 0, &err);
			if ((cam_reply != to_recieve[z]) && (z != CAM_ACK_IGNORE)){
				printf("got %x expected %x\n", cam_reply, to_recieve[z]);
				return FALSE;
			}else{
				printf(" %x", cam_reply);
			}
		}
		printf("\n");
	}else{
		printf("got %x expected %x\n", cam_reply, to_recieve[0]);
		return FALSE;
	}

	return TRUE;
}

void cam_uart_interrupt(void * context){
	uint8_t read = 0;

	while(!(IORD_FIFOED_AVALON_UART_STATUS(CAM_UART_BASE) & FIFOED_AVALON_UART_STATUS_RRDY_MSK));
	read = IORD_FIFOED_AVALON_UART_RXDATA(CAM_UART_BASE);

	if (useData){
		OSQPost(camPackageQueue, (void*) read);
	}else{
		OSQPost(camCommandQueue, (void*) read);
	}
}

void button_interrupt(void * context){
	printf("button\n");
	OSTimeDlyHMSM(0, 0, 0, 400);

	//clear interrupt
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(BUTTON_BUTTON_BASE, 1);
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(BUTTON_BUTTON_BASE, 0xF);

	//post semaphore for camera
	OSSemPost(BUTTON_SEM);
}
