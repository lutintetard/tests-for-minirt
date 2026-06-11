/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_vector_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournea <lfournea@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:32:42 by lfournea          #+#    #+#             */
/*   Updated: 2026/06/11 14:28:52 by lfournea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic.h"

t_vector	add_vector(t_vector vec1, t_vector vec2)
{
	t_vector	result;

	result.x_axis = vec1.x_axis + vec2.x_axis;
	result.y_axis = vec1.y_axis + vec2.y_axis;
	result.z_axis = vec1.z_axis + vec2.z_axis;

	return (result);
}

t_vector	sub_vectors(t_vector vec1, t_vector vec2)
{
	t_vector	result;
	
	result.x_axis = vec1.x_axis - vec2.x_axis;
	result.y_axis = vec1.y_axis - vec2.y_axis;
	result.z_axis = vec1.z_axis - vec2.z_axis;

	return (result);
}

t_vector	mult_vec_const(double value, t_vector vec)
{
	t_vector	result;
	
	result.x_axis = value * vec.x_axis;
	result.y_axis = value * vec.y_axis;
	result.z_axis = value * vec.z_axis;

	return (result);
}

t_vector	div_vec_const(double value, t_vector vec)
{
	t_vector	result;
	
	result.x_axis = vec.x_axis / value;
	result.y_axis = vec.y_axis / value;
	result.z_axis = vec.z_axis / value;

	return (result);
}

t_vector	copy_vector(t_vector other)
{
	t_vector	copy;

	copy.x_axis = other.x_axis;
	copy.y_axis = other.y_axis;
	copy.z_axis = other.z_axis;
	return (copy);
}

t_coord		copy_coord(t_coord other)
{
	t_coord		copy;

	copy.x = other.x;
	copy.y = other.y;
	copy.z = other.z;
	return (copy);
}
