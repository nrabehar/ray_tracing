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

t_color	cl_norm(t_color c)
{
	t_range	cr;

	cr = range(0.0, 255.0);
	c = vec_scale(c, 255.0);
	c.x = clamp(cr, c.x);
	c.y = clamp(cr, c.y);
	c.z = clamp(cr, c.z);
	return (c);
}

t_color	cl_unit(t_color c)
{
	return (vec_div_scale(c, 255.0f));
}

int	cl_to_int(t_color c)
{
	int	r;
	int	g;
	int	b;

	c = cl_norm(c);
	r = (int)c.x;
	g = (int)c.y;
	b = (int)c.z;
	return (r << 16 | g << 8 | b);
}
