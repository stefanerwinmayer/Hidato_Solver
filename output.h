#ifndef OUTPUT
#define OUTPUT

#include <stdio.h>
#include "state_struct.h"
#include "hillclimber_state_struct.h"

#define FREE '?'
#define BLOCKED 'X'

#define UNKNOWN -1
#define NOT_IN_USE -2

void print_hamiltonian_path(struct State *state);
void print_board(struct State *state);
void print_solution(struct HC_State *state);

#endif