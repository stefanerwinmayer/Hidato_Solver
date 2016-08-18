#include "hillclimber.h"

void produce_random_solution(struct HC_State *state)
{
	int row, col;
	int i = 0;

	for (row = 0; row < state->board_rows; row++)
	{
		for (col = 0; col < state->board_cols; col++)
		{
			if (state->original_solution[row][col] == UNKNOWN)
			{
				while (state->fixed[i] == TRUE)
					i++;

				state->original_solution[row][col] = i + 1;
				i++;
			}
		}
	}
}

int assess_solution(struct HC_State *state)
{
	return -1;
}