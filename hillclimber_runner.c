#include "hillclimber_runner.h"

void run_hillclimber(char *input)
{
	struct Num_Coordinates initial;
	struct Num_Coordinates best;

	//struct Num_Coordinates temp_solution;
	//struct Board temp_board;

	struct Board board;
	BOOL solved = FALSE;
	//int attempt = 0;

	time_t t;
	srand((unsigned)time(&t));

	initialise_state(input, &board, &initial);

	printf("Input Hidato:\n\n");
	print_board(&board, &initial);

	printf("Solving the puzzle with the hill climber algorithm:\n\n");

	solved = climb_hills(&board, &initial, &best);
	
	printf("Best solution:\n\n");
	print_board(&board, &initial);

	/*
	while (!solved)
	{

		copy_solution(&initial, &temp_solution);
		copy_board(&board, &temp_board);

		solved = climb_hills(&temp_board, &temp_solution, &best);
		attempt++;

		printf("Best solution after %d. attempt:\n\n", attempt);
		print_board(&temp_board, &best);
		printf("Score: %d\n\n", assess_solution(&temp_solution));

	}

	printf("Solved after %d attempts.", attempt);
	*/
}