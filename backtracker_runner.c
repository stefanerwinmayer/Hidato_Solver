#include "backtracker_runner.h"

void run_backtracker(
	struct Board *board,
	struct Num_Coordinates *numbers,
	BOOL smart)
{
	int iterations = 0;

	printf("  The Input Hidato:\n\n");
	print_board(board, numbers);
	printf("  Solving the puzzle with the ");
	(smart) ? printf("smart ") : printf("regular ");
	printf("backtracker...\n\n");

	if (backtrack(board, numbers, numbers->coordinates, &iterations, smart))
	{

		print_board(board, numbers);

		printf("  Hamiltonian Path:\n\n");
		print_hamiltonian_path(numbers);

		printf("  Number Of ");
		(smart) ? printf("Smart ") : printf("Regular ");
		printf("Backtracker Iterations: %d\n", iterations);
	}
	else
	{
		printf("  The input file contains an unsolvable Hidato.\n");
		printf("  Either some number is impossible to reach or\n");
		printf("  some number is higher than the number of available nodes.");
	}
}