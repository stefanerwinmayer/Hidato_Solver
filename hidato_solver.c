#include "hidato_solver.h"

int main(int argc, char *argv[])
{
	struct State state;
	struct Coordinate start;
	BOOL smart;
	char input[MAX_FILE_LENGTH];

	printf("Welcome to Hidato!\n\n");

	if (strcmp(argv[1], "-b") == 0)
	{
		smart = FALSE;
	}
	else if(strcmp(argv[1], "-sb") == 0)
	{
		smart = TRUE;
	}

	if (strcmp(argv[2], "") != 0)
	{
		file_to_string(argv[2], input);
	}

	initialise_state(input, &state, &start);
	
	printf("Input Hidato:\n\n");
	print_board(&state);

	state.backtrack_counter = 0;

	backtrack(&state, &start, INITIAL_HAM_POS, smart);

	printf("Hamiltonian Path:\n");
	print_hamiltonian_path(&state);

	printf("Solved Hidato:\n\n");
	print_board(&state);

	printf("Number of calls to backtrack: %d", state.backtrack_counter);

	(void)getchar();
	return 0;
}