#include "basic.h"

void	loop(t_lib info)
{
	int	i;

	i = 0;
	while (i < 1080 * 1920)
	{
		draw(info, i % WIDTH, i / HEIGHT, 0x00FF0000);
		i++;
	}
}

int	main(void)
//maniere de compiler avec les bonnes bibliotheques 
//cc minirt.c -lmlx_Linux -lmlx -Lminilibx -Iminilibx -lXext -lX11 -lm -lz
{
	t_lib	images;

	images.mlx_server = mlx_init();
	images.mlx_win = mlx_new_window(images.mlx_server, 1920, 1080, "Hello World!");	
	images.mlx_img = mlx_new_image(images.mlx_server, 1920, 1080);
	images.adr = mlx_get_data_addr(images.mlx_img, &images.bits_per_pixel, &images.line_length, &images.endian);
	loop(images);
	mlx_put_image_to_window(images.mlx_server, images.mlx_win, images.mlx_img, 0, 0);
	mlx_loop(images.mlx_server);

	return (0);
}
