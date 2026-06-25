/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:16:13 by tparis            #+#    #+#             */
/*   Updated: 2026/06/24 17:16:24 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic.h"

int	apply_ambient_to_sphere(t_node *sphere_node, t_ambient *ambient)
{
	t_sphere	*sphere;

	if (!sphere_node || !ambient)
		return (0);
	sphere = (t_sphere *)sphere_node->obj;
	sphere->color = calculate_color(sphere->color\
, ambient->color, ambient->bright_ratio);
	return (1);
}

int	apply_ambient_to_plane(t_node *plane_node, t_ambient *ambient)
{
	t_plane	*plane;

	if (!plane_node || !ambient)
		return (0);
	plane = (t_plane *)plane_node->obj;
	plane->color = calculate_color(plane->color\
, ambient->color, ambient->bright_ratio);
	return (1);
}

int	apply_ambient_to_cylinder(t_node *cylinder_node, t_ambient *ambient)
{
	t_cylinder	*cylinder;

	if (!cylinder_node || !ambient)
		return (0);
	cylinder = (t_cylinder *)cylinder_node->obj;
	cylinder->color = calculate_color(cylinder->color\
, ambient->color, ambient->bright_ratio);
	return (1);
}

int	apply_ambient(t_node *scene, t_ambient *ambient)
{
	t_node	*tmp;

	tmp = scene;
	while (tmp)
	{
		if (tmp->name == SPHERE)
			apply_ambient_to_sphere(tmp, ambient);
		else if (tmp->name == PLANE)
			apply_ambient_to_plane(tmp, ambient);
		else if (tmp->name == CYL)
			apply_ambient_to_cylinder(tmp, ambient);
		tmp = tmp->next;
	}
	return (1);
}
