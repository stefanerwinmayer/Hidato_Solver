#include "sput.h"
#include "../file_reader.h"
#include "../hillclimber.h"

static void test_produce_random_solution()
{
	

}

int run_hillclimber_functions_tests(void)
{
	sput_start_testing();

	sput_enter_suite("test_produce_random_solution()");
	sput_run_test(test_produce_random_solution);

	sput_finish_testing();

	return sput_get_return_value();

}