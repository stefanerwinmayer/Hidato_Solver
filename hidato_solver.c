#include "hidato_solver.h"

int main(int argc, char *argv[])
{
	BOOL backtracking, smart, hillclimbing;
	char input[MAX_FILE_LENGTH];

	backtracking = smart = hillclimbing = FALSE;

	printf("Welcome to Hidato!\n\n");

	if (strcmp(argv[ALGORITHM], "-b") == 0)
	{
		backtracking = TRUE;
	}
	else if (strcmp(argv[ALGORITHM], "-sb") == 0)
	{
		backtracking = TRUE;
		smart = TRUE;
	}
	else if (strcmp(argv[ALGORITHM], "-h") == 0)
	{
		hillclimbing = TRUE;
	}
	else
	{
		printf("Invalid input. Please specify the algorithm: -b or -sb or -h");
		(void)getchar();
		exit(EXIT_FAILURE);
	}


	if (strcmp(argv[FILE_NAME], "") != 0)
	{
		file_to_string(argv[FILE_NAME], input);
	}

	if (backtracking)
	{
		run_backtracker(input, smart);
	}
	else if (hillclimbing)
	{
		run_hillclimber(input);
	}

	(void)getchar();
	return 0;
}