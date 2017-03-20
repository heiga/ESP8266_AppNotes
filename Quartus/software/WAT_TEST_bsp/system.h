/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_gen2_0' in SOPC Builder design 'trolley_system'
 * SOPC Builder design path: ../../trolley_system.sopcinfo
 *
 * Generated: Fri Mar 17 17:38:55 MDT 2017
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x01009820
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x19
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x01004020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x19
#define ALT_CPU_NAME "nios2_gen2_0"
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x01009000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x01009820
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x19
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x01004020
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x19
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x01009000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_EPCS_FLASH_CONTROLLER
#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_NEW_SDRAM_CONTROLLER
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __ALTERA_AVALON_UART
#define __ALTERA_NIOS2_GEN2
#define __FIFOED_AVALON_UART


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone IV E"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart_0"
#define ALT_STDERR_BASE 0x100a108
#define ALT_STDERR_DEV jtag_uart_0
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart_0"
#define ALT_STDIN_BASE 0x100a108
#define ALT_STDIN_DEV jtag_uart_0
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart_0"
#define ALT_STDOUT_BASE 0x100a108
#define ALT_STDOUT_DEV jtag_uart_0
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "trolley_system"


/*
 * altera_hostfs configuration
 *
 */

#define ALTERA_HOSTFS_NAME "/mnt/host"


/*
 * button_button configuration
 *
 */

#define ALT_MODULE_CLASS_button_button altera_avalon_pio
#define BUTTON_BUTTON_BASE 0x100a0b0
#define BUTTON_BUTTON_BIT_CLEARING_EDGE_REGISTER 1
#define BUTTON_BUTTON_BIT_MODIFYING_OUTPUT_REGISTER 0
#define BUTTON_BUTTON_CAPTURE 1
#define BUTTON_BUTTON_DATA_WIDTH 1
#define BUTTON_BUTTON_DO_TEST_BENCH_WIRING 0
#define BUTTON_BUTTON_DRIVEN_SIM_VALUE 0
#define BUTTON_BUTTON_EDGE_TYPE "FALLING"
#define BUTTON_BUTTON_FREQ 50000000
#define BUTTON_BUTTON_HAS_IN 1
#define BUTTON_BUTTON_HAS_OUT 0
#define BUTTON_BUTTON_HAS_TRI 0
#define BUTTON_BUTTON_IRQ 3
#define BUTTON_BUTTON_IRQ_INTERRUPT_CONTROLLER_ID 0
#define BUTTON_BUTTON_IRQ_TYPE "LEVEL"
#define BUTTON_BUTTON_NAME "/dev/button_button"
#define BUTTON_BUTTON_RESET_VALUE 0
#define BUTTON_BUTTON_SPAN 16
#define BUTTON_BUTTON_TYPE "altera_avalon_pio"


/*
 * button_led configuration
 *
 */

#define ALT_MODULE_CLASS_button_led altera_avalon_pio
#define BUTTON_LED_BASE 0x100a0a0
#define BUTTON_LED_BIT_CLEARING_EDGE_REGISTER 0
#define BUTTON_LED_BIT_MODIFYING_OUTPUT_REGISTER 0
#define BUTTON_LED_CAPTURE 0
#define BUTTON_LED_DATA_WIDTH 1
#define BUTTON_LED_DO_TEST_BENCH_WIRING 0
#define BUTTON_LED_DRIVEN_SIM_VALUE 0
#define BUTTON_LED_EDGE_TYPE "NONE"
#define BUTTON_LED_FREQ 50000000
#define BUTTON_LED_HAS_IN 0
#define BUTTON_LED_HAS_OUT 1
#define BUTTON_LED_HAS_TRI 0
#define BUTTON_LED_IRQ -1
#define BUTTON_LED_IRQ_INTERRUPT_CONTROLLER_ID -1
#define BUTTON_LED_IRQ_TYPE "NONE"
#define BUTTON_LED_NAME "/dev/button_led"
#define BUTTON_LED_RESET_VALUE 0
#define BUTTON_LED_SPAN 16
#define BUTTON_LED_TYPE "altera_avalon_pio"


/*
 * cam_uart configuration
 *
 */

