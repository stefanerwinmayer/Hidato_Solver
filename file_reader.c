#include <stdio.h>
#include <stdlib.h>
#include "file_reader.h"

long file_length(const char *filename)
{
	FILE *fp;
	long pos;

	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("Cannot open file %s\n", filename);
		getchar();
		exit(EXIT_FAILURE);
	}

	fseek(fp, 0L, SEEK_END);
	pos = ftell(fp);

	fclose(fp);
	return pos;
}