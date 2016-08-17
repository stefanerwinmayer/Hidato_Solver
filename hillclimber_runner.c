#include "hillclimber_runner.h"

void run_hillclimber(char *input)
{
	struct HC_State state;

	initialise_hillclimber(input, &state);

	printf("Input Hidato:\n\n");
	print_solution(&state);

	printf("Solving the puzzle with the hill climber algorithm:\n\n");
}