/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:31:19 by tparis            #+#    #+#             */
/*   Updated: 2026/04/29 17:43:13 by lfournea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

// ----Other----- //
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

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;


// -----Shapes----- //

typedef struct s_sphere
{
	t_coord	coord;
	double	diameter;
	t_color	color;
}	t_sphere;

typedef struct s_plane
{
	t_coord		*coord;
	t_vector	*normal_vector;
	t_color		*color;
}	t_plane;

typedef struct s_cylinder
{
	t_coord		coord;
	t_vector	axis_vector;
	double	diameter;
	double	height;
	t_color		color;
}	t_cylinder;

enum e_object_type
{
	SPHERE,
	PLANE,
	CYLINDER,
	CAM,
	LIGHT,
	AMBIENT,
};

typedef struct s_objects
{
	int					object_type;
	void				*object;
}	t_objects;

// -----Cam&Light----- //

typedef struct s_camera
{
	t_coord		coord;
	t_vector	orientation_vector;
	double 			fov;
	t_vector	right;	
	t_vector	up;
}	t_camera;

typedef struct s_light
{
	t_coord	coord;
	double 	bright_ratio;
	t_color	color;
} t_light;

typedef struct s_ambient
{
	float	ambient_light_ratio;
	t_color	*color;
}	t_ambient;

#endif
