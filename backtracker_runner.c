#include "backtracker_runner.h"

void run_backtracker(
	struct Board *board,
	struct Num_Coordinates *numbers,
	BOOL smart)
{
	int iterations = 0;

	printf("Input Hidato:\n\n");
	print_board(board, numbers);
	printf("Solving the puzzle with the ");
	(smart) ? printf("smart ") : printf("regular ");
	printf("backtracker:\n\n");

	backtrack(board, numbers, numbers->coordinates, &iterations, smart);

	print_board(board, numbers);

	printf("Hamiltonian Path:\n\n");
	print_hamiltonian_path(numbers);

	printf("Number of iterations by the ");
	(smart) ? printf("smart ") : printf("regular ");
	printf("backtracker: %d\n", iterations);
}