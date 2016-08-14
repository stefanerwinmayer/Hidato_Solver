#include "backtracker.h"

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

BOOL valid_move(
	const struct State *state,
	const struct Coordinate *next,
	const int next_ham_pos)
{
	if (0 <= next->row && next->row < state->board_rows &&
		0 <= next->col && next->col < state->board_cols)
	{
		return TRUE;
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