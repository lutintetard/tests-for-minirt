# include "basic.h"

t_coord	add_points(t_coord a, t_coord b)
{
	t_coord	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return (result);
}

t_coord	sub_points(t_coord a, t_coord b)
{
	t_coord	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	return (result);
}

t_vector	point_to_vector(t_coord alpha)
{
	t_vector	output;

	output.x_axis = alpha.x;
	output.y_axis = alpha.y;
	output.z_axis = alpha.z;
	return (output);
}

double	distance_two_points(t_coord x, t_coord y)
{
	double	dim_x;
	double	dim_y;
	double	dim_z;
	double	res;

	dim_x = x.x - y.x;
	dim_y = x.y - y.y;
	dim_z = x.z - y.z;
	res = dim_x * dim_x + dim_y * dim_y + dim_z * dim_z;
	if (res < 1.0e-12)
		return (0);
	return (sqrt(res));
}
