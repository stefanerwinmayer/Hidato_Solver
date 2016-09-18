#include "sput.h"
#include "../hillclimber.h"

static void test_produce_random_solution()
{
	struct Board board;
	struct Num_Coordinates numbers;
	int seen[4] = { FALSE };

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
				numbers.coordinates[3].row == 0 && numbers.coordinates[3].col == 1),
		"Remaining numbers have unique coordinates assigned."
	);
}

int run_hillclimber_functions_tests(void)
{
	sput_start_testing();

	sput_enter_suite("test_produce_random_solution()");
	sput_run_test(test_produce_random_solution);

	sput_finish_testing();

	return sput_get_return_value();

}