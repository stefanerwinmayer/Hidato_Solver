#include "sput.h"
#include "../backtracker.h"

struct Coordinate current;
struct State state_1;


static void setup()
{
	current.row = 1;
	current.col = 1;

	state_1.board[1][1] = FREE;
}

static void test_update_state_free()
{
	update_state(&state_1, &current, 0);
	sput_fail_unless(
		state_1.board[1][1] == TAKEN,
		"Was FREE, after update should be TAKEN");
}

int run_backtracker_tests(void)
{
	setup();

	sput_start_testing();

	sput_enter_suite("test_update_state()");
	sput_run_test(test_update_state_board);

	sput_finish_testing();

	return sput_get_return_value();

}