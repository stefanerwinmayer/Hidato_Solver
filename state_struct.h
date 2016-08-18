#ifndef STATE_STRUCT
#define STATE_STRUCT

#include "hidato_limits.h"
#include "coordinate_struct.h"

#define UNKNOWN -2

struct State {
	struct Coordinate hamiltonian[MAX_NUMS];
	int ham_length;

	struct Coordinate *next_fixed;

	int backtrack_counter;
};

#endif