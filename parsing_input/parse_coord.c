/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 12:56:13 by tparis            #+#    #+#             */
/*   Updated: 2026/06/24 17:56:49 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic.h"

static float	parse_coord_value(const char **str)
{
	float	value;

	value = ft_atof(*str);
	if (**str == '-' || **str == '+')
		(*str)++;
	while ((**str >= '0' && **str <= '9') || **str == '.')
		(*str)++;
	return (value);
}

static int	is_coord_char(char c)
{
	return ((c >= '0' && c <= '9') || c == '.' || c == '-' || c == '+');
}

t_coord	parse_coord(const char *str)
{
	t_coord	coord;

	coord.x = 0.0f;
	coord.y = 0.0f;
	coord.z = 0.0f;
	if (is_coord_char(*str))
		coord.x = parse_coord_value(&str);
	if (*str == ',')
		str++;
	if (is_coord_char(*str))
		coord.y = parse_coord_value(&str);
	if (*str == ',')
		str++;
	if (is_coord_char(*str))
		coord.z = parse_coord_value(&str);
	return (coord);
}

void	print_coord(t_coord coord)
{
	printf("Coord: (%.2f, %.2f, %.2f)\n", coord.x, coord.y, coord.z);
}

int	is_valid_vector(char *str)
{
	char	**tokens;
	int		i;

	tokens = ft_split(str, ',');
	if (!tokens)
		return (0);
	i = 0;
	while (tokens[i])
	{
		if (ft_atof(tokens[i]) < -1.0 || ft_atof(tokens[i]) > 1.0)
			return (free_split(tokens), 0);
		i++;
	}
	free_split(tokens);
	if (i != 3)
		return (0);
	return (1);
}
