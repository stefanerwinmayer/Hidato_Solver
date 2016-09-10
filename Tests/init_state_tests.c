#include <stdlib.h>
#include "sput.h"
#include "../init_state.h"
#include "../coordinate_struct.h"

struct Coordinate start_1 = { -1, -1 };
struct Coordinate start_2 = { -1, -1 };
struct Coordinate start_3 = { -1, -1 };
struct Coordinate start_4 = { -1, -1 };
struct Coordinate start_5 = { -1, -1 };
struct Coordinate start_6 = { -1, -1 };
struct Coordinate start_7 = { -1, -1 };
struct Coordinate start_8 = { -1, -1 };
struct Coordinate start_9 = { -1, -1 };
struct Coordinate start_10 = { -1, -1 };
struct Coordinate start_11 = { -1, -1 };

static void setup(void)
{

}

static void test_initialise_state_board()
{
	
}

static void test_initialise_state_board_rows()
{
	
}

static void test_initialise_state_board_cols()
{

}

static void test_initialise_state_hamiltonian_rows()
{
	
}

static void test_initialise_state_hamiltonian_cols()
{
	
}

static void test_initialise_state_ham_length()
{
	
}

static void test_initialise_state_start_coordinate()
{
	/*
	sput_fail_unless(
		state_11.hamiltonian[0].row == 0 &&
		state_11.hamiltonian[0].col == 1,
		"Number 1 is at (0, 1)");
		*/
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

	sput_enter_suite("test_initialise_state_ham_length()");
	sput_run_test(test_initialise_state_ham_length);

	sput_enter_suite("test_initialise_state_start_coordinate()");
	sput_run_test(test_initialise_state_start_coordinate);

	sput_finish_testing();

	return sput_get_return_value();
}