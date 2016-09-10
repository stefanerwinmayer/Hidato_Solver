#include <stdlib.h>
#include "sput.h"
#include "../init_state.h"
#include "../coordinate_struct.h"

static void setup(void)
{

}

static void test_initialise_state_board()
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

	sput_finish_testing();

	return sput_get_return_value();
}