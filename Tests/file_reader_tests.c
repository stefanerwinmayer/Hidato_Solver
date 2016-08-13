#include "sput.h"
#include "../hidato_limits.h"
#include "../file_reader.h"

static void test_file_length()
{
	sput_fail_unless(
		file_length("test_empty_file.txt") == 0,
		"File length of empty file should be 0");
	sput_fail_unless(
		file_length("test_one_character_file.txt") == 1,
		"File length of file with 1 character should be 1");
	sput_fail_unless(
		file_length("test_two_characters_one_line_file.txt") == 2,
		"File length of file with 2 characters on 1 line should be 2");
	sput_fail_unless(
		file_length("test_four_characters_two_lines_file.txt") == 6,
		"File length of file with 4 characters on 2 lines should be 6 including '\n'");
}

static void test_file_to_string()
{

	char string[MAX_FILE_LENGTH] = "I'm wrong!";

	file_to_string("test_empty_file.txt", string);
	sput_fail_unless(
		strcmp(string, "") == 0,
		"Empty file should produce an empty string");

	file_to_string("test_one_character_file.txt", string);
	sput_fail_unless(
		strcmp(string, "x") == 0,
		"File with character 'x' should should produce a string 'x'");

	file_to_string("test_two_characters_one_line_file.txt", string);
	sput_fail_unless(
		strcmp(string, "xx") == 0,
		"File with characters 'xx' should should produce a string 'xx'");

	file_to_string("test_four_characters_two_lines_file.txt", string);
	sput_fail_unless(
		strcmp(string, "xx\nxx") == 0,
		"File with characters 'xx' on two lines should should produce a string 'xx\\nxx'");
}

int run_file_reader_tests(void)
{
	sput_start_testing();

	sput_enter_suite("test_file_length()");
	sput_run_test(test_file_length);

	sput_enter_suite("test_file_to_string()");
	sput_run_test(test_file_to_string);

	sput_finish_testing();

	return sput_get_return_value();
}