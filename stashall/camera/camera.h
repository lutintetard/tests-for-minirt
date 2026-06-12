/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournea <lfournea@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 12:20:28 by lfournea          #+#    #+#             */
/*   Updated: 2026/05/04 16:01:18 by lfournea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "../srcs/minirt.h"

typedef struct s_win_view
{
	double float	height;
	double float	width;
	double float	pixel_size;
	double float	angle_rad;
	double float	offset_right;
	double float	offset_up;
}	t_win_view;

typedef struct	s_quadratic
{
	double	a;
	double	b;
	double	c;
	double	delta;
}	t_quadratic;

typedef struct	s_intersections
{
	double float	distance;
	t_color		point_color;
}	t_intersections;

#endif
