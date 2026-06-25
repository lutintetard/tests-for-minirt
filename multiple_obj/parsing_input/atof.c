/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 18:00:00 by tparis            #+#    #+#             */
/*   Updated: 2026/06/24 18:10:54 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic.h"

static void	skip_whitespace(const char **str)
{
	while (**str == ' ' || **str == '\t' || **str == '\n'
		|| **str == '\r' || **str == '\f' || **str == '\v')
		(*str)++;
}

static int	parse_atof_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

static double	parse_atof_decimal(const char **str)
{
	double	decimal;
	double	result;

	result = 0.0;
	decimal = 0.1;
	while (**str >= '0' && **str <= '9')
	{
		result = result + decimal * (**str - '0');
		decimal *= 0.1;
		(*str)++;
	}
	return (result);
}

double	ft_atof(const char *str)
{
	double	result;
	double	decimal;
	int		sign;

	result = 0.0;
	if (!str)
		return (0.0);
	skip_whitespace(&str);
	sign = parse_atof_sign(&str);
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	decimal = 0.0;
	if (*str == '.')
	{
		str++;
		decimal = parse_atof_decimal(&str);
	}
	return ((result + decimal) * sign);
}
