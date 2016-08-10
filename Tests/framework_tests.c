#include "sput.h"


static void test_fail_unless()
{

}

static void test_fail_if()
{

}

int run_framework_tests(int argc, char *argv[])
{
	sput_start_testing();

	sput_enter_suite("test_fail_unless()");
	sput_run_test(test_fail_unless);

	sput_enter_suite("test_fail_if()");
	sput_run_test(test_fail_if);

	sput_finish_testing();

	return sput_get_return_value();
}