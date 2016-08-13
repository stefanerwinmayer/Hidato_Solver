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
	}
}