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

	printf("Score: %d\n\n", assess_solution(&numbers));

	copy_board(&initial, &best_solution);

	int n = 3;
	int size = 3;
	int A[] = { 1, 2, 3 };
	generate(n, A, size);


	printf("\n\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d", A[i]);
	}

	//climb_hills(&initial, &best_solution, &numbers);

	/*
	printf("Best solution:\n\n");
	print_board(&best_solution, &numbers);
	printf("Score: %d\n\n", assess_solution(&numbers));
	*/
	
}