#include "init_state.h"

void initialise_state(char *input, struct State *state)
{
	int row, col, number;
	char *p;

	state->board_rows = state->board_cols = 0;

	row = col = 0;
	number = PROCESSED;

	(state->board_rows)++;
	for (p = input; p < input + strlen(input); p++)
	{
		if (isdigit(*p))
		{
			number = (number * 10) + (*p - '0');
		}
		else if (number != PROCESSED)
		{
			state->board[row][col] = 'F';
			(state->board_cols)++;
			state->hamiltonian[number - 1].row = row;
			state->hamiltonian[number - 1].col = col;
			number = PROCESSED;
		}
	}
}