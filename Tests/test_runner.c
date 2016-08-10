#include <stdlib.h>
#include "test_runner.h"

int main(void)
{
	if (!run_framework_tests() &&
		!run_file_reader_tests())
	{
		printf("ALL TESTS SUCCEEDED!");
		getchar();
		return 0;
	}
	else
	{
		getchar();
		exit(EXIT_FAILURE);
	}
}