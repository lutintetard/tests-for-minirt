#ifndef BASIC_H
# define BASIC_H

#include "minilibx/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define WIDTH 300
#define HEIGHT 300 
#define PI 3.14

typedef struct s_lib
//structure serveur
{
	void	*mlx_server;
	void	*mlx_win;
	void	*mlx_img;
	char	*adr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_lib;

// --math-structures--
typedef struct s_coord
{
	float	x;
	float	y;
	float	z;
}	t_coord;

typedef struct s_vector
{
	double	x_axis;
	double	y_axis;
	double	z_axis;
}	t_vector;

typedef struct s_ray
{
	t_coord	origin;
	t_vector	direction;
}	t_ray;

typedef struct s_camera
//structure camera
{
	t_coord		coord;
	t_vector	orientation_vector;
	double 			fov;
	t_vector	right;	
	t_vector	up;
}	t_camera;

typedef struct s_sphere
//structure sphere
{
	t_coord	coord;
	double	diameter;
	unsigned int color;
}	t_sphere;

typedef struct	s_quadratic
{
	double	a;
	double	b;
	double	c;
	double	delta;
}	t_quadratic;

void	draw(t_lib image, int x, int y, int color);
void	centered_coord(int *x, int *y);
void	image_coord(int *x, int *y);
void	loop(t_lib info);
t_camera	calculate_cam_directions(t_camera cam);
t_vector	get_up_vec(void);
t_vector	get_right_vec(void);
unsigned int	calculate_value_pixel(t_camera cam, int x, int y);
t_ray	find_ray(int x, int y, t_camera cam);
t_vector	add_vector(t_vector vec1, t_vector vec2);
t_vector	sub_vectors(t_vector vec1, t_vector vec2);
t_vector	mult_vec_const(double value, t_vector vec);
t_vector	div_vec_const(double value, t_vector vec);
double	vector_length(t_vector vec);
t_vector	normalized_vector(t_vector vec);
void	draw(t_lib image, int x, int y, int color);
int	 find_determinant(t_quadratic params);
unsigned int	find_color_sphere(t_sphere sphere, t_ray ray);
t_quadratic	find_values_of_quadratic_sphere(t_sphere sphere, t_ray ray,\
t_quadratic params);
unsigned int	find_intersections_sphere(t_quadratic quad, t_sphere sphere);
double dot_product(t_vector vec1, t_vector vec2);
double 	dot_product_unnormed(t_vector vec1, t_vector vec2);
double	dot_product_point_vec(t_coord point, t_vector vector);
double associated_angle_rad(double val);
double 	associated_angle_deg(double val);
t_vector	vector_two_points(t_coord pa, t_coord pb);
t_vector	vector_product(t_vector vec1, t_vector vec2);
t_vector	vector_product_unnormed(t_vector vec1, t_vector vec2);
t_coord	add_points(t_coord a, t_coord b);
t_coord	sub_points(t_coord a, t_coord b);
t_vector	point_to_vector(t_coord alpha);
t_vector	copy_vector(t_vector other);
t_coord		copy_coord(t_coord other);

#endif
