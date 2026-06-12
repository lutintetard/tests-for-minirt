/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_vector_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournea <lfournea@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:32:42 by lfournea          #+#    #+#             */
/*   Updated: 2026/04/28 12:08:58 by lfournea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_functions.h"

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

t_vector	mult_vec_const(double float value, t_vector vec)
{
	t_vector	result;
	
	result.x_axis = value * vec.x_axis;
	result.y_axis = value * vec.y_axis;
	result.z_axis = value * vec.z_axis;

	return (result);
}

t_vector	div_vec_const(double float value, t_vector vec)
{
	t_vector	result;
	
	result.x_axis = vec.x_axis / value;
	result.y_axis = vec.y_axis / value;
	result.z_axis = vec.z_axis / value;

	return (result);
}
