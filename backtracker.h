#ifndef BACKTRACKER
#define BACKTRACKER

#include "boolean.h"
#include "coordinate_struct.h"
#include "state_struct.h"

#define FREE '?'
#define TAKEN 'T'

#define UNKNOWN -1

void update_state(
	struct State *state,
	const struct Coordinate *current,
	const int ham_pos);

#endif