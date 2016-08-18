#ifndef STATE_STRUCT
#define STATE_STRUCT

#include "hidato_limits.h"
#include "coordinate_struct.h"

#define FIXED -9
#define VISITED_FIXED -8
#define FREE -7
#define TAKEN -6
#define BLOCKED -5

#define UNKNOWN -2

struct State {
	struct Coordinate hamiltonian[MAX_NUMS];
	int ham_length;

	struct Coordinate *next_fixed;

	int board[MAX_ROWS][MAX_COLS];
	int board_rows;
	int board_cols;

	int backtrack_counter;
};

#endif