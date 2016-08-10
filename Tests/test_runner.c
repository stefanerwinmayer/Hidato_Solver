#include "test_runner.h"

int main(void)
{
	run_framework_tests();
	run_file_reader_tests();

	getchar();
	return 0;
}