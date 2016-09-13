#include "sput.h"
#include "../backtracker.h"

struct Coordinate current;

static void setup()
{
	current.row = 1;
	current.col = 1;
}


static void test_distance()
{
	struct Coordinate first = { 0, 0 };
	struct Coordinate second = { 2, 2 };
	struct Coordinate third = { 1, 2 };
	struct Coordinate fourth = { 1, 1 };
	struct Coordinate fifth = { 0, 0 };
	struct Coordinate sixth = { 0, 2 };

	sput_fail_unless(
		distance(&first, &second) == 2,
		"Distance between (0, 0) and (2, 2) should be 2.");

	sput_fail_unless(
		distance(&first, &third) == 2,
		"Distance between (0, 0) and (1, 2) should be 2.");

	sput_fail_unless(
		distance(&first, &fourth) == 1,
		"Distance between (0, 0) and (1, 1) should be 1.");

	sput_fail_unless(
		distance(&first, &fifth) == 0,
		"Distance between (0, 0) and (0, 0) should be 0.");

	sput_fail_unless(
		distance(&first, &sixth) == 2,
		"Distance between (0, 0) and (0, 2) should be 2.");
}

int run_backtracker_functions_tests(void)
{
	setup();

	sput_start_testing();

	sput_enter_suite("test_distance()");
	sput_run_test(test_distance);

	sput_finish_testing();

	return sput_get_return_value();

}