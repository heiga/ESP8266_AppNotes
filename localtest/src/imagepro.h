/*
 * imagepro.h
 *
 *  Created on: Feb 12, 2017
 *      Author: Randy Baron
 */

#include <inttypes.h>

#define JPEGNAME "C:\\Users\\Randy Baron\\Pictures\\sample50.jpg"

#define REGION_COUNT 10

#define REDREG_RED 200
#define REDREG_BLU 20
#define REDREG_GRN 20

struct color_region {
	uint16_t confidence;
	uint16_t pixels_detected;
	uint16_t rows_traversed;
	uint16_t cols_traversed;
	uint16_t x;
	uint16_t y;
	uint16_t last_r;
	uint16_t last_g;
	uint16_t last_b;
} color_region;
