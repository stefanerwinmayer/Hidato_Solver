#include <stdlib.h>
#include "sput.h"
#include "../file_reader.h"
#include "../init_state.h"
#include "../coordinate_struct.h"




static void setup(void)
{

}

static void test_initialise_test_puzzle_1()
{
	/* [1][?][?]
	 * [?][X][6]
	 * [?][4][?]
	 */

	char input[MAX_FILE_LENGTH];
	struct Board board;
	struct Num_Coordinates numbers;


	file_to_string("test_puzzle_1.txt", input);

	sput_fail_unless(
		initialise_state(input, &board, &numbers) == TRUE,
		"Valid puzzle -> initialise_state() = TRUE"
	);

	sput_fail_unless(
		board.grid[0][0] == FIXED && board.grid[0][1] == FREE    && board.grid[0][2] == FREE &&
		board.grid[1][0] == FREE  && board.grid[1][1] == BLOCKED && board.grid[1][2] == FIXED &&
		board.grid[2][0] == FREE  && board.grid[2][1] == FIXED   && board.grid[2][2] == FREE,
		"Node states"
	);

	sput_fail_unless(
		board.rows == 3 && board.cols == 3,
		"Rows = 3 and Columns = 3"
	);

	sput_fail_unless(
		numbers.coordinates[0].row == 0       && numbers.coordinates[0].col == 0 &&
		numbers.coordinates[1].row == UNKNOWN && numbers.coordinates[1].col == UNKNOWN &&
		numbers.coordinates[2].row == UNKNOWN && numbers.coordinates[2].col == UNKNOWN &&
		numbers.coordinates[3].row == 2       && numbers.coordinates[3].col == 1 &&
		numbers.coordinates[4].row == UNKNOWN && numbers.coordinates[4].col == UNKNOWN &&
		numbers.coordinates[5].row == 1       && numbers.coordinates[5].col == 2 &&
		numbers.coordinates[6].row == UNKNOWN && numbers.coordinates[6].col == UNKNOWN &&
		numbers.coordinates[7].row == UNKNOWN && numbers.coordinates[7].col == UNKNOWN,
		"Number Coordinates"
	);

	sput_fail_unless(
		numbers.count == 8,
		"Numbers count = 8"
	);

	sput_fail_unless(
		numbers.next_fixed == numbers.coordinates &&
		numbers.next_fixed->row == 0 && numbers.next_fixed->col == 0,
		"First initially reavealed number = 1 at (0, 0)"
	);
}

int run_init_state_tests(void)
{
	sput_start_testing();

	sput_enter_suite("test_initialise_test_puzzle_1()");
	sput_run_test(test_initialise_test_puzzle_1);

	sput_finish_testing();

	return sput_get_return_value();
}