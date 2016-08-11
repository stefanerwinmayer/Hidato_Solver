#include "sput.h"
#include "../state_struct.h"
#include "../init_state.h"
#include "../coordinate_struct.h"

#define N 9

struct State state_1;

static void allocate_memory(struct State *state)
{
	int i;

	state->hamiltonian = malloc(N * sizeof(struct Coordinate));

	state->board = malloc(N * sizeof(char));
	for (i = 0; i < N; i++)
	{
		state->board[i] = malloc(N * sizeof(char));
	}
}

static void setup(void)
{
	allocate_memory(&state_1);
	initialise_state("[1]", &state_1);
}

static void test_initialise_state_board()
{
	sput_fail_unless(
		state_1.board[0][0] == 'F',
		"");
}

static void test_initialise_state_board_rows()
{
	sput_fail_unless(
		state_1.board_rows == 1,
		"");
}

static void test_initialise_state_board_cols()
{
	sput_fail_unless(
		state_1.board_cols == 1,
		"");
}

static void test_initialise_state_hamiltonian_rows()
{
	sput_fail_unless(
		state_1.hamiltonian[0].row == 0,
		"");
}

static void test_initialise_state_hamiltonian_cols()
{
	sput_fail_unless(
		state_1.hamiltonian[0].col == 0,
		"");
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