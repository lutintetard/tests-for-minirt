/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:57:40 by tparis            #+#    #+#             */
/*   Updated: 2026/04/28 15:13:58 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void free_strs(char **strs)
{
	if (!strs)
		return;

	for (int i = 0; strs[i]; i++)
		free(strs[i]);
	free(strs);
}

void	free_sphere(t_sphere *sphere)
{
	free(sphere->color);
	free(sphere->coord);
	free(sphere);
}

void	free_plane(t_plane *plane)
{
	free(plane->coord);
	free(plane->normal_vector);
	free(plane->color);
	free(plane);
}

void	free_cylinder(t_cylinder *cylinder)
{
	free(cylinder->coord);
	free(cylinder->axis_vector);
	free(cylinder->color);
	free(cylinder);
}

void	free_camera(t_camera *camera)
{
	free(camera->coord);
	free(camera->orientation_vector);
	free(camera);
}

void	free_light(t_light	*light)
{
	free(light->coord);
	free(light->color);
	free(light);
}

void	free_ambient(t_ambient *ambient)
{
	free(ambient->color);
	free(ambient);
}

void	free_objects_list(t_node *object_list)
{
	t_node		*tmp;
	t_node		*next;
	t_objects	*obj;

	tmp = object_list;
	while (tmp)
	{
		obj = tmp->structure;
		if (obj->object_type == SPHERE)
			free_sphere(obj->object);
		else if (obj->object_type == PLANE)
			free_plane(obj->object);
		else if (obj->object_type == CYLINDER)
			free_cylinder(obj->object);
		else if (obj->object_type == CAM)
			free_camera(obj->object);
		else if (obj->object_type == LIGHT)
			free_light(obj->object);
		else if (obj->object_type == AMBIENT)
			free_ambient(obj->object);
		free(obj);
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}