#define ALT_MODULE_CLASS_cam_uart fifoed_avalon_uart
#define CAM_UART_ADD_ERROR_BITS 0
#define CAM_UART_BASE 0x100a000
#define CAM_UART_BAUD 57600
#define CAM_UART_DATA_BITS 8
#define CAM_UART_FIFO_EXPORT_USED 0
#define CAM_UART_FIXED_BAUD 1
#define CAM_UART_FREQ 50000000
#define CAM_UART_GAP_VALUE 4
#define CAM_UART_IRQ 7
#define CAM_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define CAM_UART_NAME "/dev/cam_uart"
#define CAM_UART_PARITY 'N'
#define CAM_UART_PASS_ERROR_BITS 0
#define CAM_UART_RX_FIFO_LE 0
#define CAM_UART_RX_FIFO_SIZE 512
#define CAM_UART_RX_IRQ_THRESHOLD 1
#define CAM_UART_SIM_CHAR_STREAM ""
#define CAM_UART_SIM_TRUE_BAUD 0
#define CAM_UART_SPAN 64
#define CAM_UART_STOP_BITS 1
#define CAM_UART_SYNC_REG_DEPTH 2
#define CAM_UART_TIMEOUT_VALUE 4
#define CAM_UART_TIMESTAMP_WIDTH 8
#define CAM_UART_TRANSMIT_PIN 0
#define CAM_UART_TX_FIFO_LE 0
#define CAM_UART_TX_FIFO_SIZE 8
#define CAM_UART_TX_IRQ_THRESHOLD 1
#define CAM_UART_TYPE "fifoed_avalon_uart"
#define CAM_UART_UHW_CTS 0
#define CAM_UART_USE_CTS_RTS 0
#define CAM_UART_USE_EOP_REGISTER 0
#define CAM_UART_USE_EXT_TIMESTAMP 0
#define CAM_UART_USE_GAP_DETECTION 0
#define CAM_UART_USE_RX_FIFO 1
#define CAM_UART_USE_RX_TIMEOUT 0
#define CAM_UART_USE_STATUS_BIT_CLEAR 0
#define CAM_UART_USE_TIMESTAMP 0
#define CAM_UART_USE_TX_FIFO 0


/*
 * epcs_flash_controller_0 configuration
 *
 */

#define ALT_MODULE_CLASS_epcs_flash_controller_0 altera_avalon_epcs_flash_controller
#define EPCS_FLASH_CONTROLLER_0_BASE 0x1009000
#define EPCS_FLASH_CONTROLLER_0_IRQ 5
#define EPCS_FLASH_CONTROLLER_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define EPCS_FLASH_CONTROLLER_0_NAME "/dev/epcs_flash_controller_0"
#define EPCS_FLASH_CONTROLLER_0_REGISTER_OFFSET 1024
#define EPCS_FLASH_CONTROLLER_0_SPAN 2048
#define EPCS_FLASH_CONTROLLER_0_TYPE "altera_avalon_epcs_flash_controller"


/*
 * green_leds configuration
 *
 */

#define ALT_MODULE_CLASS_green_leds altera_avalon_pio
#define GREEN_LEDS_BASE 0x100a0c0
#define GREEN_LEDS_BIT_CLEARING_EDGE_REGISTER 0
#define GREEN_LEDS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define GREEN_LEDS_CAPTURE 0
#define GREEN_LEDS_DATA_WIDTH 8
#define GREEN_LEDS_DO_TEST_BENCH_WIRING 0
#define GREEN_LEDS_DRIVEN_SIM_VALUE 0
#define GREEN_LEDS_EDGE_TYPE "NONE"
#define GREEN_LEDS_FREQ 50000000
#define GREEN_LEDS_HAS_IN 0
#define GREEN_LEDS_HAS_OUT 1
#define GREEN_LEDS_HAS_TRI 0
#define GREEN_LEDS_IRQ -1
#define GREEN_LEDS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define GREEN_LEDS_IRQ_TYPE "NONE"
#define GREEN_LEDS_NAME "/dev/green_leds"
#define GREEN_LEDS_RESET_VALUE 0
#define GREEN_LEDS_SPAN 16
#define GREEN_LEDS_TYPE "altera_avalon_pio"


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 32
#define ALT_SYS_CLK TIMER_0
#define ALT_TIMESTAMP_CLK none


