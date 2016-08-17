#ifndef INIT_STATE
#define INIT_STATE

#include <string.h>
#include <ctype.h>
#include "state_struct.h"
#include "coordinate_struct.h"
#include "hillclimber_state_struct.h"
#include "boolean.h"

#define NUMBER 0
#define QUESTION_MARK 1
#define X 2
#define VALID_INPUTS 3

#define UNKOWN -1
#define BLOCKED 'X'

void initialise_state(
	char *input,
	struct State *state);

void initialise_hillclimber(
	char *input,
	struct HC_State *state);

#endif