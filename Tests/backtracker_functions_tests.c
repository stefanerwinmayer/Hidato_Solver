#include "sput.h"
#include "../backtracker.h"

static void test_update_board()
{
	struct Board board;
	struct Num_Coordinates numbers;

	board.grid[2][2] = FIXED;
	numbers.coordinates[0].row = 2; numbers.coordinates[0].col = 2;
	
	board.grid[3][3] = FREE;
	numbers.coordinates[1].row = 3; numbers.coordinates[1].col = 3;

	update_board(&board, numbers.coordinates);
	update_board(&board, numbers.coordinates + 1);

	sput_fail_unless(
		board.grid[2][2] == VISITED_FIXED &&
		board.grid[3][3] == TAKEN,
		"FIXED -> VISITED_FIXED, FREE -> TAKEN"
	);
}

static void test_revert_board()
{
	struct Board board;
	struct Num_Coordinates numbers;

	board.grid[0][0] = VISITED_FIXED;
	board.grid[0][1] = TAKEN;
	numbers.coordinates[0].row = 0; numbers.coordinates[0].col = 0;
	numbers.coordinates[1].row = 0; numbers.coordinates[1].col = 1;

	revert_board(&board, numbers.coordinates);
	revert_board(&board, numbers.coordinates + 1);

	sput_fail_unless(
		board.grid[0][0] == FIXED &&
		board.grid[0][1] == FREE,
		"VISITED_FIXED -> FIXED, TAKEN -> FREE"
	);
}

static void test_update_hamiltonian()
{
	struct Num_Coordinates numbers;
	struct Coordinate neighbour_guess = { 2, 2 };
	struct Coordinate neighbour_fixed = { 3, 3 };

	numbers.coordinates[1].row = UNKNOWN; numbers.coordinates[1].col = UNKNOWN;
	numbers.coordinates[2].row = 3; numbers.coordinates[2].col = 3;

	update_hamiltonian(numbers.coordinates + 1, &neighbour_guess);
	update_hamiltonian(numbers.coordinates + 2, &neighbour_fixed);

	sput_fail_unless(
		numbers.coordinates[1].row == 2 &&
		numbers.coordinates[1].col == 2 &&
		numbers.coordinates[2].row == 3 && 
		numbers.coordinates[2].col == 3,
		"UNKNOWN -> (2, 2), fixed (3, 3) should stay as is"
	);
}

static void test_revert_hamiltonian()
{
	struct Board board;
	struct Num_Coordinates numbers;

	board.grid[0][0] = FIXED;
	board.grid[0][1] = FREE;
	numbers.coordinates[0].row = 0; numbers.coordinates[0].col = 0;
	numbers.coordinates[1].row = 0; numbers.coordinates[1].col = 1;

	revert_hamiltonian(&board, numbers.coordinates);
	revert_hamiltonian(&board, numbers.coordinates + 1);

	sput_fail_unless(
		numbers.coordinates[0].row == 0 &&
		numbers.coordinates[0].col == 0 &&
		numbers.coordinates[1].row == UNKNOWN &&
		numbers.coordinates[1].col == UNKNOWN,
		"Fixed (0, 0) should stay as is, (0, 1) -> UNKNOWN"
	);
}

int run_backtracker_functions_tests(void)
{
	sput_start_testing();

	sput_enter_suite("test_update_board()");
	sput_run_test(test_update_board);

	sput_enter_suite("test_revert_board()");
	sput_run_test(test_revert_board);

	sput_enter_suite("test_update_hamiltonian()");
	sput_run_test(test_update_hamiltonian);

	sput_enter_suite("test_revert_hamiltonian()");
	sput_run_test(test_revert_hamiltonian);

	sput_finish_testing();

	return sput_get_return_value();

}