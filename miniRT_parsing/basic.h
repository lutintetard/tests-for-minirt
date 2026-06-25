/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:36:34 by tparis            #+#    #+#             */
/*   Updated: 2026/06/25 14:33:53 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_H
# define BASIC_H

# include "Libft/libft.h"

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <float.h>
# include <fcntl.h>
# include <string.h>

# define BUFFER_SIZE 1024
# define DEBUG 0

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
	t_coord		origin;
	t_vector	direction;
}	t_ray;

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
}	t_color;

typedef struct s_camera
//structure camera
{
	t_coord		coord;
	t_vector	orientation_vector;
	double		fov;
	t_vector	right;	
	t_vector	up;
}	t_camera;

typedef struct s_sphere
//structure sphere
{
	t_coord			coord;
	double			diameter;
	unsigned int	color;
}	t_sphere;

typedef struct s_plane
{
	t_coord			coord;
	t_vector		normal_vector;
	unsigned int	color;
}	t_plane;

typedef struct s_cylinder
{
	t_coord			coord;
	t_vector		axis_vector;
	double			diameter;
	double			height;
	unsigned int	color;
}	t_cylinder;

typedef struct s_light
{
	t_coord			coord;
	double			bright_ratio;
	unsigned int	color;
}	t_light;

typedef struct s_ambient
{
	double			bright_ratio;
	unsigned int	color;
}	t_ambient;

typedef struct s_quadratic
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
	t_coord			inter_point;
	double			distance;
	unsigned int	color;
}	t_inter;

typedef struct s_node
{
	int				name;
	void			*obj;
	struct s_node	*next;
}	t_node;

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
