#include "sput.h"
#include "../file_reader.h"

static void test_file_length()
{
	sput_fail_unless(file_length("test_empty_file.txt") == 0, "File length of empty file should be 0");
}

int run_file_reader_tests(void)
{
	sput_start_testing();

	sput_enter_suite("test_file_length()");
	sput_run_test(test_file_length);

	sput_finish_testing();

	return sput_get_return_value();
}