#ifndef FILE_READER
#define FILE_READER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hidato_limits.h"

void file_to_string(
	const char *filename,
	char *string);

#endif