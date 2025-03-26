#include "minirt.h"

bool	is_equal(double a, double b)
{
	return (fabs(a - b) < EPSILON);
}