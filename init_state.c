#include "init_state.h"

void initialise_state(
	char *input,
	struct State *state)
{
	int row, col, number;
	char *p;
	BOOL processing[VALID_INPUTS];

	state->board_rows = state->board_cols = state->ham_length = 0;

	processing[NUMBER] = FALSE;
	processing[QUESTION_MARK] = FALSE;
	processing[X] = FALSE;

	for (row = 0; row < MAX_ROWS; row++)
	{
		for (col = 0; col < MAX_COLS; col++)
		{
			state->board[row][col] = BLOCKED;
		}
	}

	for (number = 0; number < MAX_NUMS; number++)
	{
		state->hamiltonian[number].row = UNKNOWN;
		state->hamiltonian[number].col = UNKNOWN;
	}

	row = col = number = 0;

	(state->board_rows)++;
	for (p = input; p < input + strlen(input); p++)
	{
		if (isdigit(*p))
		{
			number = (number * 10) + (*p - '0');
			processing[NUMBER] = TRUE;
		}
		else if (*p == '?')
		{
			processing[QUESTION_MARK] = TRUE;
		}
		else if (toupper(*p) == 'X')
		{
			processing[X] = TRUE;
		}
		else
		{
			if (processing[NUMBER])
			{
				state->board[row][col] = 'F';
				(state->board_cols)++;

				state->hamiltonian[number - 1].row = row;
				state->hamiltonian[number - 1].col = col;
				state->ham_length++;

				if (number == 1)
				{
					state->hamiltonian[0].row = row;
					state->hamiltonian[0].col = col;
				}

				number = 0;

				if (*p != '\n')
				{
					col++;
				}

				processing[NUMBER] = FALSE;
			}
			else if (processing[QUESTION_MARK])
			{
				state->board[row][col] = '?';
				(state->board_cols)++;

				state->ham_length++;

				if (*p != '\n')
				{
					col++;
				}

				processing[QUESTION_MARK] = FALSE;

			}
			else if (processing[X])
			{
				state->board[row][col] = 'X';
				(state->board_cols)++;

				if (*p != '\n')
				{
					col++;
				}

				processing[X] = FALSE;
			}

			if (*p == '\n')
			{
				col = 0;
				(state->board_cols) = 0;
				(state->board_rows)++;
				row++;
			}
		}
	}
}

void initialise_hillclimber(
	char *input,
	struct Num_Coordinates *numbers,
	struct Board *board)
{
	int row, col, number;
	char *p;
	BOOL processing[VALID_INPUTS];

	board->rows = board->cols = board->number_count = numbers->count = 0;

	processing[NUMBER] = FALSE;
	processing[QUESTION_MARK] = FALSE;
	processing[X] = FALSE;

	for (row = 0; row < MAX_ROWS; row++)
	{
		for (col = 0; col < MAX_COLS; col++)
		{
			board->grid[row][col] = NOT_IN_USE;
		}
	}

	for (number = 0; number < MAX_NUMS; number++)
	{
		numbers->coordinates[number].row = UNKNOWN;
		numbers->coordinates[number].col = UNKNOWN;
	}


	row = col = number = 0;

	(board->rows)++;
	for (p = input; p < input + strlen(input); p++)
	{
		if (isdigit(*p))
		{
			number = (number * 10) + (*p - '0');
			processing[NUMBER] = TRUE;
		}
		else if (*p == '?')
		{
			processing[QUESTION_MARK] = TRUE;
		}
		else if (toupper(*p) == 'X')
		{
			processing[X] = TRUE;
		}
		else
		{
			if (processing[NUMBER])
			{
				board->grid[row][col] = number;
				(board->cols)++;

				numbers->coordinates[number - 1].row = row;
				numbers->coordinates[number - 1].col = col;
				(numbers->count)++;

				board->number_count++;

				number = 0;

				if (*p != '\n')
				{
					col++;
				}

				processing[NUMBER] = FALSE;
			}
			else if (processing[QUESTION_MARK])
			{
				board->grid[row][col] = UNKNOWN;
				(board->cols)++;

				(numbers->count)++;
				board->number_count++;

				if (*p != '\n')
				{
					col++;
				}

				processing[QUESTION_MARK] = FALSE;

			}
			else if (processing[X])
			{
				board->grid[row][col] = NOT_IN_USE;
				(board->cols)++;

				if (*p != '\n')
				{
					col++;
				}

				processing[X] = FALSE;
			}

			if (*p == '\n')
			{
				col = 0;
				(board->cols) = 0;
				(board->rows)++;
				row++;
			}
		}
	}
}