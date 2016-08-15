#include "hidato_solver.h"

int main(void)
{
	struct State state;
	struct Coordinate start;
	char input[MAX_FILE_LENGTH];
	char filename[] = "sample.txt";

	printf("Welcome to Hidato!\n\n");

	file_to_string(filename, input);
	
	initialise_state(input, &state, &start);
	
	printf("Input Hidato:\n\n");
	print_board(&state);

	backtrack(&state, &start, INITIAL_HAM_POS);

	printf("Hamiltonian Path:\n");
	print_hamiltonian_path(&state);

	printf("Solved Hidato:\n\n");
	print_board(&state);

	(void)getchar();
	return 0;
}