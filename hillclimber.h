#ifndef HILLCLIMBER
#define HILLCLIMBER

#include "hillclimber_state_struct.h"
#include "coordinate_struct.h"

#define UNKNOWN -1
#define NUMBER_OF_MOVES 8

void produce_random_solution(struct HC_State *state);

int assess_solution(
	int board[MAX_ROWS][MAX_COLS],
	int rows,
	int cols);

void copy_board(struct HC_State *state);

#endif