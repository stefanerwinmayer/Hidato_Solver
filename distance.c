#include "distance.h"

int distance(
	const struct Coordinate *first,
	const struct Coordinate *second)
{
	return (int)fmax(
		(double)abs(first->row - second->row),
		(double)abs(first->col - second->col));
}
