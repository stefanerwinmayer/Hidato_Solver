#ifndef STATE_STRUCT
#define STATE_STRUCT

#include "hidato_limits.h"
#include "coordinate_struct.h"

struct State {
	struct Coordinate hamiltonian[MAX_NUMS];
	int ham_length;

	struct Coordinate *next_fixed;

	char board[MAX_ROWS][MAX_COLS];
	int board_rows;
	int board_cols;

	int backtrack_counter;
};

#endif