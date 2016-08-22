#include "file_reader.h"

void file_to_string(
	const char *filename,
	char *string)
{
	FILE *fp;
	char buffer[MAX_FILE_LENGTH / MAX_ROWS];

	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("Cannot open file %s\n", filename);
		(void)getchar();
		exit(EXIT_FAILURE);
	}

	strcpy(buffer, "");
	strcpy(string, "");

	while (fgets(buffer, MAX_FILE_LENGTH / MAX_ROWS, fp) != NULL)
	{
		strcat(string, buffer);
	}

	fclose(fp);
}