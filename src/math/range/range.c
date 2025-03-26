#include "minirt.h"

t_range	range(double min, double max)
{
	t_range	r;

	r.min = min;
	r.max = max;
	return (r);
}

double	clamp(t_range r, double value)
{
	if (value < r.min)
		return (r.min);
	if (value > r.max)
		return (r.max);
	return (value);
}

bool	in_range(t_range r, double value)
{
	return (value >= r.min && value <= r.max);
}