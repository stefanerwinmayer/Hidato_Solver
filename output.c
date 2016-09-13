#include "output.h"

void print_hamiltonian_path(struct Num_Coordinates *numbers)
{
	int i;

	printf("     (%2d, %2d)", numbers->coordinates[0].row, numbers->coordinates[0].col);
	for (i = 1; i < numbers->count; i++)
	{
		printf(" -> (%2d, %2d)", numbers->coordinates[i].row, numbers->coordinates[i].col);
		if ((i + 1) % 9 == 0)
		{
			printf("\n ");
		}
	}
	printf("\n\n");
}

void print_board(
	const struct Board *board,
	const struct Num_Coordinates *numbers)
{
	int i, j;
	char output[MAX_ROWS][MAX_COLS];

	for (i = 0; i < numbers->count; i++)
	{
		if (numbers->coordinates[i].row >= 0 && numbers->coordinates[i].col >= 0)
		{
			output[numbers->coordinates[i].row][numbers->coordinates[i].col] = (char)(i + 1);
		}
	}

	for (i = 0; i < board->rows; i++)
	{
		for (j = 0; j < board->cols; j++)
		{
			if (board->grid[i][j] == FREE)
			{
				output[i][j] = FREE;
			}
			else if (board->grid[i][j] == BLOCKED)
			{
				output[i][j] = BLOCKED;
			}
		}
	}

	printf("     ");
	for (i = 0; i < board->cols; i++)
	{
		printf("  %2d ", i);
	}
	printf("\n");

	for (i = 0; i < board->rows; i++)
	{
		printf("%4d ", i);
		for (j = 0; j < board->cols; j++)
		{
			if (output[i][j] != BLOCKED && output[i][j] != FREE)
			{
				printf("[%3d]", output[i][j]);
			}
			else if (output[i][j] == BLOCKED)
			{
				printf("     ");
			}
			else
			{
				printf("[   ]");
			}
		}
		printf("\n");
	}
	printf("\n");
}

/*
void print_solution(struct Board *board)
{
	int row, col;

	printf(" ");
	for (col = 0; col < board->cols; col++)
	{
		printf("   %d", col);
	}
	printf("\n");

	for (row = 0; row < board->rows; row++)
	{
		printf("%d ", row);
		for (col = 0; col < board->cols; col++)
		{
			if (board->grid[row][col] != BLOCKED && board->grid[row][col] != UNKNOWN)
			{
				printf("[%2.d]", board->grid[row][col]);
			}
			else if (board->grid[row][col] == BLOCKED)
			{
				printf("[XX]");
			}
			else
			{
				printf("[  ]");
			}
		}
		printf("\n");
	}
	printf("\n");
}
*/
