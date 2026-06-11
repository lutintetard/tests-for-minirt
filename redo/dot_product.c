/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournea <lfournea@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:15:07 by lfournea          #+#    #+#             */
/*   Updated: 2026/06/11 11:50:29 by lfournea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic.h"

double	dot_product(t_vector vec1, t_vector vec2)
//produit scalaire
{
	double	result;

	result = vec1.x_axis * vec2.x_axis + vec1.y_axis * vec2.y_axis + vec1.z_axis * vec2.z_axis;	
	return (result);
}

double	dot_product_unnormed(t_vector vec1, t_vector vec2)
{
	t_vector	norm_vec_1;
	t_vector	norm_vec_2;
	double	result;

	norm_vec_1 = normalized_vector(vec1);
	norm_vec_2 = normalized_vector(vec2);
	result = dot_product(norm_vec_1, norm_vec_2);
	return (result);	
}

double	dot_product_point_vec(t_coord point, t_vector vector)
{
	t_vector	point_vec;
	double		result;

	point_vec.x_axis = point.x;
	point_vec.y_axis = point.y;
	point_vec.z_axis = point.z;
	result = dot_product_unnormed(point_vec, vector);
	return (result);	
}

double	associated_angle_rad(double val)
//trouve l'angle associe au produit scalaire en radian
{
	double	result;

	result = acos(val);
	return (result);
}

double	associated_angle_deg(double val)
//fonction a verifier
{
	double	result;

	result = acos(val);
	result = result * PI / 180;
	return (result);
}

t_vector	vector_two_points(t_coord pa, t_coord pb)
{
	t_vector	vector;

	vector.x_axis = pb.x - pa.x;
	vector.y_axis = pb.y - pa.y;
	vector.z_axis = pb.z - pa.z;
	normalized_vector(vector);
	return (vector);
}

