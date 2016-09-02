#include "hillclimber_runner.h"

void run_hillclimber(char *input)
{
	struct Num_Coordinates initial;
	struct Num_Coordinates best;
	struct Board board;
	int high_score;
	int optimum_score;

	time_t t;
	srand((unsigned)time(&t));

	initialise_state(input, &board, &initial);
	optimum_score = initial.count - 1;

	printf("Input Hidato:\n\n");
	print_board(&board, &initial);

	printf("Solving the puzzle with the hill climber algorithm:\n\n");

	high_score = climb_hills(&board, &initial, &best);
	
	printf("Best solution:\n\n");
	print_board(&board, &initial);

	printf("Best possible score: %d\n", optimum_score);
	printf("Achieved Score: %d\n", high_score);
	printf("Quality of solution: %.2lf\n", ((double)high_score / optimum_score) * 100);
	if (high_score != optimum_score)
	{
		printf("NOT ");
	}
	printf("SOLVED!");
}