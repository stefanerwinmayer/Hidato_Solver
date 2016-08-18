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
	int i, row, col;
	int score = 0;
	struct Coordinate neighbour;

	static const struct Coordinate MOVE_SET[] =
	{
		{ -1, -1 },{ -1, 0 },{ -1, 1 },
		{ 0, -1 },{ 0, 1 },
		{ 1, -1 },{ 1, 0 },{ 1, 1 }
	};

	for (row = 0; row < state->board_rows; row++)
	{
		for (col = 0; col < state->board_cols; col++)
		{
			for (i = 0; i < NUMBER_OF_MOVES; i++)
			{
				neighbour.row = row + MOVE_SET[i].row;
				neighbour.col = col + MOVE_SET[i].col;


				if (0 <= neighbour.row && neighbour.row < state->board_rows &&
					0 <= neighbour.col && neighbour.col < state->board_cols)
				{
					if (state->original_solution[neighbour.row][neighbour.col] == state->original_solution[row][col] + 1 ||
					state->original_solution[neighbour.row][neighbour.col] == state->original_solution[row][col] - 1)
					{
						score++;
					}
				}
			}
		}
	}

	return score;
}