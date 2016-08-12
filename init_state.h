#ifndef STATE_BUILDER
#define STATE_BUILDER

#include <string.h>
#include <ctype.h>
#include "state_struct.h"
#include "coordinate_struct.h"
#include "boolean.h"

#define NUMBER 0
#define QUESTION_MARK 1
#define X 2
#define POSSIBILIES 3

void initialise_state(char *input, struct State *state);

#endif