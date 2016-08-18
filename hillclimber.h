#ifndef HILLCLIMBER
#define HILLCLIMBER

#include "boolean.h"
#include "board.h"
#include "coordinate_struct.h"

#define UNKNOWN -1
#define NUMBER_OF_MOVES 8

void produce_random_solution(
	struct Board *board,
	BOOL fixed[MAX_NUMS]);

int assess_solution(struct Board *board);

void copy_board(
	struct Board *source,
	struct Board *dest);

#endif