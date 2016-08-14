#ifndef BACKTRACKER
#define BACKTRACKER

#include "boolean.h"
#include "coordinate_struct.h"
#include "state_struct.h"

#define FIXED 'F'
#define VISITED_FIXED 'V'
#define FREE '?'
#define TAKEN 'T'
#define BLOCKED 'X'

#define UNKNOWN -1

BOOL backtrack(struct State *state,
	const struct Coordinate *current,
	const int ham_pos);

void update_state(
	struct State *state,
	const struct Coordinate *current,
	const int ham_pos);

BOOL valid_move(
	const struct State *state,
	const struct Coordinate *next,
	const int next_ham_pos);

void revert_state(
	struct State *state,
	const struct Coordinate *current,
	const int ham_pos);

#endif