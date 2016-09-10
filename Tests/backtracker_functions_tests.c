#include "sput.h"
#include "../backtracker.h"

struct Coordinate current;

struct State state_1;
struct State state_2;
struct State state_3;
struct State state_4;

static void setup()
{
	current.row = 1;
	current.col = 1;
}

static void test_update_state_free()
{
	state_1.board[1][1] = FREE;
	state_1.hamiltonian[1].row = UNKNOWN;
	state_1.hamiltonian[1].col = UNKNOWN;

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
	state_2.board[1][1] = FIXED;

	update_state(&state_2, &current, 1);

	sput_fail_unless(
		state_2.board[1][1] == VISITED_FIXED,
		"Was FIXED, after update should be VISITED_FIXED");
}

static void test_revert_state_taken()
{
	state_3.board[1][1] = TAKEN;
	state_3.hamiltonian[1].row = 1;
	state_3.hamiltonian[1].col = 1;

	revert_state(&state_3, &current, 1);

	sput_fail_unless(
		state_3.board[1][1] == FREE,
		"Was TAKEN, after revert should be FREE");

	sput_fail_unless(
		state_3.hamiltonian[1].row == UNKNOWN &&
		state_3.hamiltonian[1].col == UNKNOWN,
		"Coordinates were assigned, after revert they should be UNKNOWN");
}

static void test_revert_state_visited_fixed()
{
	state_4.board[1][1] = VISITED_FIXED;

	revert_state(&state_4, &current, 1);

	sput_fail_unless(
		state_4.board[1][1] == FIXED,
		"Was VISITED_FIXED, after revert should be FIXED");
}

static void test_valid_move_out_of_lower_bounds()
{
	struct State state;
	state.board_rows = 9;
	state.board_cols = 9;

	struct Coordinate outside_1 = { -1, -1 };
	struct Coordinate outside_2 = { -1, 0 };
	struct Coordinate outside_3 = { 0, -1 };

	sput_fail_if(
		valid_move(&state, &outside_1, 1),
		"Negative coordiantes should fail valid move.");

	sput_fail_if(
		valid_move(&state, &outside_2, 1),
		"Negative row coordiante should fail valid move.");

	sput_fail_if(
		valid_move(&state, &outside_3, 1),
		"Negative col coordiante should fail valid move.");
}

static void test_valid_move_out_of_upper_bounds()
{
	struct State state;
	state.board_rows = 9;
	state.board_cols = 9;

	struct Coordinate outside_1 = { 9, 9 };
	struct Coordinate outside_2 = { 9, 8 };
	struct Coordinate outside_3 = { 8, 9 };

	sput_fail_if(
		valid_move(&state, &outside_1, 1),
		"Coordiantes too large should fail valid move.");

	sput_fail_if(
		valid_move(&state, &outside_2, 1),
		"Row coordiante too large should fail valid move.");

	sput_fail_if(
		valid_move(&state, &outside_3, 1),
		"Col coordiante too large should fail valid move.");
}

static void test_valid_move_free()
{
	struct State state;
	state.board_rows = 9;
	state.board_cols = 9;
	state.board[1][1] = FREE;
	state.hamiltonian[1].row = UNKNOWN;
	state.hamiltonian[1].col = UNKNOWN;

	struct Coordinate next = { 1, 1 };

	sput_fail_unless(
		valid_move(&state, &next, 1),
		"Next Coordinate is free and next number unknown, so it should be a valid move.");

	state.hamiltonian[1].row = 2;
	state.hamiltonian[1].col = 2;

	sput_fail_if(
		valid_move(&state, &next, 1),
		"Next Coordinate is free but next number is fixed and not there so it should be an invalid move.");
}

