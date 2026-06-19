#include "basic.h"

t_ray	find_ray(int x, int y, t_camera cam)
{
	double 	offset_x;
	double 	offset_y;
	t_ray		ray_to_send;
	double	opposed;

	opposed = tan((cam.fov * 3.14 / 360));
	offset_x = 2 * x / (double)(WIDTH) * opposed;
	printf("----------New Ray------------------\n");
	printf("angle = %f\n" , cam.fov * 3.14 / 360);
	printf("value x: %d, \toffset x = %f\n" , x, offset_x);
	offset_y = 2 * y / (double)(WIDTH) * opposed;
	printf("value y: %d \toffset y = %f\n" , y, offset_y);
	ray_to_send.direction = copy_vector(cam.orientation_vector);
	//printf("x factor ray: %d, y factor ray: %d, z factor ray: %d\n", ray_to_send.direction.x_axis, ray_to_send.direction.y_axis, ray_to_send.direction.z_axis);
	ray_to_send.direction = add_vector(mult_vec_const(offset_x, cam.right), ray_to_send.direction);
	ray_to_send.direction = add_vector(mult_vec_const(offset_y, cam.up), ray_to_send.direction);
	ray_to_send.direction = normalized_vector(ray_to_send.direction);
	printf("x factor ray: %f, y factor ray: %f, z factor ray: %f\n", ray_to_send.direction.x_axis, ray_to_send.direction.y_axis, ray_to_send.direction.z_axis);
	ray_to_send.origin = copy_coord(cam.coord);
	return (ray_to_send);
}

/*
unsigned int	calculate_value_pixel_sphere(t_camera cam, int x, int y)
//cette fonction ne s'execute que lorsque on a obtenu le ray que l'on souhaite envoyer sur 
//la scene
{
	t_vector	associated_ray;
	t_sphere	sphere;
	t_ray		ray;

	//sphere.coord.x = 20;
	//sphere.coord.y = 0;
	//sphere.coord.z = 0;
	//sphere.diameter = 5;
	//sphere.color = 0x000000FF;

	//centered_coord(&x, &y);
	//ray = find_ray(x, y, cam);
	//printf("x: %d\t y: %d\t z: %d\n", ray.direction.x_axis, ray.direction.y_axis, ray.direction.y_axis);
	//usleep(5000);
	return (find_color_sphere(sphere, ray));
	//iterer sur chaque objet et determiner si il y a une intersection 
	//entre le rayon et la forme
	//trouver la valeur la plus faible et afficher la couleur associee
	//stocket les points d'intersection sous la forme de liste chainee
}

unsigned int	calculate_value_pixel_plane(t_camera cam, int x, int y)
{
	t_vector	associated_ray;
	t_plane		plane;
	t_ray		ray;

	plane.normal_vector = normalized_vector(plane.normal_vector); 
	//centered_coord(&x, &y);
	//ray = find_ray(x, y, cam);
	//printf("x: %d\t y: %d\t z: %d\n", ray.direction.x_axis, ray.direction.y_axis, ray.direction.y_axis);
	//usleep(5000);
	return (find_color_plane(plane, ray));
}


unsigned int	calculate_val_pixel_cyl(t_camera cam, int x, int y)
{
	t_cylinder		cyl;
	t_ray		ray;

	cyl.axis_vector = normalized_vector(cyl.axis_vector); 
	//centered_coord(&x, &y);
	//ray = find_ray(x, y, cam);
	//printf("x: %d\t y: %d\t z: %d\n", ray.direction.x_axis, ray.direction.y_axis, ray.direction.y_axis);
	//usleep(5000);
	return (find_color_cyl(cyl, ray));
}
*/

double	distance_to_obj(t_ray ray, t_node *obj, unsigned int *color)
{
	if (obj->name == SPHERE)
	{
		*color = (*(t_sphere *)obj->obj).color;
		return (find_color_sphere(*(t_sphere *)obj->obj, ray));
	}	
	if (obj->name == PLANE)
	{
		//faire attention a ce que le vecteur soit bien normalise
		*color = (*(t_plane *)obj->obj).color;
		return (find_color_plane(*(t_plane *)obj->obj, ray));	
	}
	if (obj->name == CYL)
	{
		//faire attention a ce que le vecteur soit bien normalise
		*color = (*(t_cylinder *)obj->obj).color;
		return (find_color_cyl(*(t_cylinder *)obj->obj, ray));	
	}
	printf("PARSING_ERROR : unknown object\n");
	return (-1);
}

unsigned int	calculate_value_pixel(t_lib info, t_camera cam, int x, int y)
{
	double	distance;
	t_inter	closest_object;
	t_node	*curr_node;
	t_ray	ray;

	centered_coord(&x, &y);
	ray = find_ray(x, y, cam);
	//attention utiliser la version de 42
	memset(&closest_object, 0, sizeof(t_inter));
	closest_object.distance = DBL_MAX;
	curr_node = info.object_list;
	while (curr_node != NULL)
	{
		unsigned int	obj_color;

		distance = distance_to_obj(ray, curr_node, &obj_color);
		if (distance >= 0 && distance < closest_object.distance)
		{
			closest_object.inter_point = add_point_vector\
			(cam.coord, mult_vec_const(distance, ray.direction)); 
			closest_object.color = obj_color;
			closest_object.distance = distance;
		}
		curr_node = curr_node->next;
	}
	t_ray	object_to_light;

	object_to_light.direction = normalized_vector(vector_two_points(closest_object.inter_point, info.light.coord));
	object_to_light.origin = add_point_vector(copy_coord(closest_object.inter_point), mult_vec_const(1.000001, object_to_light.direction)); 

	double	distance_light;
	distance_light = distance_two_points(info.light.coord, object_to_light.origin); 
	curr_node = info.object_list;
	while (curr_node != NULL)
	{
		unsigned int	obj_color;

		distance = distance_to_obj(object_to_light, curr_node, &obj_color);
		if (distance > 0 && distance < distance_light)
		{
			return(closest_object.color);
			//return (closest_object.color);
		}
		curr_node = curr_node->next;
	}
	//formule pour l'ombre
	//return (closest_object.color * 2);
	return (make_light_nice(closest_object.color, info.light, distance_light));
}
