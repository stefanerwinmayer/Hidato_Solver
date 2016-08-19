#include "hillclimber_runner.h"

void run_hillclimber(char *input)
{
	struct Num_Coordinates initial;
	struct Board board;

	initialise_state(input, &board, &initial);

	printf("Input Hidato:\n\n");
	print_board(&board, &initial);

	
	printf("Solving the puzzle with the hill climber algorithm:\n\n");
	
	produce_random_solution(&board, &initial);

	printf("Random solution:\n\n");
	print_board(&board, &initial);

	printf("Score: %d\n\n", assess_solution(&initial));

	produce_variations(3, &board, &initial);

	//climb_hills(&initial, &best_solution, &numbers);

	/*
	printf("Best solution:\n\n");
	print_board(&best_solution, &numbers);
	printf("Score: %d\n\n", assess_solution(&numbers));
	*/
	
}