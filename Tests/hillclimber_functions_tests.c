#include "sput.h"
#include "../hillclimber.h"

static void test_produce_random_solution()
{
	struct Board board;
	struct Num_Coordinates numbers;

	board.grid[0][0] = FIXED; board.grid[0][1] = FREE;
	board.grid[1][0] = FREE; board.grid[1][1] = FIXED;
	board.grid[2][0] = BLOCKED; board.grid[2][1] = BLOCKED;
	board.rows = 3; board.cols = 2;

	numbers.coordinates[0].row = 0; numbers.coordinates[0].col = 0;
	numbers.coordinates[1].row = UNKNOWN; numbers.coordinates[1].col = UNKNOWN;
	numbers.coordinates[2].row = 1; numbers.coordinates[2].col = 1;
	numbers.coordinates[3].row = UNKNOWN; numbers.coordinates[3].col = UNKNOWN;
	numbers.count = 4;

	produce_random_solution(&board, &numbers);

	sput_fail_unless(
		board.grid[0][0] == FIXED && board.grid[0][1] == TAKEN &&
		board.grid[1][0] == TAKEN && board.grid[1][1] == FIXED &&
		board.grid[2][0] == BLOCKED && board.grid[2][1] == BLOCKED,
		"All FREE nodes should be TAKEN."
	);

	sput_fail_unless(
		numbers.coordinates[0].row == 0 && numbers.coordinates[0].col == 0 &&
		numbers.coordinates[2].row == 1 && numbers.coordinates[2].col == 1,
		"Fixed number coordinates should be left untouched."
	);

	sput_fail_unless(
		(numbers.coordinates[1].row == 0 && numbers.coordinates[1].col == 1 &&
			numbers.coordinates[3].row == 1 && numbers.coordinates[3].col == 0) ||

			(numbers.coordinates[1].row == 1 && numbers.coordinates[1].col == 0 &&
				numbers.coordinates[3].row ==  0 && numbers.coordinates[3].col == 1),
		"Remaining numbers have unique coordinates assigned."
	);
}

static void test_find_number_to_swap()
{
	struct Board board;
	struct Num_Coordinates solution;

	board.grid[0][0] = FIXED; board.grid[0][1] = TAKEN;
	board.grid[1][0] = TAKEN; board.grid[1][1] = FIXED;
	board.grid[2][0] = BLOCKED; board.grid[2][1] = BLOCKED;
	board.rows = 3; board.cols = 2;

	solution.coordinates[0].row = 0; solution.coordinates[0].col = 0;
	solution.coordinates[1].row = 0; solution.coordinates[1].col = 1;
	solution.coordinates[2].row = 1; solution.coordinates[2].col = 1;
	solution.coordinates[3].row = 1; solution.coordinates[3].col = 0;
	solution.count = 4;

	sput_fail_unless(
		find_number_to_swap(&board, &solution, 0) == 1,
		"Number 2 at index 1 should be found"
	);

	sput_fail_unless(
		find_number_to_swap(&board, &solution, 1) == 1,
		"Number 2 at index 1 should be found"
	);

	sput_fail_unless(
		find_number_to_swap(&board, &solution, 2) == 3,
		"Number 4 at index 3 should be found"
	);

	sput_fail_unless(
		find_number_to_swap(&board, &solution, 3) == 3,
		"Number 4 at index 3 should be found"
	);

	sput_fail_unless(
		find_number_to_swap(&board, &solution, 4) == 4,
		"No further number can be found"
	);
}

static void test_swap_numbers()
{
	struct Num_Coordinates solution;

	solution.coordinates[0].row = 0; solution.coordinates[0].col = 0;
	solution.coordinates[1].row = 0; solution.coordinates[1].col = 1;
	solution.coordinates[2].row = 1; solution.coordinates[2].col = 1;
	solution.coordinates[3].row = 1; solution.coordinates[3].col = 0;

	swap_numbers(&solution, 1, 3);

	sput_fail_unless(
		solution.coordinates[0].row == 0 && solution.coordinates[0].col == 0 &&
		solution.coordinates[1].row == 1 && solution.coordinates[1].col == 0 &&
		solution.coordinates[2].row == 1 && solution.coordinates[2].col == 1 &&
		solution.coordinates[3].row == 0 && solution.coordinates[3].col == 1,
		"Number coordinates are swapped correctly, rest is untouched."
	);
}

static void test_update_points()
{
	struct Num_Coordinates solution;
	int points[MAX_NUMS] = { 0 };

	solution.coordinates[0].row = 0; solution.coordinates[0].col = 0;
	solution.coordinates[1].row = UNKNOWN; solution.coordinates[1].col = UNKNOWN;
	solution.coordinates[2].row = 1; solution.coordinates[2].col = 1;
	solution.coordinates[3].row = UNKNOWN; solution.coordinates[3].col = UNKNOWN;

	update_points(&solution, points, 0, 4);

	sput_fail_unless(
		points[0] == 0 && points[1] == 0 && points[2] == 0 && points[3] == 0,
		"Initial puzzle has no points."
	);

	solution.coordinates[0].row = 0; solution.coordinates[0].col = 0;
	solution.coordinates[1].row = 0; solution.coordinates[1].col = 1;
	solution.coordinates[2].row = 1; solution.coordinates[2].col = 1;
	solution.coordinates[3].row = 1; solution.coordinates[3].col = 0;

	update_points(&solution, points, 0, 4);

	sput_fail_unless(
		points[0] == 1 && points[1] == 1 && points[2] == 1 && points[3] == 0,
		"Solved puzzle has all possible points."
	);
}

int run_hillclimber_functions_tests(void)
{
	sput_start_testing();

	sput_enter_suite("test_produce_random_solution()");
	sput_run_test(test_produce_random_solution);

	sput_enter_suite("test_find_number_to_swap()");
	sput_run_test(test_find_number_to_swap);

	sput_enter_suite("test_swap_numbers()");
	sput_run_test(test_swap_numbers);

	sput_enter_suite("test_udpate_points()");
	sput_run_test(test_update_points);

	sput_finish_testing();

	return sput_get_return_value();

}