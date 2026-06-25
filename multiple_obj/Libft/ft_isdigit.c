/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 13:55:03 by tparis            #+#    #+#             */
/*   Updated: 2025/11/08 14:10:00 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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
	printf("isdigit: %d\n", isdigit(argv[1][0]));
	printf("ft_isdigit: %d\n", ft_isdigit(argv[1][0]));
}
*/
