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

	printf(" The Input Hidato:\n\n");
	print_board(board, initial);

	printf("\n Solving the puzzle with the hill-climber algorithm...\n\n");

	climb_hills(board, initial, points, &iterations);

	printf(" Best Solution:\n\n");
	print_board(board, initial);

	optimum_score = initial->count - 1;

	printf("\n Optimum Score:  %3d\n", optimum_score);

	for (i = 0; i < initial->count; i++)
	{
		high_score += points[i];
	}

	printf(" Achieved Score: %3d\n\n", high_score);
	printf(" Number Of Hill-Climber Iterations: %d\n", iterations);
}