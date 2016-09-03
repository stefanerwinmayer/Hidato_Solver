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

int assess_solution(struct Num_Coordinates *solution)
{
	struct Coordinate *current;
	int score = 0;

	for (current = solution->coordinates; current < solution->coordinates + solution->count - 1; current++)
	{
		if (distance(current, current + 1) == 1)
		{
			score++;
		}
	}

	return score;
}



int climb_hills(
	struct Board *board,
	struct Num_Coordinates *initial)
{
	int high_score;

	produce_random_solution(board, initial);

	high_score = assess_solution(initial);

	high_score = process_deriviate_solutions(board, initial, high_score);

	return high_score;
}

int process_deriviate_solutions(
	struct Board *board,
	struct Num_Coordinates *solution,
	int high_score)
{
	struct Coordinate *current;
	struct Coordinate *other;
	struct Coordinate *best_swap_one = NULL;
	struct Coordinate *best_swap_two = NULL;

	int round_high_score = high_score;
	int score = 0;

	current = solution->coordinates;

	while (current < solution->coordinates + solution->count)
	{
		current = find_number_to_swap(board, solution, current);

		other = current + 1;

		while (other < solution->coordinates + solution->count)
		{
			other = find_number_to_swap(board, solution, other);

			swap_numbers(current, other);

			score = assess_solution(solution);

			if (score > round_high_score)
			{
				best_swap_one = current;
				best_swap_two = other;
				round_high_score = score;
			}

			swap_numbers(current, other);

			other++;
		}

		current++;
	}

	if (round_high_score > high_score)
	{
		swap_numbers(best_swap_one, best_swap_two);
		high_score = process_deriviate_solutions(board, solution, round_high_score);
	}

	return high_score;
}

struct Coordinate *find_number_to_swap(
	struct Board *board,
	struct Num_Coordinates *solution,
	struct Coordinate *number)
{
	while ((
		board->grid[number->row][number->col] == FIXED ||
		board->grid[number->row][number->col] == BLOCKED) &&
		number < solution->coordinates + solution->count)
	{
		number++;
	}

	return number;
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
/*
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
*/