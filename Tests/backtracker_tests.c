#include "sput.h"
#include "../backtracker.h"

struct Coordinate current;

struct State state_1;
struct State state_2;


static void setup()
{
	current.row = 1;
	current.col = 1;

	state_1.board[1][1] = FREE;
	state_1.hamiltonian[1].row = UNKNOWN;
	state_1.hamiltonian[1].col = UNKNOWN;

	state_2.board[1][1] = FIXED;
}

static void test_update_state_free()
{
	update_state(&state_1, &current, 1);
	sput_fail_unless(
		state_1.board[1][1] == TAKEN,
		"Was FREE, after update should be TAKEN.");

	sput_fail_unless(
		state_1.hamiltonian[1].row == 1 &&
		state_1.hamiltonian[1].col == 1,
		"Coordinates were UNKNOWN, now they shoule be (1, 1)");
}

static void test_update_state_fixed()
{
	update_state(&state_2, &current, 1);
	sput_fail_unless(
		state_2.board[1][1] == VISITED_FIXED,
		"Was FIXED, after update should be VISITED_FIXED");
}

int run_backtracker_tests(void)
{
	setup();

	sput_start_testing();

	sput_enter_suite("test_update_state_free()");
	sput_run_test(test_update_state_free);

	sput_enter_suite("test_update_state_fixed()");
	sput_run_test(test_update_state_fixed);

	sput_finish_testing();

	return sput_get_return_value();

}