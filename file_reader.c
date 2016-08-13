#include "file_reader.h"

long file_length(const char *filename)
{
	FILE *fp;
	long pos;

	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("Cannot open file %s\n", filename);
		(void)getchar();
		exit(EXIT_FAILURE);
	}

	fseek(fp, 0L, SEEK_END);
	pos = ftell(fp);

	fclose(fp);
	return pos;
}

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