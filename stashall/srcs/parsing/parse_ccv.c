/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ccv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:27:48 by tparis            #+#    #+#             */
/*   Updated: 2026/04/27 16:24:08 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_coord *parse_coord(char *str)
{
	char	**split;
	t_coord	*coord;

	split = ft_split(str, ',');
	if (nb_str(split) != 3)
	{
		free_strs(split);
		return (NULL);
	}
	coord = malloc(sizeof(t_coord));
	if (!coord)
	{
		free_strs(split);
		return (NULL);
	}
	coord->x = ft_atof(split[0]);
	coord->y = ft_atof(split[1]);
	coord->z = ft_atof(split[2]);
	free_strs(split);
	return (coord);
}

t_color *parse_color(char *str)
{
	char	**split;
	t_color	*color;

	split = ft_split(str, ',');
	if (nb_str(split) != 3)
	{
		free_strs(split);
		return (NULL);
	}
	color = malloc(sizeof(t_color));
	if (!color)
	{
		free_strs(split);
		return (NULL);
	}
	color->r = atoi(split[0]);
	color->g = atoi(split[1]);
	color->b = atoi(split[2]);
	free_strs(split);
	return (color);
}

t_vector *parse_vector(char *str)
{
	char	**split;
	t_vector	*vector;

	split = ft_split(str, ',');
	if (nb_str(split) != 3)
	{
		free_strs(split);
		return (NULL);
	}
	vector = malloc(sizeof(t_vector));
	if (!vector)
	{
		free_strs(split);
		return (NULL);
	}
	vector->x_axis = ft_atof(split[0]);
	vector->y_axis = ft_atof(split[1]);
	vector->z_axis = ft_atof(split[2]);
	free_strs(split);
	return (vector);
}