#include "hillclimber.h"

void produce_random_solution(
	struct Board *board,
	struct Num_Coordinates *numbers)
{
	int row, col;
	int random_num;

	for (row = 0; row < board->rows; row++)
	{
		for (col = 0; col < board->cols; col++)
		{
			if (board->grid[row][col] == FREE)
			{

				do {
					random_num = rand() % numbers->count;
				} while (numbers->coordinates[random_num].row != UNKNOWN);

				numbers->coordinates[random_num].row = row;
				numbers->coordinates[random_num].col = col;
				board->grid[row][col] = TAKEN;
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

int climb_hills(
	struct Board *board,
	struct Num_Coordinates *initial,
	struct Num_Coordinates *best)
{
	int high_score;
	//const int optimum_score = initial->count - 1;

	produce_random_solution(board, initial);

	high_score = assess_solution(initial);

	copy_solution(initial, best);

	high_score = process_deriviate_solutions(board, initial, best, high_score);

	return high_score;
}

int process_deriviate_solutions(
	struct Board *board,
	struct Num_Coordinates *initial,
	struct Num_Coordinates *best,
	int high_score)
{
	struct Coordinate *current;
	struct Coordinate *other;
	int round_high_score = high_score;
	int score = 0;
	const int optimum_score = initial->count - 1;

	current = initial->coordinates;

	while (current < initial->coordinates + initial->count)
	{
		while (board->grid[current->row][current->col] != TAKEN &&
			current < initial->coordinates + initial->count)
		{
			current++;
		}

		other = current + 1;

		while (other < initial->coordinates + initial->count)
		{
			while (board->grid[other->row][other->col] != TAKEN &&
				other < initial->coordinates + initial->count)
			{
				other++;
			}

			if (board->grid[current->row][current->col] == TAKEN &&
				board->grid[other->row][other->col] == TAKEN)
			{
				swap_numbers(current, other);

				score = assess_solution(initial);

				if (score > round_high_score)
				{
					copy_solution(initial, best);
					round_high_score = score;
				}

				if (score == optimum_score)
				{
					return TRUE;
				}

				swap_numbers(current, other);
			}

			other++;
		}

		current++;
	}

	if (round_high_score > high_score)
	{
		high_score = round_high_score;
		copy_solution(best, initial);

		high_score = process_deriviate_solutions(board, initial, best, high_score);
	}

	return high_score;
}

void swap_numbers(
	struct Coordinate *first,
	struct Coordinate *second)
{
	struct Coordinate temp;

	temp.row = first->row;
	temp.col = first->col;
	first->row = second->row;
	first->col = second->col;
	second->row = temp.row;
	second->col = temp.col;
}

/*
void produce_predictable_solution(
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
*/

/*
void copy_board(
struct Board *source,
struct Board *dest)
{
int row, col;

dest->rows = source->rows;
dest->cols = source->cols;

for (row = 0; row < dest->cols; row++)
{
for (col = 0; col < dest->cols; col++)
{
dest->grid[row][col] = source->grid[row][col];
}
}
}
*/
