#include <stdlib.h>
#include "sput.h"
#include "../file_reader.h"
#include "../init_state.h"
#include "../coordinate_struct.h"

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
		"All nodes have the correct state"
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
		"All numbers have the correct coordinates"
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

static void test_initialise_test_puzzle_2()
{
	/* [7][6][X]
	 * [?][?][X]
	 * [4][?][1]
	 */

	char input[MAX_FILE_LENGTH];
	struct Board board;
	struct Num_Coordinates numbers;


	file_to_string("test_puzzle_2.txt", input);

	sput_fail_unless(
		initialise_state(input, &board, &numbers) == TRUE,
		"Valid puzzle -> initialise_state() = TRUE"
	);

	sput_fail_unless(
		board.grid[0][0] == FIXED && board.grid[0][1] == FIXED && board.grid[0][2] == BLOCKED &&
		board.grid[1][0] == FREE  && board.grid[1][1] == FREE  && board.grid[1][2] == BLOCKED &&
		board.grid[2][0] == FIXED && board.grid[2][1] == FREE && board.grid[2][2] == FIXED,
		"All nodes have the correct state"
	);

	sput_fail_unless(
		board.rows == 3 && board.cols == 3,
		"Rows = 3 and Columns = 3"
	);

	sput_fail_unless(
		numbers.coordinates[0].row == 2       && numbers.coordinates[0].col == 2 &&
		numbers.coordinates[1].row == UNKNOWN && numbers.coordinates[1].col == UNKNOWN &&
		numbers.coordinates[2].row == UNKNOWN && numbers.coordinates[2].col == UNKNOWN &&
		numbers.coordinates[3].row == 2       && numbers.coordinates[3].col == 0 &&
		numbers.coordinates[4].row == UNKNOWN && numbers.coordinates[4].col == UNKNOWN &&
		numbers.coordinates[5].row == 0       && numbers.coordinates[5].col == 1 &&
		numbers.coordinates[6].row == 0       && numbers.coordinates[6].col == 0,
		"All numbers have the correct coordinates"
	);

	sput_fail_unless(
		numbers.count == 7,
		"Numbers count = 7"
	);

	sput_fail_unless(
		numbers.next_fixed == numbers.coordinates &&
		numbers.next_fixed->row == 2 && numbers.next_fixed->col == 2,
		"First initially reavealed number = 1 at (2, 2)"
	);
}

static void test_initialise_test_puzzle_3()
{
	/* [X][4][?][X]
	 * [?][1][?][X]
	 * [2][?][?][X]
	 * [X][X][X][X]
	 */

	char input[MAX_FILE_LENGTH];
	struct Board board;
	struct Num_Coordinates numbers;


	file_to_string("test_puzzle_3.txt", input);

	sput_fail_unless(
		initialise_state(input, &board, &numbers) == TRUE,
		"Valid puzzle -> initialise_state() = TRUE"
	);

	sput_fail_unless(
		board.grid[0][0] == BLOCKED && board.grid[0][1] == FIXED &&
		board.grid[0][2] == FREE    && board.grid[0][3] == BLOCKED &&

		board.grid[1][0] == FREE    && board.grid[1][1] == FIXED &&
		board.grid[1][2] == FREE    && board.grid[1][3] == BLOCKED &&

		board.grid[2][0] == FIXED   && board.grid[2][1] == FREE &&
		board.grid[2][2] == FREE    && board.grid[2][3] == BLOCKED &&

		board.grid[3][0] == BLOCKED && board.grid[3][1] == BLOCKED &&
		board.grid[3][2] == BLOCKED && board.grid[3][3] == BLOCKED,
		"All nodes have the correct state"
	);

	sput_fail_unless(
		board.rows == 4 && board.cols == 4,
		"Rows = 4 and Columns = 4"
	);

	sput_fail_unless(
		numbers.coordinates[0].row == 1       && numbers.coordinates[0].col == 1 &&
		numbers.coordinates[1].row == 2       && numbers.coordinates[1].col == 0 &&
		numbers.coordinates[2].row == UNKNOWN && numbers.coordinates[2].col == UNKNOWN &&
		numbers.coordinates[3].row == 0       && numbers.coordinates[3].col == 1 &&
		numbers.coordinates[4].row == UNKNOWN && numbers.coordinates[4].col == UNKNOWN &&
		numbers.coordinates[5].row == UNKNOWN && numbers.coordinates[5].col == UNKNOWN &&
		numbers.coordinates[6].row == UNKNOWN && numbers.coordinates[6].col == UNKNOWN &&
		numbers.coordinates[7].row == UNKNOWN && numbers.coordinates[7].col == UNKNOWN,
		"All numbers have the correct coordinates"
	);

	sput_fail_unless(
		numbers.count == 8,
		"Numbers count = 8"
	);

	sput_fail_unless(
		numbers.next_fixed == numbers.coordinates &&
		numbers.next_fixed->row == 1 && numbers.next_fixed->col == 1,
		"First initially reavealed number = 1 at (2, 2)"
	);
}

