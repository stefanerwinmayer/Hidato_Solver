#include "hillclimber_runner.h"

void run_hillclimber(char *input)
{
	struct Num_Coordinates initial;
	struct Num_Coordinates best;
	struct Board board;
	int score;

	time_t t;
	srand((unsigned)time(&t));

	initialise_state(input, &board, &initial);

	printf("Input Hidato:\n\n");
	print_board(&board, &initial);

	printf("Solving the puzzle with the hill climber algorithm:\n\n");

	score = climb_hills(&board, &initial, &best);
	
	printf("Best solution:\n\n");
	print_board(&board, &initial);

	printf("Score: %d", score);
}