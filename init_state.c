#include "init_state.h"

#include <stdio.h>

void initialise_state(char *input, struct State *state)
{
	
	int row, col, number;
	char *p;

	state->board_rows = state->board_cols = 0;

	row = col = 0;
	
	(state->board_rows)++;
	for (p = input; p < input + strlen(input); p++)
	{
		if (isdigit(*p))
		{
			state->board[row][col] = 'F';
			(state->board_cols)++;

			number = *p - '0' - 1;
			state->hamiltonian[number].row = row;
			state->hamiltonian[number].col = col;
		}
		
	}
}