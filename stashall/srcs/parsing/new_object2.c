/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_object2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:30:14 by tparis            #+#    #+#             */
/*   Updated: 2026/04/28 14:28:31 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_objects	*new_ambient(char **split)
{
	t_objects *object;
	t_ambient *ambient;
	
	if (nb_str(split) != 3)
		return (NULL);
	ambient = malloc(sizeof(t_ambient));
	if (!ambient)
		return (NULL);
	ambient->ambient_light_ratio = ft_atof(split[1]);
	ambient->color = parse_color(split[2]);
	if (!ambient->color)
	{
		free(ambient->color);
		free(ambient);
		return (NULL);
	}

	object = malloc(sizeof(t_objects));
	if (!object)
	{
		free(ambient->color);
		free(ambient);
		return (NULL);
	}
	object->object_type = AMBIENT;
	object->object = ambient;
	return (object);
}

t_objects	*new_light(char **split)
{
	t_objects *object;
	t_light *light;
	
	if (nb_str(split) != 4)
		return (NULL);
	light = malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	light->coord = parse_coord(split[1]);
	light->bright_ratio = ft_atof(split[2]);
	light->color = parse_color(split[3]);
	if (!light->coord || !light->color)
	{
		free(light->coord);
		free(light->color);
		free(light);
		return (NULL);
	}

	object = malloc(sizeof(t_objects));
	if (!object)
	{
		free(light->coord);
		free(light->color);
		free(light);
		return (NULL);
	}
	object->object_type = LIGHT;
	object->object = light;
	return (object);
}

t_objects	*new_camera(char **split)
{
	t_objects *object;
	t_camera *camera;
	
	if (nb_str(split) != 4)
		return (NULL);
	camera = malloc(sizeof(t_camera));
	if (!camera)
		return (NULL);
	camera->coord = parse_coord(split[1]);
	camera->orientation_vector = parse_vector(split[2]);
	camera->fov = atoi(split[3]);
	if (!camera->coord || !camera->orientation_vector)
	{
		free(camera->coord);
		free(camera->orientation_vector);
		free(camera);
		return (NULL);
	}

	object = malloc(sizeof(t_objects));
	if (!object)
	{
		free(camera->coord);
		free(camera->orientation_vector);
		free(camera);
		return (NULL);
	}
	object->object_type = CAM;
	object->object = camera;
	return (object);
}