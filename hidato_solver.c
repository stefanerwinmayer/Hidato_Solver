#include "hidato_solver.h"

int main(int argc, char *argv[])
{
	struct State state;
	BOOL backtracking, smart, hill_climbing;
	char input[MAX_FILE_LENGTH];

	backtracking = smart = hill_climbing = FALSE;

	printf("Welcome to Hidato!\n\n");

	if (strcmp(argv[1], "-b") == 0)
	{
		backtracking = TRUE;
	}
	else if (strcmp(argv[1], "-sb") == 0)
	{
		backtracking = TRUE;
		smart = TRUE;
	}
	else if (strcmp(argv[1], "-h") == 0)
	{
		hill_climbing = TRUE;
	}
	else
	{
		printf("Invalid input. Please specify the algorithm: -b or -sb or -h");
		(void)getchar();
		exit(EXIT_FAILURE);
	}


	if (strcmp(argv[2], "") != 0)
	{
		file_to_string(argv[2], input);
	}

	if (backtracking)
	{
		initialise_state(input, &state);

		printf("Input Hidato:\n\n");
		print_board(&state);

		state.backtrack_counter = 0;

		backtrack(&state, state.hamiltonian, smart);

		printf("Hamiltonian Path:\n");
		print_hamiltonian_path(&state);

		printf("Solved Hidato:\n\n");
		print_board(&state);

		printf("Number of calls to backtrack: %d", state.backtrack_counter);
	}

	(void)getchar();
	return 0;
}