static void test_initialise_test_puzzle_missing_one()
{
	/* [?][?][?]
	 * [?][X][6]
	 * [?][4][?]
	 */

	char input[MAX_FILE_LENGTH];
	struct Board board;
	struct Num_Coordinates numbers;


	file_to_string("test_puzzle_missing_one.txt", input);

	sput_fail_unless(
		initialise_state(input, &board, &numbers) == FALSE,
		"Invalid puzzle -> initialise_state() = FALSE"
	);
}

static void test_initialise_test_puzzle_duplicate_number()
{
	/* [1][4][?]
	 * [?][X][6]
	 * [?][4][?]
	 */

	char input[MAX_FILE_LENGTH];
	struct Board board;
	struct Num_Coordinates numbers;


	file_to_string("test_puzzle_duplicate_number.txt", input);

	sput_fail_unless(
		initialise_state(input, &board, &numbers) == FALSE,
		"Invalid puzzle -> initialise_state() = FALSE"
	);
}

static void test_initialise_test_ignore_irrelevant_chars_puzzle()
{
	/* fsdxsf1vc
	* sf?sfsd3s
	*
	* contains valid puzzle:
	* [X][1]
	* [?][3]
	*/

	char input[MAX_FILE_LENGTH];
	struct Board board;
	struct Num_Coordinates numbers;


	file_to_string("test_ignore_irrelevant_chars_puzzle.txt", input);

	sput_fail_unless(
		initialise_state(input, &board, &numbers) == TRUE,
		"Valid puzzle -> initialise_state() = TRUE"
	);

	sput_fail_unless(
		board.grid[0][0] == BLOCKED && board.grid[0][1] == FIXED &&
		board.grid[1][0] == FREE    && board.grid[1][1] == FIXED,
		"All nodes have the correct state"
	);

	sput_fail_unless(
		board.rows == 2 && board.cols == 2,
		"Rows = 2 and Columns = 2"
	);

	sput_fail_unless(
		numbers.coordinates[0].row == 0 && numbers.coordinates[0].col == 1 &&
		numbers.coordinates[1].row == UNKNOWN && numbers.coordinates[1].col == UNKNOWN &&
		numbers.coordinates[2].row == 1 && numbers.coordinates[2].col == 1,
		"All numbers have the correct coordinates"
	);

	sput_fail_unless(
		numbers.count == 3,
		"Numbers count = 3"
	);

	sput_fail_unless(
		numbers.next_fixed == numbers.coordinates &&
		numbers.next_fixed->row == 0 && numbers.next_fixed->col == 1,
		"First initially reavealed number = 1 at (0, 1)"
	);
}

static void test_initialise_test_empty_file()
{
	char input[MAX_FILE_LENGTH];
	struct Board board;
	struct Num_Coordinates numbers;


	file_to_string("test_empty_file.txt", input);

	sput_fail_unless(
		initialise_state(input, &board, &numbers) == FALSE,
		"Invalid puzzle -> initialise_state() = FALSE"
	);
}

