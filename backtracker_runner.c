#ifdef _WIN32
#include <windows.h>
#endif

#include "backtracker_runner.h"

void run_backtracker(
	char *input,
	BOOL smart)
{
	struct Board board;
	struct Num_Coordinates numbers;
	int counter = 0;

#ifdef _WIN32
	LARGE_INTEGER frequency;
	LARGE_INTEGER t1, t2;
	double elapsedTime;
#endif

	initialise_state(input, &board, &numbers);

	printf("Input Hidato:\n\n");
	print_board(&board, &numbers);
	printf("Solving the puzzle with the ");
	(smart) ? printf("smart ") : printf("regular ");
	printf("backtracker:\n\n");

#ifdef _WIN32
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&t1);
#endif

	backtrack(&board, &numbers, numbers.coordinates, &counter, smart);

#ifdef _WIN32
	QueryPerformanceCounter(&t2);
	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
#endif

	print_board(&board, &numbers);

	printf("Hamiltonian Path:\n\n");
	print_hamiltonian_path(&numbers);

	printf("Number of calls to the ");
	(smart) ? printf("smart ") : printf("regular ");
	printf("backtracker: %d\n", counter);

#ifdef _WIN32
	printf("Runtime: %lf ms", elapsedTime);
#endif
}