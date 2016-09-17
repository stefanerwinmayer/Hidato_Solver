#include "sput.h"
#include "../file_reader.h"
#include "../init_state.h"
#include "../backtracker.h"

static void test_backtrack_test_puzzle_1()
{
	char input[MAX_FILE_LENGTH];
	struct Board board;
	struct Num_Coordinates numbers;
	int iterations = 0;

	file_to_string("test_puzzle_1.txt", input);
	initialise_state(input, &board, &numbers);

	sput_fail_unless(
		backtrack(&board, &numbers, numbers.coordinates, &iterations, FALSE) == TRUE,
		"Valid puzzle -> should return TRUE"
	);

	sput_fail_unless(
		board.grid[0][0] == VISITED_FIXED && board.grid[0][1] == TAKEN && board.grid[0][2] == TAKEN &&
		board.grid[1][0] == TAKEN && board.grid[1][1] == BLOCKED && board.grid[1][2] == VISITED_FIXED &&
		board.grid[2][0] == TAKEN && board.grid[2][1] == VISITED_FIXED && board.grid[2][2] == TAKEN,
		"All nodes have the correct state after backtracking"
	);

	sput_fail_unless(
		numbers.coordinates[0].row == 0 && numbers.coordinates[0].col == 0 &&
		numbers.coordinates[1].row == 1 && numbers.coordinates[1].col == 0 &&
		numbers.coordinates[2].row == 2 && numbers.coordinates[2].col == 0 &&
		numbers.coordinates[3].row == 2 && numbers.coordinates[3].col == 1 &&
		numbers.coordinates[4].row == 2 && numbers.coordinates[4].col == 2 &&
		numbers.coordinates[5].row == 1 && numbers.coordinates[5].col == 2 &&
		numbers.coordinates[6].row == 0 && numbers.coordinates[6].col == 1 &&
		numbers.coordinates[7].row == 0 && numbers.coordinates[7].col == 2,
		"All numbers have the correct coordinates"
	);
}

static void test_backtrack_test_puzzle_2()
{
	char input[MAX_FILE_LENGTH];
	struct Board board;
	struct Num_Coordinates numbers;
	int iterations = 0;

	file_to_string("test_puzzle_2.txt", input);
	initialise_state(input, &board, &numbers);

	sput_fail_unless(
		backtrack(&board, &numbers, numbers.coordinates, &iterations, FALSE) == TRUE,
		"Valid puzzle -> should return TRUE"
	);

	sput_fail_unless(
		board.grid[0][0] == VISITED_FIXED && board.grid[0][1] == VISITED_FIXED && board.grid[0][2] == BLOCKED &&
		board.grid[1][0] == TAKEN && board.grid[1][1] == TAKEN && board.grid[1][2] == BLOCKED &&
		board.grid[2][0] == VISITED_FIXED && board.grid[2][1] == TAKEN && board.grid[2][2] == VISITED_FIXED,
		"All nodes have the correct state after backtracking"
	);

	sput_fail_unless(
		numbers.coordinates[0].row == 2 && numbers.coordinates[0].col == 2 &&
		numbers.coordinates[1].row == 1 && numbers.coordinates[1].col == 1 &&
		numbers.coordinates[2].row == 2 && numbers.coordinates[2].col == 1 &&
		numbers.coordinates[3].row == 2 && numbers.coordinates[3].col == 0 &&
		numbers.coordinates[4].row == 1 && numbers.coordinates[4].col == 0 &&
		numbers.coordinates[5].row == 0 && numbers.coordinates[5].col == 1 &&
		numbers.coordinates[6].row == 0 && numbers.coordinates[6].col == 0,
		"All numbers have the correct coordinates"
	);
}

