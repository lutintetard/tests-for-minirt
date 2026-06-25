/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 12:45:52 by tparis            #+#    #+#             */
/*   Updated: 2026/06/24 17:26:06 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic.h"

unsigned int	rgb_to_uint(const char *str)
{
	unsigned int	rgb[3];
	int				i;

	i = 0;
	rgb[0] = 0;
	rgb[1] = 0;
	rgb[2] = 0;
	while (*str && i < 3)
	{
		if (*str >= '0' && *str <= '9')
			rgb[i] = rgb[i] * 10 + (*str - '0');
		else if (*str == ',')
			i++;
		else
			return (0);
		str++;
	}
	if (i != 2)
		return (0);
	if (rgb[0] > 255 || rgb[1] > 255 || rgb[2] > 255)
		return (0);
	return ((0xFFu << 24)
		| (rgb[0] << 16)
		| (rgb[1] << 8)
		| rgb[2]);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	parse_number(const char **str)
{
	int	nb;

	nb = 0;
	if (!is_digit(**str))
		return (-1);
	while (is_digit(**str))
	{
		nb = nb * 10 + (**str - '0');
		(*str)++;
	}
	if (nb > 255)
		return (-1);
	return (nb);
}

int	is_valid_color(char *str)
{
	int	i;
	int	nb;

	i = 0;
	while (i < 3)
	{
		nb = parse_number((const char **)&str);
		if (nb == -1)
			return (0);
		if (i < 2)
		{
			if (*str != ',')
				return (0);
			str++;
		}
		i++;
	}
	if (*str != '\0')
		return (0);
	return (1);
}