/*
 * jtag_uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart_0 altera_avalon_jtag_uart
#define JTAG_UART_0_BASE 0x100a108
#define JTAG_UART_0_IRQ 0
#define JTAG_UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_0_NAME "/dev/jtag_uart_0"
#define JTAG_UART_0_READ_DEPTH 64
#define JTAG_UART_0_READ_THRESHOLD 8
#define JTAG_UART_0_SPAN 8
#define JTAG_UART_0_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_0_WRITE_DEPTH 64
#define JTAG_UART_0_WRITE_THRESHOLD 8


/*
 * key configuration
 *
 */

#define ALT_MODULE_CLASS_key altera_avalon_pio
#define KEY_BASE 0x100a080
#define KEY_BIT_CLEARING_EDGE_REGISTER 0
#define KEY_BIT_MODIFYING_OUTPUT_REGISTER 0
#define KEY_CAPTURE 0
#define KEY_DATA_WIDTH 1
#define KEY_DO_TEST_BENCH_WIRING 0
#define KEY_DRIVEN_SIM_VALUE 0
#define KEY_EDGE_TYPE "NONE"
#define KEY_FREQ 50000000
#define KEY_HAS_IN 1
#define KEY_HAS_OUT 0
#define KEY_HAS_TRI 0
#define KEY_IRQ 6
#define KEY_IRQ_INTERRUPT_CONTROLLER_ID 0
#define KEY_IRQ_TYPE "LEVEL"
#define KEY_NAME "/dev/key"
#define KEY_RESET_VALUE 0
#define KEY_SPAN 16
#define KEY_TYPE "altera_avalon_pio"


/*
 * motor_l configuration
 *
 */

#define ALT_MODULE_CLASS_motor_l altera_avalon_pio
#define MOTOR_L_BASE 0x100a0d0
#define MOTOR_L_BIT_CLEARING_EDGE_REGISTER 0
#define MOTOR_L_BIT_MODIFYING_OUTPUT_REGISTER 0
#define MOTOR_L_CAPTURE 0
#define MOTOR_L_DATA_WIDTH 3
#define MOTOR_L_DO_TEST_BENCH_WIRING 0
#define MOTOR_L_DRIVEN_SIM_VALUE 0
#define MOTOR_L_EDGE_TYPE "NONE"
#define MOTOR_L_FREQ 50000000
#define MOTOR_L_HAS_IN 0
#define MOTOR_L_HAS_OUT 1
#define MOTOR_L_HAS_TRI 0
#define MOTOR_L_IRQ -1
#define MOTOR_L_IRQ_INTERRUPT_CONTROLLER_ID -1
#define MOTOR_L_IRQ_TYPE "NONE"
#define MOTOR_L_NAME "/dev/motor_l"
#define MOTOR_L_RESET_VALUE 0
#define MOTOR_L_SPAN 16
#define MOTOR_L_TYPE "altera_avalon_pio"


/*
 * motor_r configuration
 *
 */

#define ALT_MODULE_CLASS_motor_r altera_avalon_pio
#define MOTOR_R_BASE 0x100a0e0
#define MOTOR_R_BIT_CLEARING_EDGE_REGISTER 0
#define MOTOR_R_BIT_MODIFYING_OUTPUT_REGISTER 0
#define MOTOR_R_CAPTURE 0
#define MOTOR_R_DATA_WIDTH 3
#define MOTOR_R_DO_TEST_BENCH_WIRING 0
#define MOTOR_R_DRIVEN_SIM_VALUE 0
#define MOTOR_R_EDGE_TYPE "NONE"
#define MOTOR_R_FREQ 50000000
#define MOTOR_R_HAS_IN 0
#define MOTOR_R_HAS_OUT 1
#define MOTOR_R_HAS_TRI 0
#define MOTOR_R_IRQ -1
#define MOTOR_R_IRQ_INTERRUPT_CONTROLLER_ID -1
#define MOTOR_R_IRQ_TYPE "NONE"
#define MOTOR_R_NAME "/dev/motor_r"
#define MOTOR_R_RESET_VALUE 0
#define MOTOR_R_SPAN 16
#define MOTOR_R_TYPE "altera_avalon_pio"


