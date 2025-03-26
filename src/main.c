#include "minirt.h"

int	main(void)
{
	t_vec v1 = vec3(1.0, 2.0, 3.0);
	t_vec v2 = vec3(4.0, 5.0, 6.0);
	t_vec result;

	// vec_add
	result = vec_add(v1, v2);
	vec_print(result); // Expected: vec(5.000000, 7.000000, 9.000000)

	// vec_sub
	result = vec_sub(v1, v2);
	vec_print(result); // Expected: vec(-3.000000, -3.000000, -3.000000)

	// vec_neg
	result = vec_neg(v1);
	vec_print(result); // Expected: vec(-1.000000, -2.000000, -3.000000)

	// vec_scale
	result = vec_scale(v1, 2.0);
	vec_print(result); // Expected: vec(2.000000, 4.000000, 6.000000)

	// vec_div_scale
	result = vec_div_scale(v1, 2.0);
	vec_print(result); // Expected: vec(0.500000, 1.000000, 1.500000)

	// vec_cross
	result = vec_cross(v1, v2);
	vec_print(result); // Expected: vec(-3.000000, 6.000000, -3.000000)

	// vec_dot
	double dot_result = vec_dot(v1, v2);
	printf("vec_dot: %f\n", dot_result); // Expected: 32.000000

	// vec_mag
	double mag_result = vec_mag(v1);
	printf("vec_mag: %f\n", mag_result); // Expected: 3.741657

	// vec_sqmag
	double sqmag_result = vec_sqmag(v1);
	printf("vec_sqmag: %f\n", sqmag_result); // Expected: 14.000000

	// vec_norm
	result = vec_norm(v1);
	vec_print(result); // Expected: vec(0.267261, 0.534522, 0.801784)

	// vec_zero
	result = vec_zero();
	vec_print(result); // Expected: vec(0.000000, 0.000000, 0.000000)

	return (0);
}