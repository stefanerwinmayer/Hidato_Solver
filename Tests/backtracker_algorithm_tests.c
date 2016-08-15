#include "sput.h"
#include "../init_state.h"
#include "../backtracker.h"

struct State state;
struct Coordinate start;

static void test_backtrack_solvable_one_number()
{
	initialise_state("[1]", &state, &start);
	
	sput_fail_unless(
		backtrack(&state, &start, 0),
		"Single known node should succeed."
	);
}

int run_backtracker_algorithm_tests(void)
{
	sput_start_testing();

	sput_enter_suite("test_backtrack_solvable_one_number()");
	sput_run_test(test_backtrack_solvable_one_number);

	sput_finish_testing();

	return sput_get_return_value();
}