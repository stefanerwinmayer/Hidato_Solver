#include "backtracker.h"

BOOL backtrack(struct State *state,
	const struct Coordinate *current,
	const int ham_pos,
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

	update_board(state, current);
	update_hamiltonian(state, current, ham_pos);

	if (smart)
	{
		update_next_fixed(state, current, ham_pos);
	}

	for (i = 0; i < NUMBER_OF_MOVES; i++)
	{
		neighbour.row = current->row + MOVE_SET[i].row;
		neighbour.col = current->col + MOVE_SET[i].col;

		if (valid_move(state, &neighbour, ham_pos + 1))
		{
			if (smart && !sensible_move(state, &neighbour, ham_pos + 1))
			{
				continue;
			}

			next->row = neighbour.row;
			next->col = neighbour.col;

			if (!backtrack(state, next, ham_pos + 1, smart))
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
		revert_board(state, current);
		revert_hamiltonian(state, current, ham_pos);

		if (smart)
		{
			revert_next_fixed(state, current, ham_pos);
		}

		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

void update_board(
	struct State *state,
	const struct Coordinate *current)
{
	switch (state->board[current->row][current->col])
	{
	case FREE:

		state->board[current->row][current->col] = TAKEN;
		break;

	case FIXED:

		state->board[current->row][current->col] = VISITED_FIXED;
		break;
	}
}

void update_hamiltonian(
	struct State *state,
	const struct Coordinate *current,
	const int ham_pos)
{
	switch (state->board[current->row][current->col])
	{
	case TAKEN:

		state->hamiltonian[ham_pos].row = current->row;
		state->hamiltonian[ham_pos].col = current->col;
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

void revert_board(struct State *state,
	const struct Coordinate *current)
{
	switch (state->board[current->row][current->col])
	{
	case TAKEN:

		state->board[current->row][current->col] = FREE;
		break;

	case VISITED_FIXED:

		state->board[current->row][current->col] = FIXED;
		break;
	}
}

void revert_hamiltonian(struct State *state,
	const struct Coordinate *current,
	const int ham_pos)
{
	switch (state->board[current->row][current->col])
	{
	case FREE:

		state->hamiltonian[ham_pos].row = UNKNOWN;
		state->hamiltonian[ham_pos].col = UNKNOWN;
		break;
	}
}

void revert_next_fixed(
	struct State *state,
	const struct Coordinate *current,
	const int ham_pos)
{
	if (state->board[current->row][current->col] == FIXED)
	{
		state->next_fixed_pos = ham_pos;
	}
}

BOOL sensible_move(
	const struct State *state,
	const struct Coordinate *next,
	const int next_ham_pos)
{
	if (state->next_fixed_pos < state->ham_length)
	{
		struct Coordinate next_fixed = state->hamiltonian[state->next_fixed_pos];
		int dist = distance(next, &next_fixed);
		int num_diff = state->next_fixed_pos - next_ham_pos;
		int is_ok = dist <= num_diff;
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