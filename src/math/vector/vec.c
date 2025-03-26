#include "minirt.h"

t_vec	vec3(double x, double y, double z)
{
	t_vec	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec	vec_zero(void)
{
	return (vec3(0, 0, 0));
}

t_vec	vec_cp(t_vec v)
{
	return (vec3(v.x, v.y, v.z));
}

t_vec	vec_norm(t_vec v)
{
	double	mag;

	mag = vec_mag(v);
	if (mag == 0.0)
		return (v);
	return (vec_div_scale(v, mag));
}

double	vec_sqmag(t_vec v)
{
	return ((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

double	vec_mag(t_vec v)
{
	return (sqrt(vec_sqmag(v)));
}

double	vec_dot(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
