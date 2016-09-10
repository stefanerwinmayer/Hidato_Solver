#include "sput.h"
#include "../hidato_limits.h"
#include "../file_reader.h"

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

	file_to_string("test_several_characters_one_line_file.txt", string);
	sput_fail_unless(
		strcmp(string, "xyz") == 0,
		"File with characters 'xyz' should should produce a string 'xyz'");

	file_to_string("test_several_characters_several_lines_file.txt", string);
	sput_fail_unless(
		strcmp(string, "abc\ndef\nghi") == 0,
		"File with characters 'abc\\ndef\\nghi' on two lines should should produce a string 'abc\\ndef\\nghi'");

	file_to_string("test_line_break_at_file_end_file.txt", string);
	sput_fail_unless(
		strcmp(string, "abc\n\n") == 0,
		"File with characters 'abc\n\n' should should produce a string 'abc\\n\\n'");
}

int run_file_reader_tests(void)
{
	sput_start_testing();

	sput_enter_suite("test_file_to_string()");
	sput_run_test(test_file_to_string);

	sput_finish_testing();

	return sput_get_return_value();
}