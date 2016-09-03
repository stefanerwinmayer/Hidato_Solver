#ifdef _WIN32
#include <windows.h>
#endif

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

#ifdef _WIN32
	LARGE_INTEGER frequency;
	LARGE_INTEGER t1, t2;
	double elapsedTime;
#endif

	initialise_state(input, &board, &initial);
	optimum_score = initial.count - 1;

	printf("Input Hidato:\n\n");
	print_board(&board, &initial);

	printf("Solving the puzzle with the hill climber algorithm:\n\n");

#ifdef _WIN32
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&t1);
#endif

	high_score = climb_hills(&board, &initial, &best);

#ifdef _WIN32
	QueryPerformanceCounter(&t2);
	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
#endif

	printf("Best solution:\n\n");
	print_board(&board, &best);

	printf("Best possible score: %d\n", optimum_score);
	printf("Achieved Score: %d\n", high_score);
	printf("Quality of solution: %.2lf %%\n", ((double)high_score / optimum_score) * 100);

#ifdef _WIN32
	printf("Runtime: %lf ms", elapsedTime);
#endif
}