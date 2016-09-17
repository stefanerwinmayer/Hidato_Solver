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

	board.grid[2][2] = VISITED_FIXED;
	board.grid[3][3] = TAKEN;
	numbers.coordinates[0].row = 2; numbers.coordinates[0].col = 2;
	numbers.coordinates[1].row = 3; numbers.coordinates[1].col = 3;

	revert_board(&board, numbers.coordinates);
	revert_board(&board, numbers.coordinates + 1);

	sput_fail_unless(
		board.grid[2][2] == FIXED &&
		board.grid[3][3] == FREE,
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

	board.grid[2][2] = FIXED;
	numbers.coordinates[0].row = 2; numbers.coordinates[0].col = 2;

	board.grid[3][3] = FREE;
	numbers.coordinates[1].row = 3; numbers.coordinates[1].col = 3;

	revert_hamiltonian(&board, numbers.coordinates);
	revert_hamiltonian(&board, numbers.coordinates + 1);

	sput_fail_unless(
		numbers.coordinates[0].row == 2 &&
		numbers.coordinates[0].col == 2 &&
		numbers.coordinates[1].row == UNKNOWN &&
		numbers.coordinates[1].col == UNKNOWN,
		"Fixed (2, 2) should stay as is, (3, 3) -> UNKNOWN"
	);
}

static void test_valid_move()
{
	struct Board board;
	struct Num_Coordinates numbers;
	struct Coordinate neighbour_ofb_1 = { -1, -1 };
	struct Coordinate neighbour_ofb_2 = { 2, 2 };
	struct Coordinate neighbour_visited_fixed = { 0, 0 };
	struct Coordinate neighbour_taken = { 0, 1 };
	struct Coordinate neighbour_free = { 1, 0 };
	struct Coordinate neighbour_blocked = { 2, 1 };
	struct Coordinate neighbour_fixed = { 2, 0 };
	struct Coordinate *next;

	board.rows = 3; board.cols = 2;
	board.grid[0][0] = VISITED_FIXED; board.grid[0][1] = TAKEN;
	board.grid[1][0] = FREE; board.grid[1][1] = TAKEN;
	board.grid[2][0] = FIXED; board.grid[2][1] = BLOCKED;

	numbers.coordinates[0].row = 0; numbers.coordinates[0].col = 0;
	numbers.coordinates[1].row = 0; numbers.coordinates[1].col = 1;
	numbers.coordinates[2].row = 1; numbers.coordinates[2].col = 1;
	numbers.coordinates[3].row = UNKNOWN; numbers.coordinates[3].col = UNKNOWN;
	numbers.coordinates[4].row = 2; numbers.coordinates[4].col = 0;

	next = &numbers.coordinates[3];

	sput_fail_unless(
		valid_move(&board, next, &neighbour_ofb_1) == FALSE &&
		valid_move(&board, next, &neighbour_ofb_2) == FALSE,
		"(-1, -1) and (2, 2) are out of bounds -> invalid move"
	);

	sput_fail_unless(
		valid_move(&board, next, &neighbour_visited_fixed) == FALSE &&
		valid_move(&board, next, &neighbour_taken) == FALSE &&
		valid_move(&board, next, &neighbour_fixed) == FALSE &&
		valid_move(&board, next, &neighbour_blocked) == FALSE,
		"VISITED_FIXED, TAKEN, FIXED, BLOCKED nodes are not valid moves for guesses"
	);

	sput_fail_unless(
		valid_move(&board, next, &neighbour_free) == TRUE,
		"A FREE node is a valid move for a guess"
	);

	next = &numbers.coordinates[4];

	sput_fail_unless(
		valid_move(&board, next, &neighbour_blocked) == FALSE,
		"(2, 1) not the node of the next fixed number -> invalid move"
	);

	sput_fail_unless(
		valid_move(&board, next, &neighbour_fixed) == TRUE,
		"(2, 0) is the node of the next fixed number -> valid move"
	);
}

static void test_update_next_fixed()
{
	struct Num_Coordinates numbers;

	numbers.coordinates[0].row = 2; numbers.coordinates[1].col = 2;
	numbers.coordinates[1].row = UNKNOWN; numbers.coordinates[1].col = UNKNOWN;
	numbers.coordinates[2].row = 3; numbers.coordinates[2].col = 3;

	numbers.next_fixed = numbers.coordinates;
	update_next_fixed(&numbers, numbers.coordinates);

	sput_fail_unless(
		numbers.next_fixed == numbers.coordinates + 2 &&
		numbers.next_fixed->row == 3 && numbers.next_fixed->col == 3,
		"Next fixed should be number 3 at (3, 3)"
	);

	update_next_fixed(&numbers, numbers.coordinates + 1);

	sput_fail_unless(
		numbers.next_fixed == numbers.coordinates + 2 &&
		numbers.next_fixed->row == 3 && numbers.next_fixed->col == 3,
		"Next fixed should be number 3 at (3, 3)"
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

	sput_enter_suite("test_valid_move()");
	sput_run_test(test_valid_move);

	sput_enter_suite("test_update_next_fixed()");
	sput_run_test(test_update_next_fixed);

	sput_finish_testing();

	return sput_get_return_value();

}