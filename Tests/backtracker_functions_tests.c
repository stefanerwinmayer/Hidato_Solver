#include "sput.h"
#include "../backtracker.h"

static void test_update_board()
{
	struct Board board;
	struct Num_Coordinates numbers;

	board.grid[0][0] = FIXED;
	board.grid[0][1] = FREE;
	numbers.coordinates[0].row = 0; numbers.coordinates[0].col = 0;
	numbers.coordinates[1].row = 0; numbers.coordinates[1].col = 1;

	update_board(&board, numbers.coordinates);
	update_board(&board, numbers.coordinates + 1);

	sput_fail_unless(
		board.grid[0][0] == VISITED_FIXED &&
		board.grid[0][1] == TAKEN,
		"FIXED -> VISITED_FIXED, FREE -> TAKEN"
	);
}

int run_backtracker_functions_tests(void)
{
	sput_start_testing();

	sput_enter_suite("test_update_board()");
	sput_run_test(test_update_board);

	sput_finish_testing();

	return sput_get_return_value();

}