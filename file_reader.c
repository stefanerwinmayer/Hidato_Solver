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
	const long file_length,
	char *string)
{
	FILE *fp;
	char *buffer;

	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("Cannot open file %s\n", filename);
		(void)getchar();
		exit(EXIT_FAILURE);
	}

	buffer = malloc((file_length + 1) * sizeof(char));
	strcpy(buffer, "");
	strcpy(string, "");

	while (fgets(buffer, sizeof(string), fp) != NULL)
	{
		strcat(string, buffer);
	}

	free(buffer);
	fclose(fp);
}