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

void	loop(t_lib info)
{
	t_camera	cam;
	int	i;
	int	j;
	unsigned int	color;

	cam.coord.x = 0;
	cam.coord.y= 0;
	cam.coord.z = 0;
	cam.orientation_vector.x_axis = 1;
	cam.orientation_vector.y_axis = 0;
	cam.orientation_vector.z_axis = 0;
	cam.fov = 130;
	cam = calculate_cam_directions(cam); // completer les informations camera	
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		color = 0x00000000;
		while (j < WIDTH)
		{
			color = calculate_value_pixel(cam, j, i);
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
