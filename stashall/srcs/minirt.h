/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:17:08 by tparis            #+#    #+#             */
/*   Updated: 2026/05/04 15:33:36 by lfournea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h> //malloc
# include <math.h>
# include <stdio.h> //printf
# include <fcntl.h> //open
# include <unistd.h> //read, close

# include "../minilibx-linux/mlx.h" 
# include "../Libft/libft.h"
# include "../math_functions/math_functions.h"
# include "objects.h"

# define WIN_WIDTH 720
# define WIN_HEIGHT 480
# define PI 3.141592654

typedef struct s_node
{
	void			*structure;
	struct s_node	*next;
} t_node;

typedef struct s_minirt
{
	void	*mlx;
	void	*win;
	void	*img;
	t_node	*objects;
	t_node	*lights;
	t_camera	*camera;
	t_ambient	*ambient;
	t_ray		current_ray;
}	t_minirt;

// -- utils.c
void	exit_msg(char *msg, int code);
void	free_minirt(t_minirt *minirt);
int		close_win(t_minirt *minirt);

// -- parsing/parsing.c
t_node		**parse_file(char *path);

// -- parsing/new_object.c
t_objects	*new_sphere(char **split);
t_objects	*new_plane(char **split);
t_objects	*new_cylinder(char **split);

// -- parsing/new_object2.c
t_objects	*new_ambient(char **split);
t_objects	*new_light(char **split);
t_objects	*new_camera(char **split);

// -- parsing/parse_ccv.c
t_coord		*parse_coord(char *str);
t_color		*parse_color(char *str);
t_vector 	*parse_vector(char *str);

// -- parsing/utils.c
int 	is_in_list(char *str, char **list);
int		nb_str(char **strs);
float	ft_atof(const char *str);
void 	add_object_to_list(t_node **list, t_objects *new_object);

// -- parsing/print_objects.c
void	print_list_objects(t_node *node_list);

// -- parsing/free_functions.c
void	free_strs(char **strs);
void	free_objects_list(t_node *object_list);

#endif
