#include <stdlib.h>
#include "sput.h"
#include "../state_struct.h"
#include "../init_state.h"
#include "../coordinate_struct.h"

struct State state_1;
struct State state_2;
struct State state_3;
struct State state_4;
struct State state_5;
struct State state_6;
struct State state_7;
struct State state_8;
struct State state_9;

struct Coordinate start;

static void setup(void)
{
	initialise_state("[1]", &state_1, &start);

	initialise_state("[11]", &state_2, &start);

	initialise_state("[?]", &state_3, &start);

	initialise_state("[x]", &state_4, &start);

	initialise_state("[09]", &state_5, &start);

	initialise_state("[??]", &state_6, &start);

	initialise_state("[XX]", &state_7, &start);

	initialise_state("[01][??]", &state_8, &start);

	initialise_state("[01][??]\n[XX][02]", &state_9, &start);
}

static void test_initialise_state_board()
{
	sput_fail_unless(
		state_1.board[0][0] == 'F',
		"[1]");

	sput_fail_unless(
		state_2.board[0][0] == 'F',
		"[11]");

	sput_fail_unless(
		state_3.board[0][0] == '?',
		"[?]");

	sput_fail_unless(
		state_4.board[0][0] == 'X',
		"[x]");

	sput_fail_unless(
		state_5.board[0][0] == 'F',
		"[09]");

	sput_fail_unless(
		state_6.board[0][0] == '?',
		"[??]");

	sput_fail_unless(
		state_7.board[0][0] == 'X',
		"[XX]");

	sput_fail_unless(
		state_8.board[0][0] == 'F' &&
		state_8.board[0][1] == '?',
		"[01][??]");

	sput_fail_unless(
		state_9.board[0][0] == 'F' &&
		state_9.board[0][1] == '?' &&
		state_9.board[1][0] == 'X' &&
		state_9.board[1][1] == 'F',
		"[01][??]\\n[XX][02]");
}

static void test_initialise_state_board_rows()
{
	sput_fail_unless(
		state_1.board_rows == 1,
		"[1]");

	sput_fail_unless(
		state_2.board_rows == 1,
		"[11]");

	sput_fail_unless(
		state_3.board_rows == 1,
		"[?]");

	sput_fail_unless(
		state_4.board_rows == 1,
		"[x]");

	sput_fail_unless(
		state_5.board_rows == 1,
		"[09]");

	sput_fail_unless(
		state_6.board_rows == 1,
		"[??]");

	sput_fail_unless(
		state_7.board_rows == 1,
		"[XX]");

	sput_fail_unless(
		state_8.board_rows == 1,
		"[01][??]");

	sput_fail_unless(
		state_9.board_rows == 2,
		"[01][??]\\n[XX][02]");
}

static void test_initialise_state_board_cols()
{
	sput_fail_unless(
		state_1.board_cols == 1,
		"[1]");

	sput_fail_unless(
		state_2.board_cols == 1,
		"[11]");

	sput_fail_unless(
		state_3.board_cols == 1,
		"[?]");

	sput_fail_unless(
		state_4.board_cols == 1,
		"[x]");

	sput_fail_unless(
		state_5.board_cols == 1,
		"[09]");

	sput_fail_unless(
		state_6.board_cols == 1,
		"[??]");

	sput_fail_unless(
		state_7.board_cols == 1,
		"[XX]");

	sput_fail_unless(
		state_8.board_cols == 2,
		"[01][??]");

	sput_fail_unless(
		state_9.board_cols == 2,
		"[01][??]\\n[XX][02]");
}

static void test_initialise_state_hamiltonian_rows()
{
	sput_fail_unless(
		state_1.hamiltonian[0].row == 0,
		"[1]");

	sput_fail_unless(
		state_2.hamiltonian[10].row == 0,
		"[11]");

	sput_fail_unless(
		state_5.hamiltonian[8].row == 0,
		"[09]");

	sput_fail_unless(
		state_8.hamiltonian[0].row == 0,
		"[01][??]");

	sput_fail_unless(
		state_9.hamiltonian[0].row == 0 &&
		state_9.hamiltonian[1].row == 1,
		"[01][??]\\n[XX][02]");
}

static void test_initialise_state_hamiltonian_cols()
{
	sput_fail_unless(
		state_1.hamiltonian[0].col == 0,
		"[1]");

	sput_fail_unless(
		state_2.hamiltonian[10].col == 0,
		"[11]");

	sput_fail_unless(
		state_5.hamiltonian[8].col == 0,
		"[09]");

	sput_fail_unless(
		state_8.hamiltonian[0].col == 0,
		"[01][??]");

	sput_fail_unless(
		state_9.hamiltonian[0].col == 0 &&
		state_9.hamiltonian[1].col == 1,
		"[01][??]\\n[XX][02]");
}

int run_init_state_tests(void)
{
	setup();

	sput_start_testing();

	sput_enter_suite("test_initialise_state_board()");
	sput_run_test(test_initialise_state_board);

	sput_enter_suite("test_initialise_state_board_rows()");
	sput_run_test(test_initialise_state_board_rows);

	sput_enter_suite("test_initialise_state_board_cols");
	sput_run_test(test_initialise_state_board_cols);

	sput_enter_suite("test_initialise_state_hamiltonian_rows()");
	sput_run_test(test_initialise_state_hamiltonian_rows);

	sput_enter_suite("test_initialise_state_hamiltonian_cols()");
	sput_run_test(test_initialise_state_hamiltonian_cols);

	sput_finish_testing();

	return sput_get_return_value();
}