static void test_valid_move_fixed()
{
	struct State state;
	state.board_rows = 9;
	state.board_cols = 9;
	state.board[1][1] = FIXED;

	state.hamiltonian[1].row = 9;
	state.hamiltonian[1].col = 9;

	struct Coordinate next = { 1, 1 };

	sput_fail_if(
		valid_move(&state, &next, 1),
		"Next Coordinate is fixed and visitable but it belongs to the wrong number.");

	state.hamiltonian[1].row = 1;
	state.hamiltonian[1].col = 1;

	sput_fail_unless(
		valid_move(&state, &next, 1),
		"Next Coordinate is fixed and it belongs to the next number.");
}

static void test_valid_move_taken()
{
	struct State state;
	state.board_rows = 9;
	state.board_cols = 9;
	state.board[1][1] = TAKEN;

	struct Coordinate next = { 1, 1 };

	sput_fail_if(
		valid_move(&state, &next, 1),
		"Next Coordinate was already visited, invalid move.");
}

static void test_valid_move_visited_fixed()
{
	struct State state;
	state.board_rows = 9;
	state.board_cols = 9;
	state.board[1][1] = VISITED_FIXED;

	struct Coordinate next = { 1, 1 };

	sput_fail_if(
		valid_move(&state, &next, 1),
		"Next Coordinate is fixed but visited already, invalid move.");

}

static void test_valid_move_blocked()
{
	struct State state;
	state.board_rows = 9;
	state.board_cols = 9;
	state.board[1][1] = BLOCKED;

	struct Coordinate next = { 1, 1 };

	sput_fail_if(
		valid_move(&state, &next, 1),
		"Next Coordinate is blocked, invalid move.");
}

static void test_distance()
{
	struct Coordinate first = { 0, 0 };
	struct Coordinate second = { 2, 2 };
	struct Coordinate third = { 1, 2 };
	struct Coordinate fourth = { 1, 1 };
	struct Coordinate fifth = { 0, 0 };
	struct Coordinate sixth = { 0, 2 };

	sput_fail_unless(
		distance(&first, &second) == 2,
		"Distance between (0, 0) and (2, 2) should be 2.");

	sput_fail_unless(
		distance(&first, &third) == 2,
		"Distance between (0, 0) and (1, 2) should be 2.");

	sput_fail_unless(
		distance(&first, &fourth) == 1,
		"Distance between (0, 0) and (1, 1) should be 1.");

	sput_fail_unless(
		distance(&first, &fifth) == 0,
		"Distance between (0, 0) and (0, 0) should be 0.");

	sput_fail_unless(
		distance(&first, &sixth) == 2,
		"Distance between (0, 0) and (0, 2) should be 2.");
}

int run_backtracker_functions_tests(void)
{
	setup();

	sput_start_testing();

	/*
	sput_enter_suite("test_update_state_free()");
	sput_run_test(test_update_state_free);

	sput_enter_suite("test_update_state_fixed()");
	sput_run_test(test_update_state_fixed);

	sput_enter_suite("test_revert_state_taken()");
	sput_run_test(test_revert_state_taken);

	sput_enter_suite("test_revert_state_visited_fixed()");
	sput_run_test(test_revert_state_visited_fixed);
	*/

	sput_enter_suite("test_valid_move_out_of_lower_bounds()");
	sput_run_test(test_valid_move_out_of_lower_bounds);

	sput_enter_suite("test_valid_move_out_of_upper_bounds()");
	sput_run_test(test_valid_move_out_of_upper_bounds);

	sput_enter_suite("test_valid_move_free()");
	sput_run_test(test_valid_move_free);

	sput_enter_suite("test_valid_move_fixed()");
	sput_run_test(test_valid_move_fixed);

	sput_enter_suite("test_valid_move_taken()");
	sput_run_test(test_valid_move_taken);

	sput_enter_suite("test_valid_move_visited_fixed()");
	sput_run_test(test_valid_move_visited_fixed);

	sput_enter_suite("test_valid_move_blocked()");
	sput_run_test(test_valid_move_blocked);

	sput_enter_suite("test_distance()");
	sput_run_test(test_distance);

	sput_finish_testing();

	return sput_get_return_value();

}