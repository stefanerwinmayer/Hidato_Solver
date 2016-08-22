#include "hillclimber_runner.h"

void run_hillclimber(char *input)
{
	struct Num_Coordinates initial;
	struct Num_Coordinates best;

	struct Num_Coordinates temp_solution;
	struct Board temp_board;

	struct Board board;
	BOOL solved = FALSE;

	time_t t;
	srand((unsigned)time(&t));

	initialise_state(input, &board, &initial);

	printf("Input Hidato:\n\n");
	print_board(&board, &initial);

	printf("Solving the puzzle with the hill climber algorithm:\n\n");

	while (!solved)
	{

		copy_solution(&initial, &temp_solution);
		copy_board(&board, &temp_board);

		solved = climb_hills(&temp_board, &temp_solution, &best);

	}

	copy_board(&temp_board, &board);

	printf("Best OVERALL solution:\n\n");
	print_board(&board, &best);
	printf("Score: %d\n\n", assess_solution(&best));

	solved ? printf("Solved!") : printf("Could not solve it!");
	
}