#include "backtracker_runner.h"

void run_backtracker(
	char *input,
	BOOL smart)
{
	struct Board board;
	struct Num_Coordinates numbers;
	int counter = 0;

	initialise_state(input, &board, &numbers);

	printf("Input Hidato:\n\n");
	print_board(&board, &numbers);

	printf("Solving the puzzle with the ");
	(smart) ? printf("smart ") : printf("regular ");
	printf("backtracker:\n\n");

	backtrack(&board, &numbers, numbers.coordinates, &counter, smart);

	print_board(&board, &numbers);

	printf("Hamiltonian Path:\n\n");
	print_hamiltonian_path(&numbers);

	printf("Number of calls to the ");
	(smart) ? printf("smart ") : printf("regular ");
	printf("backtracker: %d", counter);
}