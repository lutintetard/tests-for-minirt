/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:50:45 by tparis            #+#    #+#             */
/*   Updated: 2026/04/28 14:28:46 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_objects	*new_sphere(char **split)
{
	t_objects *object;
	t_sphere *sphere;
	
	if (nb_str(split) != 4)
		return (NULL);
	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->coord = parse_coord(split[1]);
	sphere->diameter = ft_atof(split[2]);
	sphere->color = parse_color(split[3]);
	if (!sphere->coord || !sphere->color)
	{
		free(sphere->coord);
		free(sphere->color);
		free(sphere);
		return (NULL);
	}

	object = malloc(sizeof(t_objects));
	if (!object)
	{
		free(sphere->coord);
		free(sphere->color);
		free(sphere);
		return (NULL);
	}
	object->object_type = SPHERE;
	object->object = sphere;
	return (object);
}

t_objects	*new_plane(char **split)
{
	t_objects	*object;
	t_plane 	*plane;
	
	if (nb_str(split) != 4)
		return (NULL);
	plane = malloc(sizeof(t_plane));
	if (!plane)
		return (NULL);
	plane->coord = parse_coord(split[1]);
	plane->normal_vector = parse_vector(split[2]);
	plane->color = parse_color(split[3]);
	if (!plane->coord || !plane->normal_vector || !plane->color)
	{
		free(plane->coord);
		free(plane->normal_vector);
		free(plane->color);
		free(plane);
		return (NULL);
	}

	object = malloc(sizeof(t_objects));
	if (!object)
	{
		free(plane->coord);
		free(plane->normal_vector);
		free(plane->color);
		free(plane);
		return (NULL);
	}
	object->object_type = PLANE;
	object->object = plane;
	return (object);
}

t_objects	*new_cylinder(char **split)
{
	t_objects	*object;
	t_cylinder *cylinder;
	
	if (nb_str(split) != 6)
		return (NULL);
	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		return (NULL);
	cylinder->coord = parse_coord(split[1]);
	cylinder->axis_vector = parse_vector(split[2]);
	cylinder->diameter = ft_atof(split[3]);
	cylinder->height = ft_atof(split[4]);
	cylinder->color = parse_color(split[5]);
	if (!cylinder->coord || !cylinder->axis_vector || !cylinder->color)
	{
		free(cylinder->coord);
		free(cylinder->axis_vector);
		free(cylinder->color);
		free(cylinder);
		return (NULL);
	}

	object = malloc(sizeof(t_objects));
	if (!object)
	{
		free(cylinder->coord);
		free(cylinder->axis_vector);
		free(cylinder->color);
		free(cylinder);
		return (NULL);
	}
	object->object_type = CYLINDER;
	object->object = cylinder;
	return (object);
}