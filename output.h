#ifndef OUTPUT
#define OUTPUT

#include <stdio.h>
#include "board.h"
#include "num_coordinates.h"

void print_hamiltonian_path(struct Num_Coordinates *numbers);

void print_board(
	const struct Board *board,
	const struct Num_Coordinates *numbers);
/*
void print_solution(struct Board *board);
*/

#endif