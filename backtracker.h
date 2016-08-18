#ifndef BACKTRACKER
#define BACKTRACKER

#include <math.h>
#include "boolean.h"
#include "coordinate_struct.h"
#include "board.h"
#include "num_coordinates.h"
#include "state_struct.h"

#define NUMBER_OF_MOVES 8

BOOL backtrack(
	struct Board *board,
	struct Num_Coordinates *numbers,
	struct State *state,
	const struct Coordinate *current,
	const BOOL smart);

void update_board(
	struct Board *board,
	const struct Coordinate *current);

void update_hamiltonian(
	struct Coordinate *current,
	const struct Coordinate *neighbour);

void update_next_fixed(
	struct Board *board,
	struct Num_Coordinates *numbers,
	const struct Coordinate *current);

BOOL valid_move(
	struct Board *board,
	const struct Coordinate *next,
	const struct Coordinate *neighbour);

void revert_board(
	struct Board *board,
	const struct Coordinate *current);

void revert_hamiltonian(
	struct Board *board,
	struct Coordinate *current);

void revert_next_fixed(
	struct Board *board,
	struct Num_Coordinates *numbers,
	const struct Coordinate *current);

int distance(
	const struct Coordinate *first,
	const struct Coordinate *second);

BOOL sensible_move(
	const struct Num_Coordinates *numbers,
	const struct Coordinate *next,
	const struct Coordinate *neighbour);

#endif