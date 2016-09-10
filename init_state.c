#include "init_state.h"

BOOL initialise_state(
	char *input,
	struct Board *board,
	struct Num_Coordinates *numbers)
{
	int row, col, number;
	char *p;
	BOOL processing[VALID_INPUTS] = { FALSE };
	BOOL seen[MAX_NUMS] = { FALSE };
	BOOL row_has_data = FALSE;

	numbers->next_fixed = numbers->coordinates;

	numbers->count = 0;

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

	for (p = input; p < input + strlen(input); p++)
	{
		if (isdigit(*p))
		{
			number = (number * 10) + (*p - '0');
			processing[NUMBER] = TRUE;
			row_has_data = TRUE;
		}
		else if (*p == '?')
		{
			processing[QUESTION_MARK] = TRUE;
			row_has_data = TRUE;
		}
		else if (toupper(*p) == 'X')
		{
			processing[X] = TRUE;
			row_has_data = TRUE;
		}
		else
		{
			if (processing[NUMBER])
			{
				if (seen[number - 1])
				{
					printf("Invalid input: Number %d is present multiple times.", number);
					return FALSE;
				}

				seen[number - 1] = TRUE;

				board->grid[row][col] = FIXED;

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

				if (*p != '\n')
				{
					col++;
				}

				processing[X] = FALSE;
			}

			if (*p == '\n' && row_has_data)
			{
				if (col > board->cols)
				{
					board->cols = col;
				}
				col = 0;
				row++;
				row_has_data = FALSE;
			}
		}
	}

	if (col == 0)
	{
		board->rows = row;
	}
	else
	{
		board->rows = row + 1;
	}

	if (!seen[ONE])
	{
		printf("Invalid input: Number 1 must be present.");
		return FALSE;
	}

	return TRUE;
}