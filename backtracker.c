#include "backtracker.h"

BOOL backtrack(
	struct Board *board,
	struct State *state,
	const struct Coordinate *current,
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

	(state->backtrack_counter)++;

	update_board(board, current);

	if (smart)
	{
		update_next_fixed(board, state, current);
	}

	for (i = 0; i < NUMBER_OF_MOVES; i++)
	{
		neighbour.row = current->row + MOVE_SET[i].row;
		neighbour.col = current->col + MOVE_SET[i].col;

		if (valid_move(board, state, next, &neighbour))
		{
			if (smart && !sensible_move(state, next, &neighbour))
			{
				continue;
			}

			update_hamiltonian(next, &neighbour);

			if (!backtrack(board, state, next, smart))
			{
				continue;
			}
			else
			{
				return TRUE;
			}
		}
	}

	if (current != state->hamiltonian + state->ham_length - 1) /* if not solved yet */
	{
		revert_board(board, current);
		revert_hamiltonian(state, current);

		if (smart)
		{
			revert_next_fixed(state, current);
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
	struct Board *board,
	struct State *state,
	const struct Coordinate *current)
{
	if (board->grid[current->row][current->col] == VISITED_FIXED)
	{
		state->next_fixed = current + 1;

		while (state->next_fixed->row == UNKNOWN)
		{
			(state->next_fixed)++;
		}
	}
}

BOOL valid_move(
	struct Board *board,
	const struct State *state,
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
	struct State *state,
	struct Coordinate *current)
{
	if (state->board[current->row][current->col] == FREE)
	{
		current->row = UNKNOWN;
		current->col = UNKNOWN;
	}
}

void revert_next_fixed(
	struct State *state,
	const struct Coordinate *current)
{
	if (state->board[current->row][current->col] == FIXED)
	{
		state->next_fixed = current;
	}
}

BOOL sensible_move(
	const struct State *state,
	const struct Coordinate *next,
	const struct Coordinate *neighbour)
{
	if (state->next_fixed < state->hamiltonian + state->ham_length - 1)
	{
		int dist = distance(neighbour, state->next_fixed);
		int available_steps = state->next_fixed - next;
		int is_ok = dist <= available_steps;
		return is_ok;
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