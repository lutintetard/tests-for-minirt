#include "minilibx/mlx.h"

typedef struct s_lib
{
	void	*mlx_server;
	void	*mlx_win;
	void	*mlx_img;
	char	*adr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
} t_lib;

void	loop(t_lib info)
{
	int	i;

	i = 0;
	while (i < 1080 )
	{
		*(unsigned int *)(info.mlx_img + i * sizeof(unsigned int)) = 0x00FFFFFF;
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
