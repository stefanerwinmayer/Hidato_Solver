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

void generate(int n, int a[], int size)
{
	int i, temp;

	if (n == 1)
	{
		for (i = 0; i < size; i++)
		{
			printf("%d", a[i]);
		}
		printf("\n");
	}
	else
	{
		for (i = 0; i < n - 1; i++)
		{
			generate(n - 1, a, size);
			if (n % 2 == 0)
			{
				temp = a[i];
				a[i] = a[n - 1];
				a[n - 1] = temp;
			}
			else
			{
				temp = a[0];
				a[0] = a[n - 1];
				a[n - 1] = temp;
				
			}
		}
		generate(n - 1, a, size);
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