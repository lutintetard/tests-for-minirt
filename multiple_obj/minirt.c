#include  "basic.h"

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
	sphere = malloc(sizeof(t_sphere));
	plane = malloc(sizeof(t_plane));
	sphere->coord.x = 20;
	sphere->coord.y = 0;
	sphere->coord.z = 0;
	sphere->diameter = 10;
	sphere->color = 0x00770000;
	plane->coord.x = 0;
	plane->coord.y = 0;
	plane->coord.z = -10;
	plane->normal_vector.x_axis = 0;
	plane->normal_vector.y_axis = 0;
	plane->normal_vector.z_axis = 1;
	plane->normal_vector = normalized_vector(plane->normal_vector);
	plane->color = 0x00777777;
	cyl->coord.x = 20;
	cyl->coord.y = 0;
	cyl->coord.z = 0;
	cyl->axis_vector.x_axis = 1;
	cyl->axis_vector.y_axis = 0;
	cyl->axis_vector.z_axis = -0.25;
	cyl->axis_vector = normalized_vector(cyl->axis_vector);
	cyl->diameter = 5;
	cyl->height = 11;
	cyl->color = 0x00007700;

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
	obj2->next = NULL;
	obj3->name = CYL;
	obj3->obj = (void *)cyl;
	obj3->next = NULL;
	*node = obj1;
}

void	set_light(t_lib *info)
{
	info->light.coord.x = 10;
	info->light.coord.y = 0;
	info->light.coord.z = 0;
	info->light.bright_ratio = 1;
	info->light.color = 0x00FFFFFF;
}

void	loop(t_lib *info)
{
	t_camera	cam;
	int	i;
	int	j;
	unsigned int	color;

	cam.coord.x = 0;
	cam.coord.y = 0;
	cam.coord.z = 10;
	cam.orientation_vector.x_axis = 1;
	cam.orientation_vector.y_axis = 0;
	cam.orientation_vector.z_axis = -0.25;
	cam.fov = 70;
	cam = calculate_cam_directions(cam); // completer les informations camera	
	set_light(info);
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		color = 0x00000000;
		while (j < WIDTH)
		{
			color = calculate_value_pixel(*info, cam, j, i);
			printf("image x: %d image y: %d color: %d\n", j, i, color);
			draw(*info, j++, i, color);
		}
		i++;
	}
}

int	close_window(void *param)
{
	t_lib	argument;
	t_node	*node;
	t_node	*prev;

	argument = *(t_lib *)param;
	node = argument.object_list;
	while (node != NULL)
	{
		free(node->obj);
		prev = node;
		node = node->next;
		free(prev);
	}
	mlx_destroy_image(argument.mlx_server, argument.mlx_img);
	mlx_destroy_window(argument.mlx_server, argument.mlx_win);
	mlx_destroy_display(argument.mlx_server);
	free(argument.mlx_server);
	exit(0);
}

int	escape_win(int keycode, void *param)
{
	if (keycode == XK_Escape)
	{
		close_window(param);
		return (0);
	}
	return (0);
}

int	main(void)
//maniere de compiler avec les bonnes bibliotheques 
//cc *.c -lmlx_Linux -lmlx -Lminilibx -Iminilibx -lXext -lX11 -lm -lz
{
	t_lib	images;

	debug();
	images.mlx_server = mlx_init();
	images.mlx_win = mlx_new_window(images.mlx_server, WIDTH, HEIGHT, "Hello World!");	
	images.mlx_img = mlx_new_image(images.mlx_server, WIDTH, HEIGHT);
	images.adr = mlx_get_data_addr(images.mlx_img, &images.bits_per_pixel, &images.line_length, &images.endian);
	generate_list_of_objects(&images.object_list);
	loop(&images);
	mlx_put_image_to_window(images.mlx_server, images.mlx_win, images.mlx_img, 0, 0);
	mlx_key_hook(images.mlx_win, escape_win, (void *)&images);
	mlx_hook(images.mlx_win, 17, 0, close_window, (void *)&images);
	mlx_loop(images.mlx_server);
	return (0);
}
