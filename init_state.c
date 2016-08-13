#include "init_state.h"

void initialise_state(char *input, struct State *state)
{
	int row, col, number;
	char *p;
	BOOL processing[VALID_INPUTS];
	
	state->board_rows = state->board_cols = 0;
	row = col = number = 0;

	processing[NUMBER] = FALSE;
	processing[QUESTION_MARK] = FALSE;
	processing[X] = FALSE;

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