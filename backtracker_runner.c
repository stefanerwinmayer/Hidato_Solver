#include "backtracker_runner.h"

void run_backtracker(
	char *input,
	BOOL smart)
{
	struct State state;

	initialise_state(input, &state);

	printf("Input Hidato:\n\n");
	print_board(&state);

	printf("Solving the puzzle with the ");
	(smart) ? printf("smart ") : printf("regular ");
	printf("backtracker:\n\n");

	state.backtrack_counter = 0;

	backtrack(&state, state.hamiltonian, smart);

	print_board(&state);

	printf("Hamiltonian Path:\n\n");
	print_hamiltonian_path(&state);

	printf("Number of calls to the ");
	(smart) ? printf("smart ") : printf("regular ");
	printf("backtracker: %d", state.backtrack_counter);
}