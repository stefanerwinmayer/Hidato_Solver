#ifndef OUTPUT
#define OUTPUT

#include <stdio.h>
#include "state_struct.h"

#define FREE '?'
#define BLOCKED 'X'

#define UNKNOWN -1

void print_hamiltonian_path(struct State *state);
void print_board(struct State *state);

#endif