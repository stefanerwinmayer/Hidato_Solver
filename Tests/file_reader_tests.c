#include "sput.h"
#include "../file_reader.h"

int run_file_reader_tests(void)
{
	sput_start_testing();

	sput_finish_testing();

	return sput_get_return_value();
}