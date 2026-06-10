/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournea <lfournea@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:37:58 by lfournea          #+#    #+#             */
/*   Updated: 2026/04/28 15:32:36 by lfournea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_functions.h"

t_vector	vector_product(t_vector vec1, t_vector vec2)
{
	t_vector	result;

	result.x_axis = vec1.y_axis * vec2.z_axis - vec1.z_axis * vec2.y_axis;
	result.y_axis = vec1.z_axis * vec2.x_axis - vec1.x_axis * vec2.z_axis;
	result.z_axis = vec1.x_axis * vec2.y_axis - vec1.y_axis * vec2.x_axis;
	result = normalized_vector(result);	
	return (result);
}

t_vector	vector_product_unnormed(t_vector vec1, t_vector vec2)
{
	t_vector	result;
	t_vector	norm_vector_1;
	t_vector	norm_vector_2;

	norm_vector_1 = normalized_vector(vec1);
	norm_vector_2 = normalized_vector(vec2);
	result = vector_product(norm_vector_1, norm_vector_2);
	return (result);
}
