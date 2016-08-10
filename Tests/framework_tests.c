#include "sput.h"


static void test_fail_unless()
{
	/* This should fail */
	/* sput_fail_unless(1 == 0, "1 == 0"); */
	/* This should pass*/
	sput_fail_unless(1 == 1, "1 == 1");
}

static void test_fail_if()
{
	/* This should fail */
	/* sput_fail_if(1 == 1, "1 == 1"); */
	/* This should pass*/
	sput_fail_if(1 == 0, "1 == 0");
}

int run_framework_tests(void)
{
	sput_start_testing();

	sput_enter_suite("test_fail_unless()");
	sput_run_test(test_fail_unless);

	sput_enter_suite("test_fail_if()");
	sput_run_test(test_fail_if);

	sput_finish_testing();

	return sput_get_return_value();
}