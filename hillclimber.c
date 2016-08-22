#include "hillclimber.h"

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

void produce_random_solution(
	struct Board *board,
	struct Num_Coordinates *numbers)
{
	int row, col;
	int random_num;
	time_t t;

	srand((unsigned)time(&t));

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

BOOL climb_hills(
	struct Board *board,
	struct Num_Coordinates *initial,
	struct Num_Coordinates *best,
	int *process_deriviate_counter)
{
	int high_score;
	BOOL solved = TRUE;
	const int optimum_score = initial->count - 1;

	produce_random_solution(board, initial);

	printf("Random solution:\n\n");
	print_board(board, initial);

	high_score = assess_solution(initial);
	printf("Score: %d\n\n", high_score);

	copy_solution(initial, best);

	if (high_score != optimum_score)
	{
		printf("PROCESSING DERIVIATE SOLUTIONS:\n\n");
		solved = process_deriviate_solutions(board, initial, best, optimum_score, high_score, process_deriviate_counter);
	}
	
	return solved;
}

BOOL process_deriviate_solutions(
	struct Board *board,
	struct Num_Coordinates *initial,
	struct Num_Coordinates *best,
	int best_score,
	int high_score,
	int *process_deriviate_counter)
{
	struct Coordinate *current;
	struct Coordinate *other;
	BOOL solved = FALSE;
	int round_high_score = high_score;
	int score = 0;

	current = initial->coordinates;

	(*process_deriviate_counter)++;

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

				//print_board(board, initial);

				score = assess_solution(initial);

				if (score > round_high_score)
				{
					copy_solution(initial, best);
					round_high_score = score;

					printf("Best INTERIM solution:\n\n");
					print_board(board, best);
					printf("Score: %d\n\n", score);
				}

				if (score == best_score)
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

		solved = process_deriviate_solutions(board, initial, best, best_score, high_score, process_deriviate_counter);
	}

	return solved;
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
*/

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