#include "output.h"

void print_board(struct State *state)
{
	int i, j;
	char output[MAX_ROWS][MAX_COLS] = { {BLOCKED} };
	
	for (i = 0; i < state->ham_length; i++)
	{
		if (state->hamiltonian[i].row >= 0 && state->hamiltonian[i].col >= 0)
		{
			output[state->hamiltonian[i].row][state->hamiltonian[i].col] = (char)(i + 1);
		}
	}

	for (i = 0; i < state->board_rows; i++)
	{
		for (j = 0; j < state->board_cols; j++)
		{
			if (state->board[i][j] == FREE)
			{
				output[i][j] = FREE;
			}
		}
	}

	for (i = 0; i < state->board_rows; i++)
	{
		for (j = 0; j < state->board_cols; j++)
		{
			if (output[i][j] != BLOCKED && output[i][j] != FREE)
			{
				printf("[%2.d]", output[i][j]);
			}
			else if (output[i][j] == BLOCKED)
			{
				printf("[XX]");
			}
			else
			{
				printf("[??]");
			}
		}
		printf("\n");
	}
	printf("\n");
}