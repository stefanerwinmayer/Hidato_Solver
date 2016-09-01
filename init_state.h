#ifndef INIT_STATE
#define INIT_STATE

#include <string.h>
#include <ctype.h>
#include "num_coordinates.h"
#include "coordinate_struct.h"
#include "board.h"
#include "boolean.h"

#define NUMBER 0
#define QUESTION_MARK 1
#define X 2
#define VALID_INPUTS 3
#define ONE 0

void initialise_state(
	char *input,
	struct Board *board,
	struct Num_Coordinates *numbers);

/*
void initialise_hillclimber(
	char *input,
	struct Num_Coordinates *numbers,
	struct Board *initial);
*/

#endif