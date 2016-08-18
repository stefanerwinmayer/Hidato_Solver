#include "hillclimber_runner.h"

void run_hillclimber(char *input)
{
	struct HC_State state;

	initialise_hillclimber(input, &state);

	printf("Input Hidato:\n\n");
	print_solution(state.original_solution, state.board_rows, state.board_cols);

	printf("Solving the puzzle with the hill climber algorithm:\n\n");

	produce_random_solution(&state);

	printf("Random solution:\n\n");
	print_solution(state.original_solution, state.board_rows, state.board_cols);

	printf("Score: %d\n\n", assess_solution(state.original_solution, state.board_rows, state.board_cols));

	copy_board(&state);

	printf("Best solution:\n\n");
	print_solution(state.best_solution, state.board_rows, state.board_cols);
	printf("Score: %d\n\n", assess_solution(state.best_solution, state.board_rows, state.board_cols));
	

}