#ifndef BASIC_H
# define BASIC_H

# include "minilibx/mlx.h"
# include "Libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <float.h>
# include <string.h>
# include <stdbool.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <unistd.h>
# define WIDTH 900
# define HEIGHT 600 
# define PI 3.14
# define PLANE_QUAD_ON 1
# define IMPLEMENT_DEBUG 1
# define DEBUG 0


// --math-structures--
typedef struct s_coord
{
	double	x;
	double	y;
	double	z;
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

typedef struct s_plane
{
	t_coord		coord;
	t_vector	normal_vector;
	unsigned int	color;
}	t_plane;

typedef struct s_cylinder
{
	t_coord		coord;
	t_vector	axis_vector;
	double	diameter;
	double	height;
	unsigned int	color;
}	t_cylinder;

typedef struct s_light
{
	t_coord	coord;
	double 	bright_ratio;
	unsigned int	color;
}	t_light;

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
}	t_color;

typedef struct s_ambient
{
	double			bright_ratio;
	unsigned int	color;
}	t_ambient;

typedef struct	s_quadratic
{
	double	a;
	double	b;
	double	c;
	double	delta;
}	t_quadratic;

typedef enum e_shape
{
	SPHERE,
	PLANE,
	CYL,
	LIGHT,
	AMBIENT,
	CAM,
}	t_shape;

typedef struct s_inter
{
	t_coord	inter_point;
	double	distance;
	unsigned int color;
	t_vector vec;
}	t_inter;

typedef struct s_node
{
	int	name;
	void	*obj;
	struct s_node *next;
}	t_node;

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
	t_node	*object_list;
	t_light	*light;
	t_camera	*cam;
}	t_lib;

void	draw(t_lib image, int x, int y, int color);
void	centered_coord(int *x, int *y);
void	image_coord(int *x, int *y);
void	loop(t_lib *info);
t_camera	calculate_cam_directions(t_camera cam);
t_vector	get_up_vec(void);
t_vector	get_right_vec(void);
unsigned int	calculate_value_pixel(t_lib info, t_camera cam, int x, int y);
t_ray	find_ray(int x, int y, t_camera cam);
t_vector	add_vector(t_vector vec1, t_vector vec2);
t_vector	sub_vectors(t_vector vec1, t_vector vec2);
t_vector	mult_vec_const(double value, t_vector vec);
t_vector	div_vec_const(double value, t_vector vec);
t_coord		add_point_vector(t_coord point, t_vector vec);
double	vector_length(t_vector vec);
t_vector	normalized_vector(t_vector vec);
void	draw(t_lib image, int x, int y, int color);
double	 find_determinant(t_quadratic params);
double	find_color_sphere(t_sphere sphere, t_ray ray);
t_quadratic	find_values_of_quadratic_sphere(t_sphere sphere, t_ray ray,\
t_quadratic params);
double	find_intersections_sphere(t_quadratic quad);
double dot_product(t_vector vec1, t_vector vec2);
double 	dot_product_unnormed(t_vector vec1, t_vector vec2);
double	dot_product_point_vec(t_coord point, t_vector vector);
double	dot_product_point_vec_two(t_coord point, t_vector vector);
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
double	distance_two_points(t_coord x, t_coord y);
double	find_color_plane(t_plane plane, t_ray ray);
//unsigned int	calculate_value_pixel_plane(t_camera cam, int x, int y);
double	find_color_cyl(t_cylinder cyl, t_ray ray);
//unsigned int	calculate_val_pixel_cyl(t_camera cam, int x, int y);
double	smallest_positive(double x, double y);
unsigned int	make_light_nice(unsigned int color, t_light light, double distance);
void	debug(void);

// --parsing--
t_node			*parse_scene(const char *filename);
unsigned int	rgb_to_uint(const char *str);
t_coord			parse_coord(const char *str);
t_node			*parse_sphere(const char *line);
t_node			*parse_plane(const char *line);
t_node			*parse_cylinder(const char *line);
t_node			*parse_light(const char *line);
t_node			*parse_ambient(const char *line);
t_node			*parse_camera(const char *line);

// --validation--
int				scan_lines(char **lines);
int				is_valid_ambient(char *line, int nb_line, int nb_ambient);
int				is_valid_vector(char *str);
int				is_valid_color(char *str);
int				is_valid_sphere(char *line, int nb_line);
int				is_valid_cylinder(char *line, int nb_line);
int				is_valid_plane(char *line, int nb_line);
int				is_valid_light(char *line, int nb_line, int nb_light);
int				is_valid_camera(char *line, int nb_line, int nb_cam);

// --utils--
double			ft_atof(const char *str);
char			*read_file(const char *filename);
void			add_node(t_node *scene, t_node *new_node);
t_vector		convert_coord_to_vector(t_coord coord);
void			print_scene(t_node *scene);
t_node			*find_shape(t_node *shape_list, int type);
t_color			hextocolor(unsigned int hex);
unsigned int	colortohex(t_color c);
unsigned int	calculate_color(unsigned int obj_color\
, unsigned int light_color, double bright);
t_node 			*copy_list_obj(t_node *scene);

// --print--
void			print_coord(t_coord coord);
void			print_sphere(t_sphere *sphere);
void			print_plane(t_plane *plane);
void			print_cylinder(t_cylinder *cylinder);
void			print_light(t_light *light);
void			print_ambient(t_ambient *ambient);
void			print_camera(t_camera *camera);

// --light--
int				apply_ambient(t_node *scene, t_ambient *ambient);

// --free_functions--
void			free_split(char **split);
void			free_scene(t_node *scene, int free_obj);

#endif
