#include "sput.h"
#include "../backtracker.h"

struct Coordinate current;
struct State state_1;
int ham_pos;

static void setup()
{
	current.row = 1;
	current.col = 1;
	ham_pos = 1;

	state_1.board[1][1] = FREE;
	state_1.hamiltonian[ham_pos].row = UNKNOWN;
	state_1.hamiltonian[ham_pos].col = UNKNOWN;
}

static void test_update_state_free()
{
	update_state(&state_1, &current, 1);
	sput_fail_unless(
		state_1.board[1][1] == TAKEN,
		"Was FREE, after update should be TAKEN");

	sput_fail_unless(
		state_1.hamiltonian[ham_pos].row == 1 &&
		state_1.hamiltonian[ham_pos].col == 1,
		"Coordinate was unknown, after update should have the coordinates of the current node");
}

int run_backtracker_tests(void)
{
	setup();

	sput_start_testing();

	sput_enter_suite("test_update_state_free()");
	sput_run_test(test_update_state_free);

	sput_finish_testing();

	return sput_get_return_value();

}