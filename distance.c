#include "distance.h"

int distance(
	const struct Coordinate *first,
	const struct Coordinate *second)
{
	return (int)fmax(abs(first->row - second->row), abs(first->col - second->col));
}
