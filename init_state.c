#include "init_state.h"

BOOL initialise_state(
	char *input,
	struct Board *board,
	struct Num_Coordinates *numbers)
{
	int row, col, number;
	char *p;
	BOOL processing[NUM_VALID_INPUTS] = { FALSE };
	BOOL seen[MAX_NUMS] = { FALSE };

	numbers->next_fixed = numbers->coordinates;

	board->rows = board->cols = numbers->count = 0;

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
				if (seen[number - 1])
				{
					printf("Invalid input: Number %d is present multiple times.", number);
					return FALSE;
				}

				seen[number - 1] = TRUE;

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

	if (!seen[ONE])
	{
		printf("Invalid input: Number 1 must be present.");
		return FALSE;
	}

	return TRUE;
}