/*
 * onchip_memory2_0 configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_memory2_0 altera_avalon_onchip_memory2
#define ONCHIP_MEMORY2_0_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEMORY2_0_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEMORY2_0_BASE 0x1004000
#define ONCHIP_MEMORY2_0_CONTENTS_INFO ""
#define ONCHIP_MEMORY2_0_DUAL_PORT 0
#define ONCHIP_MEMORY2_0_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_0_INIT_CONTENTS_FILE "trolley_system_onchip_memory2_0"
#define ONCHIP_MEMORY2_0_INIT_MEM_CONTENT 1
#define ONCHIP_MEMORY2_0_INSTANCE_ID "NONE"
#define ONCHIP_MEMORY2_0_IRQ -1
#define ONCHIP_MEMORY2_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEMORY2_0_NAME "/dev/onchip_memory2_0"
#define ONCHIP_MEMORY2_0_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEMORY2_0_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_0_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEMORY2_0_SINGLE_CLOCK_OP 0
#define ONCHIP_MEMORY2_0_SIZE_MULTIPLE 1
#define ONCHIP_MEMORY2_0_SIZE_VALUE 16384
#define ONCHIP_MEMORY2_0_SPAN 16384
#define ONCHIP_MEMORY2_0_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEMORY2_0_WRITABLE 1


/*
 * prox_sensor configuration
 *
 */

#define ALT_MODULE_CLASS_prox_sensor altera_avalon_pio
#define PROX_SENSOR_BASE 0x100a0f0
#define PROX_SENSOR_BIT_CLEARING_EDGE_REGISTER 1
#define PROX_SENSOR_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PROX_SENSOR_CAPTURE 1
#define PROX_SENSOR_DATA_WIDTH 1
#define PROX_SENSOR_DO_TEST_BENCH_WIRING 0
#define PROX_SENSOR_DRIVEN_SIM_VALUE 0
#define PROX_SENSOR_EDGE_TYPE "FALLING"
#define PROX_SENSOR_FREQ 50000000
#define PROX_SENSOR_HAS_IN 1
#define PROX_SENSOR_HAS_OUT 0
#define PROX_SENSOR_HAS_TRI 0
#define PROX_SENSOR_IRQ 2
#define PROX_SENSOR_IRQ_INTERRUPT_CONTROLLER_ID 0
#define PROX_SENSOR_IRQ_TYPE "LEVEL"
#define PROX_SENSOR_NAME "/dev/prox_sensor"
#define PROX_SENSOR_RESET_VALUE 0
#define PROX_SENSOR_SPAN 16
#define PROX_SENSOR_TYPE "altera_avalon_pio"


/*
 * sdram_controller_0 configuration
 *
 */

#define ALT_MODULE_CLASS_sdram_controller_0 altera_avalon_new_sdram_controller
#define SDRAM_CONTROLLER_0_BASE 0x800000
#define SDRAM_CONTROLLER_0_CAS_LATENCY 3
#define SDRAM_CONTROLLER_0_CONTENTS_INFO
#define SDRAM_CONTROLLER_0_INIT_NOP_DELAY 0.0
#define SDRAM_CONTROLLER_0_INIT_REFRESH_COMMANDS 2
#define SDRAM_CONTROLLER_0_IRQ -1
#define SDRAM_CONTROLLER_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SDRAM_CONTROLLER_0_IS_INITIALIZED 1
#define SDRAM_CONTROLLER_0_NAME "/dev/sdram_controller_0"
#define SDRAM_CONTROLLER_0_POWERUP_DELAY 100.0
#define SDRAM_CONTROLLER_0_REFRESH_PERIOD 15.625
#define SDRAM_CONTROLLER_0_REGISTER_DATA_IN 1
#define SDRAM_CONTROLLER_0_SDRAM_ADDR_WIDTH 0x16
#define SDRAM_CONTROLLER_0_SDRAM_BANK_WIDTH 2
#define SDRAM_CONTROLLER_0_SDRAM_COL_WIDTH 8
#define SDRAM_CONTROLLER_0_SDRAM_DATA_WIDTH 16
#define SDRAM_CONTROLLER_0_SDRAM_NUM_BANKS 4
#define SDRAM_CONTROLLER_0_SDRAM_NUM_CHIPSELECTS 1
#define SDRAM_CONTROLLER_0_SDRAM_ROW_WIDTH 12
#define SDRAM_CONTROLLER_0_SHARED_DATA 0
#define SDRAM_CONTROLLER_0_SIM_MODEL_BASE 0
#define SDRAM_CONTROLLER_0_SPAN 8388608
#define SDRAM_CONTROLLER_0_STARVATION_INDICATOR 0
#define SDRAM_CONTROLLER_0_TRISTATE_BRIDGE_SLAVE ""
#define SDRAM_CONTROLLER_0_TYPE "altera_avalon_new_sdram_controller"
#define SDRAM_CONTROLLER_0_T_AC 5.5
#define SDRAM_CONTROLLER_0_T_MRD 3
#define SDRAM_CONTROLLER_0_T_RCD 20.0
#define SDRAM_CONTROLLER_0_T_RFC 70.0
#define SDRAM_CONTROLLER_0_T_RP 20.0
#define SDRAM_CONTROLLER_0_T_WR 14.0


