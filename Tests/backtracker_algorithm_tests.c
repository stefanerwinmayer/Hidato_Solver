#include "sput.h"
#include "../init_state.h"
#include "../backtracker.h"

struct State state_1;
struct Coordinate start_1;

static void test_backtrack_solvable()
{
	initialise_state("[1]", &state_1, &start_1);
	
	sput_fail_unless(
		backtrack(&state_1, &start_1, 0),
		"Single known node should succeed."
	);
}

int run_backtracker_algorithm_tests(void)
{
	sput_start_testing();

	sput_enter_suite("test_backtrack_solvable()");
	sput_run_test(test_backtrack_solvable);

	sput_finish_testing();

	return sput_get_return_value();
}