#include "basic.h"

/*
t_vector	find_ray(int pixel, t_win_view win, t_camera camera)
//cette fonction determine en fonction de l'indice du pixel le rayon associe
//il renvoie la structure correspondant a ce rayon
//pour des questions de lisibilite l'equation "vector = f + au + bv" est 
//decomposee en plusieurs lignes
{
	t_vector	associated_vector;

	find_offsets(pixel, win);
	associated_vector = orientation->vector;
	associated_vector = add_vector(mult_vec_const(win.offset_right, camera->right), associated_vector);
	associated_vector = add_vector(mult_vec_const(win.offset_up, camera->up), associated_vector);
	associated_vector = normalized_vector(associated_vector);
	return (associated_vector); 
}
*/

t_ray	find_ray(int x, int y, t_camera cam)
{
	double 	offset_x;
	double 	offset_y;
	t_ray		ray_to_send;
	double	opposed;

	opposed = tan((cam.fov * 3.14 / 360));
	offset_x = x / (double)(WIDTH) * opposed;
	printf("angle = %f\t" , cam.fov * 3.14 / 360);
	printf("value x: %d, \toffset x = %f\n" , x, offset_x);
	offset_y = y / (double)(WIDTH) * opposed;
	printf("value y: %d \toffset y = %f\n" , y, offset_y);
	ray_to_send.direction = copy_vector(cam.orientation_vector);
	printf("x factor ray: %d, y factor ray: %d, z factor ray: %d\n", ray_to_send.direction.x_axis, ray_to_send.direction.y_axis, ray_to_send.direction.z_axis);
	ray_to_send.direction = copy_vector(add_vector(mult_vec_const(offset_x, cam.right), ray_to_send.direction));
	ray_to_send.direction = copy_vector(add_vector(mult_vec_const(offset_y, cam.up), ray_to_send.direction));
	ray_to_send.direction = copy_vector(normalized_vector(ray_to_send.direction));
	//printf("x factor ray: %d, y factor ray: %d, z factor ray: %d\n", ray_to_send.direction.x_axis, ray_to_send.direction.y_axis, ray_to_send.direction.z_axis);
	ray_to_send.origin = copy_coord(cam.coord);
	return (ray_to_send);
}

/*
void 	determine_scene_prop(t_win_view info,  double float deg)
//le but de cette fonction est de determiner l'offset necessaire au calcul des
//rayons associes
//dans cette fonction il faut verifier que l'on ne prend pas la moitie de la 
//valeur renseignee en parametre par l'utilisateur
{
	double float	angle_rad;
	
	angle_rad = deg * PI / 180;
	info.height = tan(angle_rad);
	info.pixel_size = 2 * info.height / WIN_HEIGHT;
	info.width = info.pixel_size * WIN_WIDTH / 2;
	return (pixel_size);
}
*/

unsigned int	calculate_value_pixel(t_camera cam, int x, int y)
//cette fonction ne s'execute que lorsque on a obtenu le ray que l'on souhaite envoyer sur 
//la scene
{
	t_vector	associated_ray;
	t_sphere	sphere;
	t_ray		ray;

	sphere.coord.x = 20;
	sphere.coord.y = 0;
	sphere.coord.z = 0;
	sphere.diameter = 5;
	sphere.color = 0x000000FF;

	centered_coord(&x, &y);
	ray = find_ray(x, y, cam);
	//printf("x: %d\t y: %d\t z: %d\n", ray.direction.x_axis, ray.direction.y_axis, ray.direction.y_axis);
	//usleep(5000);
	return (find_color_sphere(sphere, ray));
	//iterer sur chaque objet et determiner si il y a une intersection 
	//entre le rayon et la forme
	//trouver la valeur la plus faible et afficher la couleur associee
	//stocket les points d'intersection sous la forme de liste chainee
}

/*
int	send_rays(t_lib info)
//cette fonction parcours les pixels selon leurs indices et lance les fonctions 
//qui determinent la couleur a afficher
{
	t_camera	cam;
	int	pixel_i;

	cam.coord.x = 0
	cam.coord.y= 0
	cam.coord.z = 0
	cam.orientation_vector.x_axis = 1;
	cam.orientation_vector.y_axis = 0;
	cam.orientation_vector.z_axis = 0;
	cam.fov = 70;
	
	calculate_cam_directions(cam); // completer les informations camera	
	//determine_scene_prop(essentials, info->camera->fov);
	pixel_i = 0;
	while (pixel_i < WIN_WIDTH * WIN_HEIGHT)
	{
		calculate_value_pixel(info, pixel_i, essentials);
		pixel_i++;
	}
	//push l'image une fois que le rendu est calcule
}
*/
