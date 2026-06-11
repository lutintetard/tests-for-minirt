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
