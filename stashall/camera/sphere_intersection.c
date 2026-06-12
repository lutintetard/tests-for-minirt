/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournea <lfournea@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:28:02 by lfournea          #+#    #+#             */
/*   Updated: 2026/06/11 11:14:39 by lfournea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	find_values_of_quadratic_sphere(t_sphere *sphere, t_minirt *info,\
t_quadratic *params)
//la resolution de l'equation du second degre quand il y a intersection 
//entre un point et une sphere est 
//a = 1
//b = 2D . (O - C)
//c = | O - C | ^2 - R^2
//A VERIFIER LES RESULTATS
{
	t_vector	intermediary_step;

	params->a = 1;
	intermediary_step = sub_vectors(info->camera->coord, sphere->coord);
	params->b = dot_product(mult_vec_const(2, info->current_ray.direction), params->c);  
	params->c = pow(vector_length(intermediary_step), 2);
	params->c -= pow(sphere->diameter, 2);
}

int	 find_determinant(t_quadratic *params)
//le calcul du delta est le suivant;
//delta = b^2 - 4ac
{
	params->delta = pow(params->b, 2) - (4 * params->a * params->c);
	if (params->delta < 0)
		return (1);
	return (0);
} 

int	find_intersections_sphere(t_quadratic *quad, t_node **list, t_sphere *sphere)
//pour determiner la distance il faut resoudre l'equation avec -b +/- racine delta / 2a
{
	double	distance_1;
	double	distance_2;

	distance_1 = ((-1) * (quad->b) - sqrt(quad->delta)) / (2 * quad->a);
	distance_2 = ((-1) * (quad->b) + sqrt(quad->delta)) / (2 * quad->a);
	if (create_node_if_postive(distance_1, list, sphere))
		return (1);
	if (distance_1 == distance_2)
		return (0);
	if (create_node_if_postive(distance_2, list, sphere))
		return (1);
	return (0);
}

int	create_node_if_postive(double dist, t_node **list, t_sphere *sphere)
{
	t_intersection	*inter;

	if (dist < 0)
		return (0);
	inter = malloc(sizeof(t_intersection));
	if (inter == NULL)
		return (1);
	inter->distance = dist;
	inter->color = sphere->color;
	if (add_to_list(list, (void *)inter))
		return (free(inter), 1);	
	return (0);
}
