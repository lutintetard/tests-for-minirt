/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:29:45 by tparis            #+#    #+#             */
/*   Updated: 2026/06/24 16:55:36 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic.h"

static int	check_entity(char *line, int idx, int *count, int type)
{
	(*count)++;
	if (type == 0)
	{
		if (!is_valid_camera(line, idx, *count))
			return (0);
	}
	else if (type == 1)
	{
		if (!is_valid_ambient(line, idx, *count))
			return (0);
	}
	else
	{
		if (!is_valid_light(line, idx, *count))
			return (0);
	}
	return (1);
}

static int	check_shape(char *line, int idx)
{
	if (ft_strncmp(line, "sp ", 3) == 0)
	{
		if (!is_valid_sphere(line, idx))
			return (0);
	}
	else if (ft_strncmp(line, "pl ", 3) == 0)
	{
		if (!is_valid_plane(line, idx))
			return (0);
	}
	else if (ft_strncmp(line, "cy ", 3) == 0)
	{
		if (!is_valid_cylinder(line, idx))
			return (0);
	}
	return (1);
}

static int	process_line(char *line, int idx, int *nb_obj)
{
	if (ft_strncmp(line, "L ", 2) == 0)
		return (check_entity(line, idx, &nb_obj[2], 2));
	if (ft_strncmp(line, "A ", 2) == 0)
		return (check_entity(line, idx, &nb_obj[1], 1));
	if (ft_strncmp(line, "C ", 2) == 0)
		return (check_entity(line, idx, &nb_obj[0], 0));
	return (check_shape(line, idx));
}

int	scan_lines(char **lines)
{
	int	i;
	int	nb_obj[3];

	i = 0;
	nb_obj[0] = 0;
	nb_obj[1] = 0;
	nb_obj[2] = 0;
	while (lines[i] != NULL)
	{
		if (!process_line(lines[i], i, nb_obj))
			return (0);
		i++;
	}
	if (nb_obj[0] < 1 || nb_obj[1] < 1)
	{
		printf("Missing cam / ambient");
		return (0);
	}
	return (1);
}
