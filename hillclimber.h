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

void copy_solution(
	struct Num_Coordinates *source,
	struct Num_Coordinates *dest);

void climb_hills(
	struct Board *board,
	struct Num_Coordinates *initial,
	struct Num_Coordinates *best);

void process_deriviate_solutions(
	struct Board *board,
	struct Num_Coordinates *initial,
	struct Num_Coordinates *best,
	int best_score,
	int high_score);

void swap_numbers(
	struct Coordinate *first,
	struct Coordinate *second);

#endif