static void test_backtrack_test_puzzle_3()
{
	char input[MAX_FILE_LENGTH];
	struct Board board;
	struct Num_Coordinates numbers;
	int iterations = 0;

	file_to_string("test_puzzle_3.txt", input);
	initialise_state(input, &board, &numbers);

	sput_fail_unless(
		backtrack(&board, &numbers, numbers.coordinates, &iterations, FALSE) == TRUE,
		"Valid puzzle -> should return TRUE"
	);

	sput_fail_unless(
		board.grid[0][0] == BLOCKED && board.grid[0][1] == VISITED_FIXED &&
		board.grid[0][2] == TAKEN && board.grid[0][3] == BLOCKED &&
		board.grid[1][0] == TAKEN && board.grid[1][1] == VISITED_FIXED &&
		board.grid[1][2] == TAKEN && board.grid[1][3] == BLOCKED &&
		board.grid[2][0] == VISITED_FIXED && board.grid[2][1] == TAKEN &&
		board.grid[2][2] == TAKEN && board.grid[2][3] == BLOCKED &&
		board.grid[3][0] == BLOCKED && board.grid[3][1] == BLOCKED &&
		board.grid[3][2] == BLOCKED && board.grid[3][3] == BLOCKED,
		"All nodes have the correct state after backtracking"
	);

	sput_fail_unless(
		numbers.coordinates[0].row == 1 && numbers.coordinates[0].col == 1 &&
		numbers.coordinates[1].row == 2 && numbers.coordinates[1].col == 0 &&
		numbers.coordinates[2].row == 1 && numbers.coordinates[2].col == 0 &&
		numbers.coordinates[3].row == 0 && numbers.coordinates[3].col == 1 &&
		numbers.coordinates[4].row == 0 && numbers.coordinates[4].col == 2 &&
		numbers.coordinates[5].row == 1 && numbers.coordinates[5].col == 2 &&
		numbers.coordinates[6].row == 2 && numbers.coordinates[6].col == 1 &&
		numbers.coordinates[7].row == 2 && numbers.coordinates[7].col == 2,
		"All numbers have the correct coordinates"
	);
}

static void test_smart_backtrack_test_puzzle_1()
{
	char input[MAX_FILE_LENGTH];
	struct Board board;
	struct Num_Coordinates numbers;
	int iterations = 0;

	file_to_string("test_puzzle_1.txt", input);
	initialise_state(input, &board, &numbers);

	sput_fail_unless(
		backtrack(&board, &numbers, numbers.coordinates, &iterations, TRUE) == TRUE,
		"Valid puzzle -> should return TRUE"
	);

	sput_fail_unless(
		board.grid[0][0] == VISITED_FIXED && board.grid[0][1] == TAKEN && board.grid[0][2] == TAKEN &&
		board.grid[1][0] == TAKEN && board.grid[1][1] == BLOCKED && board.grid[1][2] == VISITED_FIXED &&
		board.grid[2][0] == TAKEN && board.grid[2][1] == VISITED_FIXED && board.grid[2][2] == TAKEN,
		"All nodes have the correct state after backtracking"
	);

	sput_fail_unless(
		numbers.coordinates[0].row == 0 && numbers.coordinates[0].col == 0 &&
		numbers.coordinates[1].row == 1 && numbers.coordinates[1].col == 0 &&
		numbers.coordinates[2].row == 2 && numbers.coordinates[2].col == 0 &&
		numbers.coordinates[3].row == 2 && numbers.coordinates[3].col == 1 &&
		numbers.coordinates[4].row == 2 && numbers.coordinates[4].col == 2 &&
		numbers.coordinates[5].row == 1 && numbers.coordinates[5].col == 2 &&
		numbers.coordinates[6].row == 0 && numbers.coordinates[6].col == 1 &&
		numbers.coordinates[7].row == 0 && numbers.coordinates[7].col == 2,
		"All numbers have the correct coordinates"
	);
}

static void test_smart_backtrack_test_puzzle_2()
{
	char input[MAX_FILE_LENGTH];
	struct Board board;
	struct Num_Coordinates numbers;
	int iterations = 0;

	file_to_string("test_puzzle_2.txt", input);
	initialise_state(input, &board, &numbers);

	sput_fail_unless(
		backtrack(&board, &numbers, numbers.coordinates, &iterations, TRUE) == TRUE,
		"Valid puzzle -> should return TRUE"
	);

	sput_fail_unless(
		board.grid[0][0] == VISITED_FIXED && board.grid[0][1] == VISITED_FIXED && board.grid[0][2] == BLOCKED &&
		board.grid[1][0] == TAKEN && board.grid[1][1] == TAKEN && board.grid[1][2] == BLOCKED &&
		board.grid[2][0] == VISITED_FIXED && board.grid[2][1] == TAKEN && board.grid[2][2] == VISITED_FIXED,
		"All nodes have the correct state after backtracking"
	);

	sput_fail_unless(
		numbers.coordinates[0].row == 2 && numbers.coordinates[0].col == 2 &&
		numbers.coordinates[1].row == 1 && numbers.coordinates[1].col == 1 &&
		numbers.coordinates[2].row == 2 && numbers.coordinates[2].col == 1 &&
		numbers.coordinates[3].row == 2 && numbers.coordinates[3].col == 0 &&
		numbers.coordinates[4].row == 1 && numbers.coordinates[4].col == 0 &&
		numbers.coordinates[5].row == 0 && numbers.coordinates[5].col == 1 &&
		numbers.coordinates[6].row == 0 && numbers.coordinates[6].col == 0,
		"All numbers have the correct coordinates"
	);
}

