#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}			t_vec;

t_vec		vec3(double x, double y, double z);
t_vec		vec_zero(void);
t_vec		vec_cp(t_vec v);
t_vec		vec_norm(t_vec v);
t_vec		vec_cross(t_vec v1, t_vec v2);

double		vec_dot(t_vec v1, t_vec v2);
double		vec_sqmag(t_vec v);
double		vec_mag(t_vec v);

// Operation
t_vec		vec_add(t_vec v1, t_vec v2);
t_vec		vec_sub(t_vec v1, t_vec v2);
t_vec		vec_neg(t_vec v);
t_vec		vec_scale(t_vec v, double t);
t_vec		vec_div_scale(t_vec v, double t);

// Debug
void		vec_print(t_vec v);

#endif