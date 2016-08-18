#ifndef BOARD
#define BOARD

#include "hidato_limits.h"

#define FIXED -9
#define VISITED_FIXED -8
#define FREE -7
#define TAKEN -6
#define BLOCKED -5

struct Board {
	int grid[MAX_ROWS][MAX_COLS];

	int rows;
	int cols;

	int number_count;
};

#endif