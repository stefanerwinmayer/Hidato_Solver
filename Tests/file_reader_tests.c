#include "sput.h"
#include "../file_reader.h"

static void test_file_length()
{
	sput_fail_unless(file_length("test_empty_file.txt") == 0, "File length of empty file should be 0");
	sput_fail_unless(file_length("test_one_character_file.txt") == 1, "File length of file with 1 character should be 1");
	sput_fail_unless(file_length("test_two_characters_one_line_file.txt") == 2, "File length of file with 2 characters on 1 line should be 2");
}

int run_file_reader_tests(void)
{
	sput_start_testing();

	sput_enter_suite("test_file_length()");
	sput_run_test(test_file_length);

	sput_finish_testing();

	return sput_get_return_value();
}