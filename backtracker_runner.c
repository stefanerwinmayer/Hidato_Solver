#include "backtracker_runner.h"

void run_backtracker(
	char *input,
	BOOL smart)
{
	struct State state;
	struct Board board;
	struct Num_Coordinates numbers;

	initialise_state(input, &board, &state);

	printf("Input Hidato:\n\n");
	print_board(&board, &state);

	printf("Solving the puzzle with the ");
	(smart) ? printf("smart ") : printf("regular ");
	printf("backtracker:\n\n");

	state.backtrack_counter = 0;

	backtrack(&board, &state, state.hamiltonian, smart);

	print_board(&board, &state);

	printf("Hamiltonian Path:\n\n");
	print_hamiltonian_path(&state);

	printf("Number of calls to the ");
	(smart) ? printf("smart ") : printf("regular ");
	printf("backtracker: %d", state.backtrack_counter);
}