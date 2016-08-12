#ifndef STATE_BUILDER
#define STATE_BUILDER

#include <string.h>
#include <ctype.h>
#include "state_struct.h"
#include "coordinate_struct.h"

#define NUMBER 0
#define QUESTION_MARK 1
#define X 2

#define TRUE 1
#define FALSE 0

#define POSSIBILIES 3

typedef int BOOL;

void initialise_state(char *input, struct State *state);

#endif