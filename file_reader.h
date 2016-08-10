#ifndef FILE_READER
#define FILE_READER

long file_length(const char *filename);

void file_to_string(
	const char *filename,
	const int file_length,
	char *string);

#endif