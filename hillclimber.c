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

void update_points(
	struct Num_Coordinates *solution,
	int *points,
	int i,
	int end)
{
	while (i < end)
	{
		if (distance(&solution->coordinates[i], &solution->coordinates[i + 1]) == 1)
		{
			points[i] = 1;
		}
		i++;
	}
}

void climb_hills(
	struct Board *board,
	struct Num_Coordinates *initial,
	int *points,
	int *iterations)
{
	produce_random_solution(board, initial);

	update_points(initial, points, 0, initial->count);

	process_deriviate_solutions(board, initial, points, iterations);

}

void process_deriviate_solutions(
	struct Board *board,
	struct Num_Coordinates *solution,
	int *points,
	int *iterations)
{
	int i, j, best_i, best_j;
	int best_change, current_change;

	do
	{
		(*iterations)++;

		best_i = NONE;
		best_j = NONE;

		i = best_change = 0;

		while (i < solution->count)
		{
			i = find_number_to_swap(board, solution, i);

			j = i + 1;

			while (j < solution->count)
			{
				j = find_number_to_swap(board, solution, j);

				current_change = assess_deriviate(solution, points, i, j);

				if (current_change > best_change)
				{
					best_i = i;
					best_j = j;
					best_change = current_change;
				}

				j++;
			}

			i++;
		}

		if (best_change > 0)
		{
			swap_numbers(solution, best_i, best_j);
			update_points(solution, points, best_i - 1, best_i + 1);
			update_points(solution, points, best_j - 1, best_j + 1);
		}

	} while (best_change > 0);
} 

int assess_deriviate(
	const struct Num_Coordinates *solution,
	const int *points,
	const int i,
	const int j)
{
	int after_points = 0;
	int initial_points = points[i - 1] + points[i] + points[j - 1] + points[j];
	
	if (distance(&solution->coordinates[i - 1], &solution->coordinates[j]) == 1)
	{
		after_points++;
	}
	if (distance(&solution->coordinates[j], &solution->coordinates[i + 1]) == 1)
	{
		after_points++;
	}
	if (distance(&solution->coordinates[j - 1], &solution->coordinates[i]) == 1)
	{
		after_points++;
	}
	if (distance(&solution->coordinates[i], &solution->coordinates[j + 1]) == 1)
	{
		after_points++;
	}

	return after_points - initial_points;
}

int find_number_to_swap(
	struct Board *board,
	struct Num_Coordinates *solution,
	int i)
{
	while (
		i < solution->count &&
		board->grid[solution->coordinates[i].row][solution->coordinates[i].col] != TAKEN)
	{
		i++;
	}

	return i;
}


void swap_numbers(
	struct Num_Coordinates *solution,
	int i,
	int j)
{
	struct Coordinate temp;

	temp.row = solution->coordinates[i].row;
	temp.col = solution->coordinates[i].col;

	solution->coordinates[i].row = solution->coordinates[j].row;
	solution->coordinates[i].col = solution->coordinates[j].col;

	solution->coordinates[j].row = temp.row;
	solution->coordinates[j].col = temp.col;
}