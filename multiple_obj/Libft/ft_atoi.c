/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:55:03 by tparis            #+#    #+#             */
/*   Updated: 2026/04/27 12:01:58 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	s;
	int	r;

	s = 1;
	r = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		s = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (ft_isdigit(*str))
	{
		r = r * 10;
		r = r + (*str - '0');
		str++;
	}
	return (r * s);
}

/*
#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char **argv)
{
	(void)argc;
	printf("atoi: %d\n", atoi(argv[1]));
	printf("ft_atoi: %d\n", ft_atoi(argv[1]));
}
*/
