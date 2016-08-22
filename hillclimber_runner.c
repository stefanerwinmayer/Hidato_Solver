#include "hillclimber_runner.h"

void run_hillclimber(char *input)
{
	struct Num_Coordinates initial;
	struct Num_Coordinates best;
	struct Board board;
	BOOL outcome;
	int process_deriviate_counter = 0;

	initialise_state(input, &board, &initial);

	printf("Input Hidato:\n\n");
	print_board(&board, &initial);

	printf("Solving the puzzle with the hill climber algorithm:\n\n");

	outcome = climb_hills(&board, &initial, &best, &process_deriviate_counter);

	printf("Best OVERALL solution:\n\n");
	print_board(&board, &best);
	printf("Score: %d\n\n", assess_solution(&best));

	printf("Amount of calls to process_deriviate(): %d\n", process_deriviate_counter);
	outcome ? printf("Solved!") : printf("Could not solve it!");
	
}