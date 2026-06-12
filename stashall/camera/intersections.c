/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournea <lfournea@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:56:59 by lfournea          #+#    #+#             */
/*   Updated: 2026/06/10 14:22:56 by lfournea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

int	inter_sphere(t_sphere *sphere, t_node **list, t_minirt *info)
// pour determiner le point d'intersection entre un rayon et une sphere il faut resoudre
// une equation du second degre dont les paramatres a b et c sont
// a = D^2 = 1
// b = 2D . (O - C)
// c = |O - C|^2 - R^2
// une intersection n'est possible que quand le determinant de l'expression est positif
{
	double	determinant;
	t_quadratic	quadratic_params;

	find_values_of_quadratic_sphere(sphere, info, &quadratic);
	if (find_determinant(&quadratic))
		return (0);
	if (find_intersections_sphere(quadratic, list, sphere))
		return (1);
	return (0);
}

int	inter_plane(t_plane *plane, t_node **list, t_minirt *info)
//dans cette fonction utiliser un produit vectoriel pour s'assurer que le vecteur 
//de vision de la camera et le plan ne sont pas confondus (possiblement une infinite de 
//reponses possibles alors
//en plusieurs lignes il faut resoudre l'equation 
//t = (p2 . n - p1 . n) / (d . n)
//ou p1 est le point d'origine du rayon d le vecteur de direction du rayon 
//p2 est le point du plan et n la vecteur orthogonal au plan
{
	
	t_intersection	*inter;
	double		direc_plane;
	double		distance;

	direc_plane = dot_product_unnormed(info->current_ray.direction, *plane->normal_vector);
	if (direc_plane == 0)
		return (2);
	distance = dot_product_point_vec(*plane->coord, *plane->normal_vector); 
	distance -= dot_product_point_vec(info->current_ray.origin, info->current_ray.direction); 
	distance /= direc_plane;
	if (distance < 0)
		return (0);
	inter = malloc(sizeof(t_intersection));
	if (inter == NULL)
		return (1);
	inter->distance = distance;
	inter->point_color = *plane->color;
	add_object_to_list(list, (void *)inter);
	return (0); 
}

int	inter_cylinder(t_vector direction, t_cylinder *cylinder, t_node **list, t_minirt *info)
// l'equation generale pour modeliser un cylindre est 
// pour un cylindre de rayon r et oriente sur l'axe p + vt
// (q - p - (v . (q - p) v))^2 - r^2 = 0
// ou q est un point du cylindre
{
	printf("This function has not been implemented yet"\n);
	return (0);
}
