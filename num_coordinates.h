#ifndef NUM_COORDINATES
#define NUM_COORDINATES

#include "coordinate_struct.h"
#include "hidato_limits.h"

#define UNKNOWN -2

struct Num_Coordinates {
	struct Coordinate coordinates[MAX_NUMS];
	int count;

	struct Coordinate *next_fixed;
};

#endif
