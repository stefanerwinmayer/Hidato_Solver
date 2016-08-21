#include "hillclimber_runner.h"

void run_hillclimber(char *input)
{
	struct Num_Coordinates initial;
	struct Num_Coordinates best;
	struct Board board;

	initialise_state(input, &board, &initial);

	printf("Input Hidato:\n\n");
	print_board(&board, &initial);

	printf("Solving the puzzle with the hill climber algorithm:\n\n");
	
	climb_hills(&board, &initial, &best);

	printf("Best solution:\n\n");
	print_board(&board, &best);
	printf("Score: %d\n\n", assess_solution(&best));
	
	
}