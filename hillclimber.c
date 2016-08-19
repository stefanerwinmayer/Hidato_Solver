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

void copy_solution(
	struct Num_Coordinates *source,
	struct Num_Coordinates *dest)
{
	int i;

	dest->count = source->count;

	for (i = 0; i < source->count; i++)
	{
		dest->coordinates[i].row = source->coordinates[i].row;
		dest->coordinates[i].col = source->coordinates[i].col;
	}
}

void climb_hills(
	struct Board *initial,
	struct Board *best_solution,
	struct Num_Coordinates *numbers)
{
	struct Coordinate *current;
	struct Coordinate *other;
	struct Coordinate swap;

	current = numbers->coordinates;




	while (current < numbers->coordinates + numbers->count)
	{

		while (initial->grid[current->row][current->col] != TAKEN)
		{
			current++;
		}

		other = current + 1;

		while (other < numbers->coordinates + numbers->count)
		{
			while (initial->grid[other->row][other->col] != TAKEN) //||
				//other == current)
			{
				other++;
			}


			swap.row = current->row;
			swap.col = current->col;
			current->row = other->row;
			current->col = other->col;
			other->row = swap.row;
			other->col = swap.col;

			print_board(initial, numbers);

			swap.row = current->row;
			swap.col = current->col;
			current->row = other->row;
			current->col = other->col;
			other->row = swap.row;
			other->col = swap.col;

			other++;
		}

		current++;
	}
}

void produce_variations(
	int n,
	struct Board *board,
	struct Num_Coordinates *initial,
	struct Num_Coordinates *numbers)
{
	int i;
	struct Coordinate temp;

	if (n == 1)
	{
		for (i = 0; i < initial->count; i++)
		{
			if (board->grid[initial->coordinates[i].row][initial->coordinates[i].col] == FIXED &&
				(numbers->coordinates[i].row != initial->coordinates[i].col ||
				numbers->coordinates[i].col != initial->coordinates[i].col))
			{
				break;
			}
		}

		if (i == initial->count)
		{
			print_board(board, numbers);
		}
	}
	else
	{
		for (i = 0; i < n - 1; i++)
		{
			produce_variations(n - 1, board, initial, numbers);
			if (n % 2 == 0)
			{
				temp.row = numbers->coordinates[i].row;
				temp.col = numbers->coordinates[i].col;
				numbers->coordinates[i].row = numbers->coordinates[n - 1].row;
				numbers->coordinates[i].col = numbers->coordinates[n - 1].col;
				numbers->coordinates[n - 1].row = temp.row;
				numbers->coordinates[n - 1].col = temp.col;
			}
			else
			{
				temp.row = numbers->coordinates[0].row;
				temp.col = numbers->coordinates[0].col;
				numbers->coordinates[0].row = numbers->coordinates[n - 1].row;
				numbers->coordinates[0].col = numbers->coordinates[n - 1].col;
				numbers->coordinates[n - 1].row = temp.row;
				numbers->coordinates[n - 1].col = temp.col;

			}
		}
		produce_variations(n - 1, board, initial, numbers);
	}
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

/*
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
*/