static void test_smart_backtrack_test_puzzle_3()
{
	char input[MAX_FILE_LENGTH];
	struct Board board;
	struct Num_Coordinates numbers;
	int iterations = 0;

	file_to_string("test_puzzle_3.txt", input);
	initialise_state(input, &board, &numbers);

	sput_fail_unless(
		backtrack(&board, &numbers, numbers.coordinates, &iterations, TRUE) == TRUE,
		"Valid puzzle -> should return TRUE"
	);

	sput_fail_unless(
		board.grid[0][0] == BLOCKED && board.grid[0][1] == VISITED_FIXED &&
		board.grid[0][2] == TAKEN && board.grid[0][3] == BLOCKED &&
		board.grid[1][0] == TAKEN && board.grid[1][1] == VISITED_FIXED &&
		board.grid[1][2] == TAKEN && board.grid[1][3] == BLOCKED &&
		board.grid[2][0] == VISITED_FIXED && board.grid[2][1] == TAKEN &&
		board.grid[2][2] == TAKEN && board.grid[2][3] == BLOCKED &&
		board.grid[3][0] == BLOCKED && board.grid[3][1] == BLOCKED &&
		board.grid[3][2] == BLOCKED && board.grid[3][3] == BLOCKED,
		"All nodes have the correct state after backtracking"
	);

	sput_fail_unless(
		numbers.coordinates[0].row == 1 && numbers.coordinates[0].col == 1 &&
		numbers.coordinates[1].row == 2 && numbers.coordinates[1].col == 0 &&
		numbers.coordinates[2].row == 1 && numbers.coordinates[2].col == 0 &&
		numbers.coordinates[3].row == 0 && numbers.coordinates[3].col == 1 &&
		numbers.coordinates[4].row == 0 && numbers.coordinates[4].col == 2 &&
		numbers.coordinates[5].row == 1 && numbers.coordinates[5].col == 2 &&
		numbers.coordinates[6].row == 2 && numbers.coordinates[6].col == 1 &&
		numbers.coordinates[7].row == 2 && numbers.coordinates[7].col == 2,
		"All numbers have the correct coordinates"
	);
}

static void test_backtrack_invalid_puzzle_1()
{
	char input[MAX_FILE_LENGTH];
	struct Board board;
	struct Num_Coordinates numbers;
	int iterations = 0;

	file_to_string("test_invalid_puzzle_1.txt", input);
	initialise_state(input, &board, &numbers);

	sput_fail_unless(
		backtrack(&board, &numbers, numbers.coordinates, &iterations, FALSE) == FALSE,
		"Number 2 at (2, 2) is not a neighbour of number 1 at (0,0)"
	);
}

static void test_backtrack_invalid_puzzle_2()
{
	char input[MAX_FILE_LENGTH];
	struct Board board;
	struct Num_Coordinates numbers;
	int iterations = 0;

	file_to_string("test_invalid_puzzle_2.txt", input);
	initialise_state(input, &board, &numbers);

	sput_fail_unless(
		backtrack(&board, &numbers, numbers.coordinates, &iterations, FALSE) == FALSE,
		"Puzzle contains 8 numbers but has Number 9 in it"
	);
}

int run_backtracker_algorithm_tests(void)
{
	sput_start_testing();

	sput_enter_suite("test_backtrack_test_puzzle_1");
	sput_run_test(test_backtrack_test_puzzle_1);

	sput_enter_suite("test_backtrack_test_puzzle_2");
	sput_run_test(test_backtrack_test_puzzle_2);

	sput_enter_suite("test_backtrack_test_puzzle_3");
	sput_run_test(test_backtrack_test_puzzle_3);

	sput_enter_suite("test_smart_backtrack_test_puzzle_1");
	sput_run_test(test_smart_backtrack_test_puzzle_1);

	sput_enter_suite("test_smart_backtrack_test_puzzle_2");
	sput_run_test(test_smart_backtrack_test_puzzle_2);

	sput_enter_suite("test_smart_backtrack_test_puzzle_3");
	sput_run_test(test_smart_backtrack_test_puzzle_3);

	sput_enter_suite("test_backtrack_invalid_puzzle_1");
	sput_run_test(test_backtrack_invalid_puzzle_1);

	sput_enter_suite("test_backtrack_invalid_puzzle_2");
	sput_run_test(test_backtrack_invalid_puzzle_2);

	sput_finish_testing();

	return sput_get_return_value();
}