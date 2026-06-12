/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 13:55:03 by tparis            #+#    #+#             */
/*   Updated: 2025/11/08 14:15:17 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}

/*
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	(void)argc;
	printf("isalnum: %d\n", isalnum(argv[1][0]));
	printf("ft_isalnum: %d\n", ft_isalnum(argv[1][0]));
}
*/
