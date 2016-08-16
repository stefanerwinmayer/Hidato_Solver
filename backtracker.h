#ifndef BACKTRACKER
#define BACKTRACKER

#include <math.h>
#include "boolean.h"
#include "coordinate_struct.h"
#include "state_struct.h"

#define FIXED 'F'
#define VISITED_FIXED 'V'
#define FREE '?'
#define TAKEN 'T'
#define BLOCKED 'X'

#define UNKNOWN -1

#define NUMBER_OF_MOVES 8

BOOL backtrack(
	struct State *state,
	const struct Coordinate *current,
	const int ham_pos,
	const BOOL smart);

void update_board(
	struct State *state,
	const struct Coordinate *current);

void update_hamiltonian(
	struct State *state,
	const struct Coordinate *current,
	const int ham_pos);

void update_next_fixed(
	const struct State *state,
	const struct Coordinate *current,
	const int ham_pos);

BOOL valid_move(
	const struct State *state,
	const struct Coordinate *next,
	const int next_ham_pos);

void revert_board(
	struct State *state,
	const struct Coordinate *current);

void revert_hamiltonian(
	struct State *state,
	const struct Coordinate *current,
	const int ham_pos);

void revert_next_fixed(
	struct State *state,
	const struct Coordinate *current,
	const int ham_pos);

int distance(
	const struct Coordinate *first,
	const struct Coordinate *second);

BOOL sensible_move(
	const struct State *state,
	const struct Coordinate *next,
	const int next_ham_pos);

#endif