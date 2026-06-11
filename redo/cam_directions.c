#include "basic.h"

t_vector	get_right_vec(void)
{
	t_vector	vec;

	vec.x_axis = 0;
	vec.y_axis = 1;
	vec.z_axis = 0;
	return (vec);
}

t_vector	get_up_vec(void)
{
	t_vector	vec;

	vec.x_axis = 0;
	vec.y_axis = 0;
	vec.z_axis = 1;
	return (vec);
}

t_camera	calculate_cam_directions(t_camera cam)
{
	t_vector	up;
	t_vector	right;

	cam.orientation_vector = normalized_vector(cam.orientation_vector);
	cam.up = get_up_vec();
	cam.right = get_right_vec();
	//cam.up = vector_product_unnormed(cam.orientation_vector, cam.up);
	//cam.right = vector_product_unnormed(cam.orientation_vector, cam.right);
	return (cam);
}
