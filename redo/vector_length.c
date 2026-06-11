/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournea <lfournea@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:24:13 by lfournea          #+#    #+#             */
/*   Updated: 2026/06/11 12:11:10 by lfournea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic.h"

double	vector_length(t_vector vec)
{
	double	result;

	result = vec.x_axis * vec.x_axis + vec.y_axis * vec.y_axis + vec.z_axis * vec.z_axis;
	result = sqrt(result);
	return (result);
}

t_vector	normalized_vector(t_vector vec)
{
	double 	length;
	t_vector	normed;

	length = vector_length(vec);
	normed = div_vec_const(length, vec);
	return (normed);	
}
