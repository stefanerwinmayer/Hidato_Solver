#ifndef INIT_STATE
#define INIT_STATE

#include <string.h>
#include <ctype.h>
#include "state_struct.h"
#include "coordinate_struct.h"
#include "board.h"
#include "boolean.h"

#define NUMBER 0
#define QUESTION_MARK 1
#define X 2
#define VALID_INPUTS 3

#define UNKNOWN -1
#define BLOCKED 'X'

#define NOT_IN_USE -2

void initialise_state(
	char *input,
	struct State *state);

void initialise_hillclimber(
	char *input,
	BOOL fixed[MAX_NUMS],
	struct Board *initial);

#endif