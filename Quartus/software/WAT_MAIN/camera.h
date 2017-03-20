/*
 * camera_test.h
 *
 *  Created on: Mar 1, 2017
 *      Author: Randy Baron
 */

#ifndef CAMERA_TEST_H_
#define CAMERA_TEST_H_

#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>

#include "includes.h"
#include "altera_avalon_uart_regs.h"
#include "wat_main.h"

void camera_task(void* pdata);
void cam_uart_interrupt(void * context);
bool cam_send_command(uint8_t* to_send, uint8_t* to_recieve, uint16_t size, OS_EVENT* used_queue);

/* Redefine stdbool to use project constant names */
#define TRUE   true
#define FALSE  false

/* Definition of camera constants */
#define CAM_COMMAND_LENGTH      6
#define CAM_BITS_PER_PACKAGE	506
#define CAM_DATA_START			3
#define CAM_MAX_ATTEMPTS   		60
#define CAM_INIT_SYNC_DELAY     5
#define CAM_ACK_IGNORE			3

/* Definition of camera commands */
static const uint8_t CAM_SYNC[CAM_COMMAND_LENGTH] = {0xAA, 0x0D, 0x00, 0x00, 0x00, 0x00};
static const uint8_t CAM_INIT[CAM_COMMAND_LENGTH] = {0xAA, 0x01, 0x00, 0x07, 0x07, 0x07};
static const uint8_t CAM_SIZE[CAM_COMMAND_LENGTH] = {0xAA, 0x06, 0x08, 0x00, 0x02, 0x00}; //512 bytes
static const uint8_t CAM_SNAP[CAM_COMMAND_LENGTH] = {0xAA, 0x05, 0x00, 0x00, 0x00, 0x00};
static const uint8_t CAM_GRAB[CAM_COMMAND_LENGTH] = {0xAA, 0x04, 0x01, 0x00, 0x00, 0x00};
static const uint8_t CAM_DATA[CAM_COMMAND_LENGTH] = {0xAA, 0x0A, 0x01, 0x00, 0x00, 0x00}; //NOTE sent by camera, last six bits are the package size

/* Definition of ACK commands to pair with each relevant command
 * NOTE fourth command is actually 0xXX, don't care terms and is ignored
 */
static const uint8_t CAM_ACK_SYNC[CAM_COMMAND_LENGTH] = {0xAA, 0x0E, 0x0D, 0x00, 0x00, 0x00};
static const uint8_t CAM_ACK_INIT[CAM_COMMAND_LENGTH] = {0xAA, 0x0E, 0x01, 0x00, 0x00, 0x00};
static const uint8_t CAM_ACK_SIZE[CAM_COMMAND_LENGTH] = {0xAA, 0x0E, 0x06, 0x00, 0x00, 0x00};
static const uint8_t CAM_ACK_SNAP[CAM_COMMAND_LENGTH] = {0xAA, 0x0E, 0x05, 0x00, 0x00, 0x00};
static const uint8_t CAM_ACK_GRAB[CAM_COMMAND_LENGTH] = {0xAA, 0x0E, 0x04, 0x00, 0x00, 0x00};
static const uint8_t CAM_ACK_DEND[CAM_COMMAND_LENGTH] = {0xAA, 0x0E, 0x00, 0x00, 0xF0, 0xF0};

/* Defintion of the ACK commands for data processing
 * NOTE there are two more commands consisting of the last packet ID
 */
#define CAM_DACK_ONE 0xAA
#define CAM_DACK_TWO 0x0E
#define CAM_DACK_TRE 0x00
#define CAM_DACK_FOR 0x00

/* Definition of global task flow variables*/
bool useData;


#endif /* CAMERA_TEST_H_ */
