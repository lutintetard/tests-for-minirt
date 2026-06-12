/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cam_directions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournea <lfournea@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:22:07 by lfournea          #+#    #+#             */
/*   Updated: 2026/04/29 11:22:37 by lfournea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_vector	get_right_vec(void)
{
	t_vector	vec;

	vec.x_axis = 1;
	vec.y_axis = 0;
	vec.z_axis = 0;
	return (vec);
}

t_vector	get_up_vec(void)
{
	t_vector	vec;

	vec.x_axis = 0;
	vec.y_axis = 1;
	vec.z_axis = 0;
	return (vec);
}

void	calculate_cam_directions(t_camera *cam)
{
	t_vector	up;
	t_vector	right;

	cam->orientation_vector = normalized_vector(cam->orientation_vector);
	up = get_up_vec();
	right = get_right_vec();
	cam->up = vector_product_unnormed(cam->orientation_vector, up);
	cam->right = vector_product_unnormed(cam->orientation_vector, right);
} 
