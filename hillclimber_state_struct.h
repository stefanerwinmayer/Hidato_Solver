#ifndef HILLCLIMBER_STATE_STRUCT
#define HILLCLIMBER_STATE_STRUCT

#include "hidato_limits.h"
#include "boolean.h"

struct HC_State {
	int number_count;

	BOOL fixed[MAX_NUMS];

	int original_solution[MAX_ROWS][MAX_COLS];
	int best_solution[MAX_ROWS][MAX_COLS];

	int board_rows;
	int board_cols;
};

#endif