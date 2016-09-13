#include "hillclimber_runner.h"

void run_hillclimber(
	struct Board *board,
	struct Num_Coordinates *initial)
{
	int i, high_score = 0;
	int iterations = 0;
	int optimum_score;
	int points[MAX_NUMS] = { 0 };

	time_t t;
	srand((unsigned)time(&t));

	printf("Input Hidato:\n\n");
	print_board(board, initial);

	printf("Solving the puzzle with the hill climber algorithm:\n\n");

	climb_hills(board, initial, points, &iterations);

	printf("Best solution:\n\n");
	print_board(board, initial);

	optimum_score = initial->count - 1;

	printf("Best possible score: %d\n", optimum_score);

	for (i = 0; i < initial->count; i++)
	{
		high_score += points[i];
	}

	printf("Number of iterations: %d\n", iterations);
	printf("Achieved Score: %d\n", high_score);
	printf("Quality of solution: %.2lf %%\n", ((double)high_score / optimum_score) * 100);
}