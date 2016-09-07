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

int assess_solution(
	struct Num_Coordinates *solution,
	int *points)
{
	int i, score = 0;

	for (i = 1; i < solution->count; i++)
	{
		if (distance(&solution->coordinates[i - 1], &solution->coordinates[i]) == 1)
		{
			points[i - 1] = 1;
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
	int points[MAX_NUMS] = { 0 };

	produce_random_solution(board, initial);

	high_score = assess_solution(initial, points);

	high_score = process_deriviate_solutions(board, initial, high_score, points);

	return high_score;
}

int process_deriviate_solutions(
	struct Board *board,
	struct Num_Coordinates *solution,
	int high_score,
	int *points)
{
	int current_index;
	int other_index;
	int best_swap_index_one = -1;
	int best_swap_index_two = -1;

	int round_high_score = high_score;
	int score = 0;

	current_index = 0;

	while (current_index < solution->count)
	{
		current_index = find_number_to_swap(board, solution, current_index);

		other_index = current_index + 1;

		while (other_index < solution->count)
		{
			other_index = find_number_to_swap(board, solution, other_index);

			//swap_numbers(solution, current_index, other_index);

			//score = assess_solution(solution, points);

			//if (score > round_high_score)
			if (is_better(solution, points, current_index, other_index))
			{
				best_swap_index_one = current_index;
				best_swap_index_two = other_index;
				//round_high_score = score;
			}

			//swap_numbers(solution, current_index, other_index);

			other_index++;
		}

		current_index++;
	}

	//if (round_high_score > high_score)
	if (best_swap_index_one != -1)
	{
		swap_numbers(solution, best_swap_index_one, best_swap_index_two);
		round_high_score = assess_solution(solution, points);
		high_score = process_deriviate_solutions(board, solution, round_high_score, points);
	}

	return high_score;
}

BOOL is_better(
	struct Num_Coordinates *solution,
	int *points,
	int first,
	int second)
{
	int i, j, after_points = 0;
	int initial_points =
		points[first - 1] + points[first] +
		points[second - 1] + points[second];
	
	if (distance(&solution->coordinates[first - 1], &solution->coordinates[second]) == 1)
	{
		after_points++;
	}
	if (distance(&solution->coordinates[second], &solution->coordinates[first + 1]) == 1)
	{
		after_points++;
	}
	if (distance(&solution->coordinates[second - 1], &solution->coordinates[first]) == 1)
	{
		after_points++;
	}
	if (distance(&solution->coordinates[first], &solution->coordinates[second + 1]) == 1)
	{
		after_points++;
	}

	return after_points > initial_points;

}

int find_number_to_swap(
	struct Board *board,
	struct Num_Coordinates *solution,
	int index)
{
	while ((
		board->grid[solution->coordinates[index].row][solution->coordinates[index].col] == FIXED ||
		board->grid[solution->coordinates[index].row][solution->coordinates[index].col] == BLOCKED) &&
		index < solution->count)
	{
		index++;
	}

	return index;
}


void swap_numbers(
	struct Num_Coordinates *solution,
	int index_one,
	int index_two)
{
	struct Coordinate temp;

	temp.row = solution->coordinates[index_one].row;
	temp.col = solution->coordinates[index_one].col;

	solution->coordinates[index_one].row = solution->coordinates[index_two].row;
	solution->coordinates[index_one].col = solution->coordinates[index_two].col;

	solution->coordinates[index_two].row = temp.row;
	solution->coordinates[index_two].col = temp.col;
}

/*
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
*/


/*
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
*/

/*
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
*/


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