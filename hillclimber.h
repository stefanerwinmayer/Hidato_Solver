#ifndef HILLCLIMBER
#define HILLCLIMBER

#include <stdlib.h>
#include <time.h>

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

int climb_hills(
	struct Board *board,
	struct Num_Coordinates *initial);

int process_deriviate_solutions(
	struct Board *board,
	struct Num_Coordinates *initial,
	int high_score);

void swap_numbers(
	struct Coordinate *first,
	struct Coordinate *second);

struct Coordinate *find_number_to_swap(
	struct Board *board,
	struct Num_Coordinates *numbers,
	struct Coordinate *number);

#endif