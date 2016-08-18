#ifndef OUTPUT
#define OUTPUT

#include <stdio.h>
#include "state_struct.h"
#include "board.h"

void print_hamiltonian_path(struct State *state);
void print_board(struct State *state);
void print_solution(struct Board *board);

#endif