/*
 * speaker configuration
 *
 */

#define ALT_MODULE_CLASS_speaker altera_avalon_pio
#define SPEAKER_BASE 0x100a090
#define SPEAKER_BIT_CLEARING_EDGE_REGISTER 0
#define SPEAKER_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SPEAKER_CAPTURE 0
#define SPEAKER_DATA_WIDTH 1
#define SPEAKER_DO_TEST_BENCH_WIRING 0
#define SPEAKER_DRIVEN_SIM_VALUE 0
#define SPEAKER_EDGE_TYPE "NONE"
#define SPEAKER_FREQ 50000000
#define SPEAKER_HAS_IN 0
#define SPEAKER_HAS_OUT 1
#define SPEAKER_HAS_TRI 0
#define SPEAKER_IRQ -1
#define SPEAKER_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SPEAKER_IRQ_TYPE "NONE"
#define SPEAKER_NAME "/dev/speaker"
#define SPEAKER_RESET_VALUE 0
#define SPEAKER_SPAN 16
#define SPEAKER_TYPE "altera_avalon_pio"


/*
 * sysid_qsys_0 configuration
 *
 */

#define ALT_MODULE_CLASS_sysid_qsys_0 altera_avalon_sysid_qsys
#define SYSID_QSYS_0_BASE 0x100a100
#define SYSID_QSYS_0_ID 0
#define SYSID_QSYS_0_IRQ -1
#define SYSID_QSYS_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_QSYS_0_NAME "/dev/sysid_qsys_0"
#define SYSID_QSYS_0_SPAN 8
#define SYSID_QSYS_0_TIMESTAMP 1489793743
#define SYSID_QSYS_0_TYPE "altera_avalon_sysid_qsys"


/*
 * timer_0 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_0 altera_avalon_timer
#define TIMER_0_ALWAYS_RUN 0
#define TIMER_0_BASE 0x100a040
#define TIMER_0_COUNTER_SIZE 32
#define TIMER_0_FIXED_PERIOD 0
#define TIMER_0_FREQ 50000000
#define TIMER_0_IRQ 4
#define TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_0_LOAD_VALUE 49999
#define TIMER_0_MULT 0.001
#define TIMER_0_NAME "/dev/timer_0"
#define TIMER_0_PERIOD 1
#define TIMER_0_PERIOD_UNITS "ms"
#define TIMER_0_RESET_OUTPUT 0
#define TIMER_0_SNAPSHOT 1
#define TIMER_0_SPAN 32
#define TIMER_0_TICKS_PER_SEC 1000
#define TIMER_0_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_0_TYPE "altera_avalon_timer"


/*
 * ucosii configuration
 *
 */

