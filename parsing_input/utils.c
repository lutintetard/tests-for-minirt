/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 12:37:58 by tparis            #+#    #+#             */
/*   Updated: 2026/06/24 18:12:00 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic.h"

void	add_node(t_node *scene, t_node *new_node)
{
	t_node	*current;

	current = scene;
	while (current->next)
		current = current->next;
	current->next = new_node;
}

static void	print_scene_object(t_node *scene)
{
	if (scene->name == SPHERE)
		print_sphere((t_sphere *)scene->obj);
	else if (scene->name == PLANE)
		print_plane((t_plane *)scene->obj);
	else if (scene->name == CYL)
		print_cylinder((t_cylinder *)scene->obj);
	else if (scene->name == LIGHT)
		print_light((t_light *)scene->obj);
	else if (scene->name == AMBIENT)
		print_ambient((t_ambient *)scene->obj);
	else if (scene->name == CAM)
		print_camera((t_camera *)scene->obj);
}

void	print_scene(t_node *scene)
{
	if (!scene)
		return ;
	while (scene)
	{
		print_scene_object(scene);
		scene = scene->next;
	}
}
