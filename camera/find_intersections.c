/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intersections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournea <lfournea@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:00:16 by tparis            #+#    #+#             */
/*   Updated: 2026/05/04 15:36:06 by lfournea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

int	analyse_current_object(t_node *object_to_analyse, t_node **list_intersections, t_minirt *info)
{
	t_objects	*object;
	int		return_value;

	return_value = 1;
	object = (t_objects *)object_to_analyse;
	if (object->object_type == SPHERE)
		return_value = inter_sphere((t_sphere *)object->object, list_intersections, info);
	else if (object->object_type == PLANE) 
		return_value = inter_plane((t_plane *)object->object, list_intersections, info);
	else if (object->object_type == CYLINDER)
		return_value = inter_cylinder((t_cylinder *)object->object, list_intersections, info);
	return (return_value);
}

int	find_intersections(t_node **objects, t_minirt *info)
{
	t_node	*current_object;

	current_object = info->objects;
	while (current_object)
	{
		analyse_current_object(current_object, objects, info);
		current_object = current_object->next;
	}			
}
