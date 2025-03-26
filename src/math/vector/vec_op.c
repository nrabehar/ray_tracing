#include "minirt.h"

t_vec	vec_add(t_vec v1, t_vec v2)
{
	double	x;
	double	y;
	double	z;

	x = v1.x + v2.x;
	y = v1.y + v2.y;
	z = v1.z + v2.z;
	return (vec3(x, y, z));
}

t_vec	vec_sub(t_vec v1, t_vec v2)
{
	double	x;
	double	y;
	double	z;

	x = v1.x - v2.x;
	y = v1.y - v2.y;
	z = v1.z - v2.z;
	return (vec3(x, y, z));
}

t_vec	vec_neg(t_vec v)
{
	double	x;
	double	y;
	double	z;

	x = v.x * -1;
	y = v.y * -1;
	z = v.z * -1;
	return (vec3(x, y, z));
}

t_vec	vec_scale(t_vec v, double t)
{
	double	x;
	double	y;
	double	z;

	x = v.x * t;
	y = v.y * t;
	z = v.z * t;
	return (vec3(x, y, z));
}

t_vec	vec_div_scale(t_vec v, double t)
{
	double	x;
	double	y;
	double	z;

	x = v.x / t;
	y = v.y / t;
	z = v.z / t;
	return (vec3(x, y, z));
}

t_vec	vec_cross(t_vec v1, t_vec v2)
{
	double x = v1.y * v2.z - v1.z * v2.y;
	double y = v1.z * v2.x - v1.x * v2.z;
	double z = v1.x * v2.y - v1.y * v2.x;
	return (vec3(x, y, z));
}