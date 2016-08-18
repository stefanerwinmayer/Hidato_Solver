#ifndef NUM_COORDINATES
#define NUM_COORDINATES

#include "coordinate_struct.h"
#include "hidato_limits.h"

struct Num_Coordinates {
	struct Coordinate coordinates[MAX_NUMS];
	int count;
};

#endif#pragma once
