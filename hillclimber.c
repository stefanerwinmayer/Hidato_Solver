#include "hillclimber.h"

void produce_random_solution(
	struct Board *board,
	struct Num_Coordinates *numbers)
{
	int row, col;
	int i = 0;

	for (row = 0; row < board->rows; row++)
	{
		for (col = 0; col < board->cols; col++)
		{
			if (board->grid[row][col] == FREE)
			{
				while (numbers->coordinates[i].row != UNKNOWN)
					i++;

				numbers->coordinates[i].row = row;
				numbers->coordinates[i].col = col;
				board->grid[row][col] = TAKEN;
				i++;
			}
		}
	}
}

int assess_solution(struct Num_Coordinates *numbers)
{
	struct Coordinate *current;
	int score = 0;

	for (current = numbers->coordinates; current < numbers->coordinates + numbers->count - 1; current++)
	{
		if (distance(current, current + 1) == 1)
		{
			score++;
		}
	}

	return score;
}

void copy_board(
	struct Board *source,
	struct Board *dest)
{
	int row, col;

	dest->rows = source->rows;
	dest->cols = source->cols;

	dest->number_count = source->number_count;

	for (row = 0; row < dest->rows; row++)
	{
		for (col = 0; col < dest->cols; col++)
		{
			dest->grid[row][col] = source->grid[row][col];
		}
	}
}

void climb_hills(
	struct Board *initial,
	struct Board *best_solution,
	struct Num_Coordinates *numbers)
{

}

/*
int assess_solution(struct Board *board)
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

for (row = 0; row < board->rows; row++)
{
for (col = 0; col < board->cols; col++)
{
for (i = 0; i < NUMBER_OF_MOVES; i++)
{
neighbour.row = row + MOVE_SET[i].row;
neighbour.col = col + MOVE_SET[i].col;


if (0 <= neighbour.row && neighbour.row < board->rows &&
0 <= neighbour.col && neighbour.col < board->cols)
{
if (board->grid[neighbour.row][neighbour.col] == board->grid[row][col] + 1 ||
board->grid[neighbour.row][neighbour.col] == board->grid[row][col] - 1)
{
score++;
}
}
}
}
}

return score;
}
*/