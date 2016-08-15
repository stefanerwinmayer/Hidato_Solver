#include "backtracker.h"

BOOL backtrack(struct State *state,
	const struct Coordinate *current,
	const int ham_pos,
	const BOOL smart)
{
	int i;
	struct Coordinate next;

	static const struct Coordinate MOVE_SET[] =
	{
		{ -1, -1 },{ -1, 0 },{ -1, 1 },
		{  0, -1 },          {  0, 1 },
		{  1, -1 },{  1, 0 },{  1, 1 }
	};

	update_state(state, current, ham_pos);

	for (i = 0; i < NUMBER_OF_MOVES; i++)
	{
		next.row = current->row + MOVE_SET[i].row;
		next.col = current->col + MOVE_SET[i].col;

		if (valid_move(state, &next, ham_pos + 1))
		{
			if (!backtrack(state, &next, ham_pos + 1, smart))
			{
				continue;
			}
			else
			{
				return TRUE;
			}
		}
	}

	if (ham_pos != state->ham_length - 1) /* if not solved yet */
	{
		revert_state(state, current, ham_pos);
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

void update_state(
	struct State *state,
	const struct Coordinate *current,
	const int ham_pos)
{
	switch (state->board[current->row][current->col])
	{
	case FREE:

		state->hamiltonian[ham_pos].row = current->row;
		state->hamiltonian[ham_pos].col = current->col;
		state->board[current->row][current->col] = TAKEN;
		break;

	case FIXED:

		state->board[current->row][current->col] = VISITED_FIXED;
		break;
	}
}

void update_next_fixed(
	struct State *state,
	const struct Coordinate *current,
	const int ham_pos)
{
	if (state->board[current->row][current->col] == VISITED_FIXED)
	{
		state->next_fixed_pos = ham_pos + 1;

		while (state->hamiltonian[state->next_fixed_pos].row == UNKNOWN)
		{
			(state->next_fixed_pos)++;
		}
	}
}

BOOL valid_move(
	const struct State *state,
	const struct Coordinate *next,
	const int next_ham_pos)
{
	if (0 <= next->row && next->row < state->board_rows &&
		0 <= next->col && next->col < state->board_cols)
	{
		if (state->board[next->row][next->col] == FREE &&
			state->hamiltonian[next_ham_pos].row == UNKNOWN)
		{
			return TRUE;
		}
		else if (state->board[next->row][next->col] == FIXED &&
			state->hamiltonian[next_ham_pos].row == next->row &&
			state->hamiltonian[next_ham_pos].col == next->col)
		{
			return TRUE;
		}
	}
	return FALSE;
}

void revert_state(struct State *state,
	const struct Coordinate *current,
	const int ham_pos)
{
	switch (state->board[current->row][current->col])
	{
	case TAKEN:

		state->hamiltonian[ham_pos].row = UNKNOWN;
		state->hamiltonian[ham_pos].col = UNKNOWN;
		state->board[current->row][current->col] = FREE;
		break;

	case VISITED_FIXED:

		state->board[current->row][current->col] = FIXED;
		break;
	}
}

BOOL sensible_move(
	const struct State *state,
	const struct Coordinate *next,
	const int next_ham_pos)
{
	return FALSE;
}

int distance(
	const struct Coordinate *first,
	const struct Coordinate *second)
{
	return (int)fmax(abs(first->row - second->row), abs(first->col - second->col));
}