static void test_initialise_test_puzzle_superflous_lines()
{
	/* [1][?][?]
	 * <empty line>
	 * [?][X][6]
	 * <garbage line>
	 * [?][4][?]
	 * <empty line>
	 */

	char input[MAX_FILE_LENGTH];
	struct Board board;
	struct Num_Coordinates numbers;


	file_to_string("test_puzzle_superflous_lines.txt", input);

	sput_fail_unless(
		initialise_state(input, &board, &numbers) == TRUE,
		"Valid puzzle -> initialise_state() = TRUE"
	);

	sput_fail_unless(
		board.grid[0][0] == FIXED && board.grid[0][1] == FREE    && board.grid[0][2] == FREE &&
		board.grid[1][0] == FREE  && board.grid[1][1] == BLOCKED && board.grid[1][2] == FIXED &&
		board.grid[2][0] == FREE  && board.grid[2][1] == FIXED   && board.grid[2][2] == FREE,
		"All nodes have the correct state"
	);

	sput_fail_unless(
		board.rows == 3 && board.cols == 3,
		"Rows = 3 and Columns = 3"
	);

	sput_fail_unless(
		numbers.coordinates[0].row == 0 && numbers.coordinates[0].col == 0 &&
		numbers.coordinates[1].row == UNKNOWN && numbers.coordinates[1].col == UNKNOWN &&
		numbers.coordinates[2].row == UNKNOWN && numbers.coordinates[2].col == UNKNOWN &&
		numbers.coordinates[3].row == 2 && numbers.coordinates[3].col == 1 &&
		numbers.coordinates[4].row == UNKNOWN && numbers.coordinates[4].col == UNKNOWN &&
		numbers.coordinates[5].row == 1 && numbers.coordinates[5].col == 2 &&
		numbers.coordinates[6].row == UNKNOWN && numbers.coordinates[6].col == UNKNOWN &&
		numbers.coordinates[7].row == UNKNOWN && numbers.coordinates[7].col == UNKNOWN,
		"All numbers have the correct coordinates"
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

static void test_initialise_test_puzzle_variable_cols()
{
	/* [1][?]
	 * [?][X][?]
	 * [?][5]
	*/

	char input[MAX_FILE_LENGTH];
	struct Board board;
	struct Num_Coordinates numbers;


	file_to_string("test_puzzle_variable_cols.txt", input);

	sput_fail_unless(
		initialise_state(input, &board, &numbers) == TRUE,
		"Valid puzzle -> initialise_state() = TRUE"
	);

	sput_fail_unless(
		board.grid[0][0] == FIXED && board.grid[0][1] == FREE    && board.grid[0][2] == BLOCKED &&
		board.grid[1][0] == FREE  && board.grid[1][1] == BLOCKED && board.grid[1][2] == FREE &&
		board.grid[2][0] == FREE  && board.grid[2][1] == FIXED   && board.grid[2][2] == BLOCKED,
		"All nodes have the correct state"
	);

	sput_fail_unless(
		board.rows == 3 && board.cols == 3,
		"Rows = 3 and Columns = 3"
	);

	sput_fail_unless(
		numbers.coordinates[0].row == 0 && numbers.coordinates[0].col == 0 &&
		numbers.coordinates[1].row == UNKNOWN && numbers.coordinates[1].col == UNKNOWN &&
		numbers.coordinates[2].row == UNKNOWN && numbers.coordinates[2].col == UNKNOWN &&
		numbers.coordinates[3].row == UNKNOWN && numbers.coordinates[3].col == UNKNOWN &&
		numbers.coordinates[4].row == 2 && numbers.coordinates[4].col == 1 &&
		numbers.coordinates[5].row == UNKNOWN && numbers.coordinates[5].col == UNKNOWN, 
		"All numbers have the correct coordinates"
	);

	sput_fail_unless(
		numbers.count == 6,
		"Numbers count = 6"
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

	sput_enter_suite("test_initialise_test_puzzle_2()");
	sput_run_test(test_initialise_test_puzzle_2);

	sput_enter_suite("test_initialise_test_puzzle_3()");
	sput_run_test(test_initialise_test_puzzle_3);

	sput_enter_suite("test_initialise_test_puzzle_missing_one()");
	sput_run_test(test_initialise_test_puzzle_missing_one);

	sput_enter_suite("test_initialise_test_puzzle_duplicate_number()");
	sput_run_test(test_initialise_test_puzzle_duplicate_number);

	sput_enter_suite("test_initialise_test_ignore_irrelevant_chars_puzzle()");
	sput_run_test(test_initialise_test_ignore_irrelevant_chars_puzzle);

	sput_enter_suite("test_initialise_test_empty_file()");
	sput_run_test(test_initialise_test_empty_file);

	sput_enter_suite("test_initialise_test_puzzle_superflous_lines()");
	sput_run_test(test_initialise_test_puzzle_superflous_lines);

	sput_enter_suite("test_initialise_test_puzzle_variable_cols()");
	sput_run_test(test_initialise_test_puzzle_variable_cols);

	sput_finish_testing();

	return sput_get_return_value();
}