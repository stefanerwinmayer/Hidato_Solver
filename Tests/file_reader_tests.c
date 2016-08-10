#include "sput.h"
#include "../file_reader.h"

static void test_fail_unless()
{
	sput_fail_unless(file_length("test_empty_file.txt") == 0, "File length of empty file is 0");
}

int run_file_reader_tests(void)
{
	sput_start_testing();

	sput_enter_suite("test_fail_unless()");
	sput_run_test(test_fail_unless);

	sput_finish_testing();

	return sput_get_return_value();
}