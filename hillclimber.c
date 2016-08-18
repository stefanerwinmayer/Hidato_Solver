#include "hillclimber.h"

void produce_random_solution(
	struct Board *board,
	BOOL fixed[MAX_NUMS])
{
	int row, col;
	int i = 0;

	for (row = 0; row < board->rows; row++)
	{
		for (col = 0; col < board->cols; col++)
		{
			if (board->grid[row][col] == UNKNOWN)
			{
				while (fixed[i] == TRUE)
					i++;

				board->grid[row][col] = i + 1;
				i++;
			}
		}
	}
}

int assess_solution(
	int board[MAX_ROWS][MAX_COLS],
	int rows,
	int cols)
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

	for (row = 0; row < rows; row++)
	{
		for (col = 0; col < cols; col++)
		{
			for (i = 0; i < NUMBER_OF_MOVES; i++)
			{
				neighbour.row = row + MOVE_SET[i].row;
				neighbour.col = col + MOVE_SET[i].col;


				if (0 <= neighbour.row && neighbour.row < rows &&
					0 <= neighbour.col && neighbour.col < cols)
				{
					if (board[neighbour.row][neighbour.col] == board[row][col] + 1 ||
						board[neighbour.row][neighbour.col] == board[row][col] - 1)
					{
						score++;
					}
				}
			}
		}
	}

	return score;
}

void copy_board(struct HC_State *state)
{
	int row, col;

	for (row = 0; row < state->board_rows; row++)
	{
		for (col = 0; col < state->board_cols; col++)
		{
			state->best_solution[row][col] = state->original_solution[row][col];
		}
	}
}