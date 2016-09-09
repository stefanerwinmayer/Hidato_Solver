#include "backtracker.h"

BOOL backtrack(
	struct Board *board,
	struct Num_Coordinates *numbers,
	const struct Coordinate *current,
	int *iterations,
	const BOOL smart)
{
	int i;
	struct Coordinate *next = current + 1;
	struct Coordinate neighbour;

	static const struct Coordinate MOVE_SET[] =
	{
		{ -1, -1 },{ -1, 0 },{ -1, 1 },
		{  0, -1 },          {  0, 1 },
		{  1, -1 },{  1, 0 },{  1, 1 }
	};

	(*iterations)++;

	update_board(board, current);

	if (smart)
	{
		update_next_fixed(numbers, current);
	}

	for (i = 0; i < NUMBER_OF_MOVES; i++)
	{
		neighbour.row = current->row + MOVE_SET[i].row;
		neighbour.col = current->col + MOVE_SET[i].col;

		if (valid_move(board, next, &neighbour))
		{
			if (smart && !sensible_move(numbers, next, &neighbour))
			{
				continue;
			}

			update_hamiltonian(next, &neighbour);

			if (!backtrack(board, numbers, next, iterations, smart))
			{
				continue;
			}
			else
			{
				return TRUE;
			}
		}
	}

	if (current != numbers->coordinates + numbers->count - 1) /* if not solved yet */
	{
		revert_board(board, current);
		revert_hamiltonian(board, current);

		if (smart)
		{
			revert_next_fixed(numbers, current);
		}

		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

void update_board(
	struct Board *board,
	const struct Coordinate *current)
{
	switch (board->grid[current->row][current->col])
	{
	case FREE:

		board->grid[current->row][current->col] = TAKEN;
		break;

	case FIXED:

		board->grid[current->row][current->col] = VISITED_FIXED;
		break;
	}
}

void update_hamiltonian(
	struct Coordinate *next,
	const struct Coordinate *neighbour)
{
	if (next->row == UNKNOWN)
	{
		next->row = neighbour->row;
		next->col = neighbour->col;
	}
}

void update_next_fixed(
	struct Num_Coordinates *numbers,
	const struct Coordinate *current)
{
	if (current == numbers->next_fixed)
	{
		do {
			(numbers->next_fixed)++;
		} while (numbers->next_fixed->row == UNKNOWN);
	}
}

BOOL valid_move(
	const struct Board *board,
	const struct Coordinate *next,
	const struct Coordinate *neighbour)
{
	if (0 <= neighbour->row && neighbour->row < board->rows &&
		0 <= neighbour->col && neighbour->col < board->cols)
	{
		if (next->row == UNKNOWN &&
			board->grid[neighbour->row][neighbour->col] == FREE)
		{
			return TRUE;
		}
		else if (next->row == neighbour->row && next->col == neighbour->col)
		{
			return TRUE;
		}
	}
	return FALSE;
}

void revert_board(
	struct Board *board,
	const struct Coordinate *current)
{
	switch (board->grid[current->row][current->col])
	{
	case TAKEN:

		board->grid[current->row][current->col] = FREE;
		break;

	case VISITED_FIXED:

		board->grid[current->row][current->col] = FIXED;
		break;
	}
}

void revert_hamiltonian(
	const struct Board *board,
	struct Coordinate *current)
{
	if (board->grid[current->row][current->col] == FREE)
	{
		current->row = UNKNOWN;
		current->col = UNKNOWN;
	}
}

void revert_next_fixed(
	struct Num_Coordinates *numbers,
	const struct Coordinate *current)
{
	if (current->row != UNKNOWN)
	{
		numbers->next_fixed = current;
	}
}

BOOL sensible_move(
	const struct Num_Coordinates *numbers,
	const struct Coordinate *next,
	const struct Coordinate *neighbour)
{
	int dist, available_steps;

	if (numbers->next_fixed < numbers->coordinates + numbers->count - 1)
	{
		dist = distance(neighbour, numbers->next_fixed);
		available_steps = numbers->next_fixed - next;
		return dist <= available_steps;
	}
	else
	{
		return TRUE;
	}
}

int distance(
	const struct Coordinate *first,
	const struct Coordinate *second)
{
	return (int)fmax(abs(first->row - second->row), abs(first->col - second->col));
}