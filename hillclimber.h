#ifndef HILLCLIMBER
#define HILLCLIMBER

#include "boolean.h"
#include "board.h"
#include "coordinate_struct.h"
#include "num_coordinates.h"

#include "output.h"
#include "backtracker.h"

#define NUMBER_OF_MOVES 8

void produce_random_solution(
	struct Board *board,
	struct Num_Coordinates *numbers);

int assess_solution(struct Num_Coordinates *numbers);

void copy_board(
	struct Board *source,
	struct Board *dest);

void climb_hills(
	struct Board *initial,
	struct Board *best_solution,
	struct Num_Coordinates *numbers);

#endif