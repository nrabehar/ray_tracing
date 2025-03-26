#ifndef RANGE_H
# define RANGE_H

# include <stdbool.h>

typedef struct s_range
{
	double	min;
	double	max;
}			t_range;

t_range		range(double min, double max);
double		clamp(t_range r, double value);
bool		in_range(t_range r, double value);

#endif