#include "sput.h"
#include "../init_state.h"
#include "../backtracker.h"

static void test_backtrack_test_puzzle_1()
{

	sput_fail_if(
		0,
		""
	);
}

int run_backtracker_algorithm_tests(void)
{
	sput_start_testing();

	sput_enter_suite("test_backtrack_test_puzzle_1");
	sput_run_test(test_backtrack_test_puzzle_1);

	sput_finish_testing();

	return sput_get_return_value();
}