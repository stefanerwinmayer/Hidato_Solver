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

int assess_solution(
	struct Num_Coordinates *solution,
	int *points);

int climb_hills(
	struct Board *board,
	struct Num_Coordinates *initial);

int process_deriviate_solutions(
	struct Board *board,
	struct Num_Coordinates *initial,
	int high_score,
	int *points);

void swap_numbers(
	struct Num_Coordinates *solution,
	int index_one,
	int index_two);

int find_number_to_swap(
	struct Board *board,
	struct Num_Coordinates *solution,
	int index);

BOOL is_better(
	struct Num_Coordinates *solution,
	int *points,
	int index_one,
	int index_two);

#endif