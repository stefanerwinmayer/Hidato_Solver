#include "init_state.h"

void initialise_state(
	char *input,
	struct Board *board,
	struct Num_Coordinates *numbers)
{
	int row, col, number;
	char *p;
	BOOL processing[VALID_INPUTS];

	board->rows = board->cols = numbers->count = 0;

	processing[NUMBER] = FALSE;
	processing[QUESTION_MARK] = FALSE;
	processing[X] = FALSE;

	for (row = 0; row < MAX_ROWS; row++)
	{
		for (col = 0; col < MAX_COLS; col++)
		{
			board->grid[row][col] = BLOCKED;
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
				board->grid[row][col] = FIXED;
				(board->cols)++;

				numbers->coordinates[number - 1].row = row;
				numbers->coordinates[number - 1].col = col;
				(numbers->count)++;

				number = 0;

				if (*p != '\n')
				{
					col++;
				}

				processing[NUMBER] = FALSE;
			}
			else if (processing[QUESTION_MARK])
			{
				board->grid[row][col] = FREE;
				(board->cols)++;

				(numbers->count)++;

				if (*p != '\n')
				{
					col++;
				}

				processing[QUESTION_MARK] = FALSE;

			}
			else if (processing[X])
			{
				board->grid[row][col] = BLOCKED;
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

/*
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
			board->grid[row][col] = BLOCKED;
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
				board->grid[row][col] = BLOCKED;
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
*/