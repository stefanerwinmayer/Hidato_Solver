#include "hillclimber_runner.h"

void run_hillclimber(char *input)
{
	struct Num_Coordinates numbers;
	struct Board initial;
	struct Board best_solution;

	initialise_state(input, &initial, &numbers);

	printf("Input Hidato:\n\n");
	print_board(&initial, &numbers);

	
	printf("Solving the puzzle with the hill climber algorithm:\n\n");
	
	produce_random_solution(&initial, &numbers);

	printf("Random solution:\n\n");
	print_board(&initial, &numbers);
	/*
	printf("Score: %d\n\n", assess_solution(&initial));

	copy_board(&initial, &best_solution);

	printf("Best solution:\n\n");
	print_solution(&best_solution);
	printf("Score: %d\n\n", assess_solution(&best_solution));
	*/
	
}