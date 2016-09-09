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
#define NONE -9

void produce_random_solution(
	struct Board *board,
	struct Num_Coordinates *numbers);

void update_points(
	struct Num_Coordinates *solution,
	int *points,
	int i,
	int end);

void climb_hills(
	struct Board *board,
	struct Num_Coordinates *initial,
	int *points,
	int *iterations);

void process_deriviate_solutions(
	struct Board *board,
	struct Num_Coordinates *initial,
	int *points,
	int *iterations);

void swap_numbers(
	struct Num_Coordinates *solution,
	const int index_one,
	const int index_two);

int find_number_to_swap(
	const struct Board *board,
	const struct Num_Coordinates *solution,
	int index);

int assess_deriviate(
	const struct Num_Coordinates *solution,
	const int *points,
	const int index_one,
	const int index_two);

#endif