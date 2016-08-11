#include "sput.h"
#include "../state_struct.h"
#include "../init_state.h"

int run_init_state_tests(void)
{
	sput_start_testing();

	sput_finish_testing();

	return sput_get_return_value();
}