#define OS_ARG_CHK_EN 1
#define OS_CPU_HOOKS_EN 1
#define OS_DEBUG_EN 1
#define OS_EVENT_NAME_SIZE 32
#define OS_FLAGS_NBITS 16
#define OS_FLAG_ACCEPT_EN 1
#define OS_FLAG_DEL_EN 1
#define OS_FLAG_EN 1
#define OS_FLAG_NAME_SIZE 32
#define OS_FLAG_QUERY_EN 1
#define OS_FLAG_WAIT_CLR_EN 1
#define OS_LOWEST_PRIO 20
#define OS_MAX_EVENTS 60
#define OS_MAX_FLAGS 20
#define OS_MAX_MEM_PART 60
#define OS_MAX_QS 20
#define OS_MAX_TASKS 10
#define OS_MBOX_ACCEPT_EN 1
#define OS_MBOX_DEL_EN 1
#define OS_MBOX_EN 1
#define OS_MBOX_POST_EN 1
#define OS_MBOX_POST_OPT_EN 1
#define OS_MBOX_QUERY_EN 1
#define OS_MEM_EN 1
#define OS_MEM_NAME_SIZE 32
#define OS_MEM_QUERY_EN 1
#define OS_MUTEX_ACCEPT_EN 1
#define OS_MUTEX_DEL_EN 1
#define OS_MUTEX_EN 1
#define OS_MUTEX_QUERY_EN 1
#define OS_Q_ACCEPT_EN 1
#define OS_Q_DEL_EN 1
#define OS_Q_EN 1
#define OS_Q_FLUSH_EN 1
#define OS_Q_POST_EN 1
#define OS_Q_POST_FRONT_EN 1
#define OS_Q_POST_OPT_EN 1
#define OS_Q_QUERY_EN 1
#define OS_SCHED_LOCK_EN 1
#define OS_SEM_ACCEPT_EN 1
#define OS_SEM_DEL_EN 1
#define OS_SEM_EN 1
#define OS_SEM_QUERY_EN 1
#define OS_SEM_SET_EN 1
#define OS_TASK_CHANGE_PRIO_EN 1
#define OS_TASK_CREATE_EN 1
#define OS_TASK_CREATE_EXT_EN 1
#define OS_TASK_DEL_EN 1
#define OS_TASK_IDLE_STK_SIZE 512
#define OS_TASK_NAME_SIZE 32
#define OS_TASK_PROFILE_EN 1
#define OS_TASK_QUERY_EN 1
#define OS_TASK_STAT_EN 1
#define OS_TASK_STAT_STK_CHK_EN 1
#define OS_TASK_STAT_STK_SIZE 512
#define OS_TASK_SUSPEND_EN 1
#define OS_TASK_SW_HOOK_EN 1
#define OS_TASK_TMR_PRIO 0
#define OS_TASK_TMR_STK_SIZE 512
#define OS_THREAD_SAFE_NEWLIB 1
#define OS_TICKS_PER_SEC TIMER_0_TICKS_PER_SEC
#define OS_TICK_STEP_EN 1
#define OS_TIME_DLY_HMSM_EN 1
#define OS_TIME_DLY_RESUME_EN 1
#define OS_TIME_GET_SET_EN 1
#define OS_TIME_TICK_HOOK_EN 1
#define OS_TMR_CFG_MAX 16
#define OS_TMR_CFG_NAME_SIZE 16
#define OS_TMR_CFG_TICKS_PER_SEC 10
#define OS_TMR_CFG_WHEEL_SIZE 2
#define OS_TMR_EN 0


/*
 * wifi_uart configuration
 *
 */

#define ALT_MODULE_CLASS_wifi_uart altera_avalon_uart
#define WIFI_UART_BASE 0x100a060
#define WIFI_UART_BAUD 57600
#define WIFI_UART_DATA_BITS 8
#define WIFI_UART_FIXED_BAUD 1
#define WIFI_UART_FREQ 50000000
#define WIFI_UART_IRQ 1
#define WIFI_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define WIFI_UART_NAME "/dev/wifi_uart"
#define WIFI_UART_PARITY 'N'
#define WIFI_UART_SIM_CHAR_STREAM ""
#define WIFI_UART_SIM_TRUE_BAUD 0
#define WIFI_UART_SPAN 32
#define WIFI_UART_STOP_BITS 1
#define WIFI_UART_SYNC_REG_DEPTH 2
#define WIFI_UART_TYPE "altera_avalon_uart"
#define WIFI_UART_USE_CTS_RTS 0
#define WIFI_UART_USE_EOP_REGISTER 0

#endif /* __SYSTEM_H_ */
