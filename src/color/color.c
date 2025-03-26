#include "minirt.h"

t_color	color(double r, double g, double b)
{
	return (vec3(r, g, b));
}
t_color	cl_mul(t_color c1, t_color c2)
{
	double	r;
	double	g;
	double	b;

	r = c1.x * c2.x;
	g = c1.y * c2.y;
	b = c1.z * c2.z;
	return (color(r, g, b));
}

t_color	cl_had(t_color c1, t_color c2)
{
	return (cl_mul(c1, c2));
}
