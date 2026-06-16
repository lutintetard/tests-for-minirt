#include "basic.h"

void	loop_test(t_lib info)
//fonction pour tester l'affichage des pixels;
{
	int	i;
	int	j;

	i = 0;	
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
			draw(info, i, j++, 0x00FF0000);
		i++;
	}
}

void	generate_list_of_objects(t_node **node)
{
	t_cylinder	*cyl;
	t_sphere	*sphere;
	t_plane		*plane;

	cyl = malloc(sizeof(t_cylinder));
	sphere =  malloc(sizeof(t_cylinder));
	plane = malloc(sizeof(t_plane));
	sphere->coord.x = 20;
	sphere->coord.y = 0;
	sphere->coord.z = 0;
	sphere->diameter = 5;
	sphere->color = 0x000000FF;
	plane->coord.x = 0;
	plane->coord.y = 0;
	plane->coord.z = -10;
	plane->normal_vector.x_axis = 0;
	plane->normal_vector.y_axis = 2;
	plane->normal_vector.z_axis = 1;
	plane->color = 0x00FF0000;
	cyl->coord.x = 20;
	cyl->coord.y = 0;
	cyl->coord.z = 0;
	cyl->axis_vector.x_axis = 1;
	cyl->axis_vector.y_axis = 1;
	cyl->axis_vector.z_axis = 1;
	cyl->diameter = 1;
	cyl->height = 5;
	cyl->color = 0x0000FF00;

	t_node	*obj1;
	t_node	*obj2;
	t_node	*obj3;

	obj1 = malloc(sizeof(t_node));
	obj2 = malloc(sizeof(t_node));
	obj3 = malloc(sizeof(t_node));
	obj1->name = PLANE;
	obj1->obj = (void *)plane;
	obj1->next = obj2;
	obj2->name = SPHERE;
	obj2->obj = (void *)sphere;
	obj2->next = obj3;
	obj3->name = CYL;
	obj3->obj = (void *)CYL;
	obj3->next = NULL;
	*node = obj1;
}


void	loop(t_lib info)
{
	t_camera	cam;
	int	i;
	int	j;
	unsigned int	color;

	cam.coord.x = 0;
	cam.coord.y= 0;
	cam.coord.z = 0;
	cam.orientation_vector.x_axis = 0;
	cam.orientation_vector.y_axis = 0;
	cam.orientation_vector.z_axis = -1;
	cam.fov = 70;
	cam = calculate_cam_directions(cam); // completer les informations camera	
	generate_list_of_objects(&info.object_list);
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		color = 0x00000000;
		while (j < WIDTH)
		{
			color = calculate_value_pixel(info, cam, j, i);
			printf("image x: %d image y: %d color: %d\n", j, i, color);
			draw(info, j++, i, color);
		}
		i++;
	}
}

int	main(void)
//maniere de compiler avec les bonnes bibliotheques 
//cc minirt.c -lmlx_Linux -lmlx -Lminilibx -Iminilibx -lXext -lX11 -lm -lz
{
	t_lib	images;

	images.mlx_server = mlx_init();
	images.mlx_win = mlx_new_window(images.mlx_server, WIDTH, HEIGHT, "Hello World!");	
	images.mlx_img = mlx_new_image(images.mlx_server, WIDTH, HEIGHT);
	images.adr = mlx_get_data_addr(images.mlx_img, &images.bits_per_pixel, &images.line_length, &images.endian);
	loop(images);
	mlx_put_image_to_window(images.mlx_server, images.mlx_win, images.mlx_img, 0, 0);
	mlx_loop(images.mlx_server);
	return (0);
}
