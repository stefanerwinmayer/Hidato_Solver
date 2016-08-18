#ifndef HILLCLIMBER
#define HILLCLIMBER

#include "hillclimber_state_struct.h"

#define UNKNOWN -1

void produce_random_solution(struct HC_State *state);
int assess_solution(struct HC_State *state);

#endif