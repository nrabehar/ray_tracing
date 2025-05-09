#ifndef COLOR_H
# define COLOR_H

# include "../../math/inc/math.h"

typedef t_vec	t_color;

t_color			color(double r, double g, double b);
t_color			cl_mul(t_color c1, t_color c2);
t_color			cl_had(t_color c1, t_color c2);

t_color			cl_norm(t_color c);
t_color			cl_unit(t_color c);

int				cl_to_int(t_color c);

#endif