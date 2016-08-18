#ifndef BOARD
#define BOARD

#include "hidato_limits.h"

struct Board {
	int grid[MAX_ROWS][MAX_COLS];

	int rows;
	int cols;

	int number_count;
};

#endif