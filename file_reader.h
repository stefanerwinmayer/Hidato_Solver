#ifndef FILE_READER
#define FILE_READER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hidato_limits.h"

long file_length(const char *filename);

void file_to_string(
	const char *filename,
	char *string);

#endif