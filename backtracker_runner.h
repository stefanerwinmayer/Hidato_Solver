#ifndef BACKTRACKER_RUNNER
#define BACKTRACKER_RUNNER

#include <stdio.h>
#include "boolean.h"
#include "board.h"
#include "num_coordinates.h"
#include "init_state.h"
#include "backtracker.h"
#include "output.h"

void run_backtracker(
	struct Board *board,
	struct Num_Coordinates *numbers,
	BOOL smart);

#endif