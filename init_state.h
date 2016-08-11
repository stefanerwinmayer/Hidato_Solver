#ifndef STATE_BUILDER
#define STATE_BUILDER

#include <string.h>
#include <ctype.h>
#include "state_struct.h"
#include "coordinate_struct.h"

#define PROCESSED 0

void initialise_state(char *input, struct State *state);

#endif