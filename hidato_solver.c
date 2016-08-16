#include "hidato_solver.h"

int main(void)
{
	struct State state;
	struct Coordinate start;
	BOOL smart = FALSE;
	char input[MAX_FILE_LENGTH];
	char filename[] = "sample.txt";

	printf("Welcome to Hidato!\n\n");

	file_to_string(filename, input);
	
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