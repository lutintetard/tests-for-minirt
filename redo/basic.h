#ifndef BASIC_H
# define BASIC_H

#include "minilibx/mlx.h"
#define WIDTH 1920
#define HEIGHT 1080

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

void	draw(t_lib image, int x, int y, int color);
void	centered_coord(int *x, int *y);
void	image_coord(int *x, int *y);

#endif
