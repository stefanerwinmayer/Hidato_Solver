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

void assess_solution(
	struct Num_Coordinates *solution,
	int *points);

void climb_hills(
	struct Board *board,
	struct Num_Coordinates *initial,
	int *points);

void process_deriviate_solutions(
	struct Board *board,
	struct Num_Coordinates *initial,
	int *points);

void swap_numbers(
	struct Num_Coordinates *solution,
	int index_one,
	int index_two);

int find_number_to_swap(
	struct Board *board,
	struct Num_Coordinates *solution,
	int index);

int assess_deriviate(
	struct Num_Coordinates *solution,
	int *points,
	int index_one,
	int index_two);

#endif