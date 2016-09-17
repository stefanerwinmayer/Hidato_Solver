#include "sput.h"
#include "../backtracker.h"

static void test_distance()
{
}

int run_backtracker_functions_tests(void)
{
	sput_start_testing();

	sput_enter_suite("test_distance()");
	sput_run_test(test_distance);

	sput_finish_testing();

	return sput_get_return_value();

}