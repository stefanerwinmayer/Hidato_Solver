#ifndef FILE_READER
#define FILE_READER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long file_length(const char *filename);

void file_to_string(
	const char *filename,
	const long file_length,
	char *string);

#endif