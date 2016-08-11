#include <stdlib.h>
#include "sput.h"
#include "../state_struct.h"
#include "../init_state.h"
#include "../coordinate_struct.h"

#define N 99
#define UNKNOWN -1

struct State state_1;
struct State state_2;
struct State state_3;

static void allocate_memory(struct State *state)
{
	int i;

	state->hamiltonian = malloc(N * sizeof(struct Coordinate));

	state->board = malloc(N * sizeof(char *));
	for (i = 0; i < N; i++)
	{
		state->board[i] = malloc(N * sizeof(char));
	}
}

static void deallocate_memory(struct State *state)
{
	int i;

	free(state->hamiltonian);

	for (i = 0; i < N; i++)
	{
		free(state->board[i]);
	}
	free(state->board);
}

static void setup(void)
{
	allocate_memory(&state_1);
	initialise_state("[1]", &state_1);

	allocate_memory(&state_2);
	initialise_state("[11]", &state_2);

	allocate_memory(&state_3);
	initialise_state("[?]", &state_3);
}

static void teardown(void)
{
	deallocate_memory(&state_1);
	deallocate_memory(&state_2);
	deallocate_memory(&state_3);
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
		state_3.board[0][0] == 'G',
		"[?]");
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
		state_3.hamiltonian[10].row == UNKNOWN,
		"[?]");
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
		state_3.hamiltonian[10].col == UNKNOWN,
		"[?]");
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

	teardown();

	return sput_get_return_value();
}