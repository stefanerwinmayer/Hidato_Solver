#include "sput.h"
#include "../init_state.h"
#include "../backtracker.h"

struct State state;
struct Coordinate start;
BOOL smart;

static void test_backtrack_solvable()
{
	initialise_state("[1]", &state, &start);
	
	sput_fail_unless(
		backtrack(&state, &start, 0, smart),
		"Backtracking [1] should succeed."
	);

	initialise_state("[?][1]", &state, &start);
	sput_fail_unless(
		backtrack(&state, &start, 0, smart),
		"Backtracking [?][1] should succeed."
	);

	initialise_state("[?][1]\n[2][?]", &state, &start);
	sput_fail_unless(
		backtrack(&state, &start, 0, smart),
		"Backtracking [?][1]\\n[2][?] should succeed."
	);
}

static void test_backtrack_unsolvable()
{
	initialise_state("[1][?][2]", &state, &start);

	sput_fail_if(
		backtrack(&state, &start, 0, smart),
		"Backtracking [1][?][2] should fail."
	);
}

int run_backtracker_algorithm_tests(void)
{
	sput_start_testing();

	sput_enter_suite("test_backtrack_solvable()");
	sput_run_test(test_backtrack_solvable);

	sput_enter_suite("test_backtrack_unsolvable()");
	sput_run_test(test_backtrack_unsolvable);

	sput_finish_testing();

	return sput_get_return_value();
}