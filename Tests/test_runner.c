#include <stdlib.h>
#include "test_runner.h"

int main(void)
{
	if (!run_framework_tests() &&
		!run_file_reader_tests() &&
		!run_init_state_tests() &&
		//!run_backtracker_functions_tests())// &&
		//!run_backtracker_algorithm_tests())
	{
		printf("\nALL TESTS SUCCEEDED!");
		(void)getchar();
		return 0;
	}
	else
	{
		(void)getchar();
		exit(EXIT_FAILURE);
	}
}