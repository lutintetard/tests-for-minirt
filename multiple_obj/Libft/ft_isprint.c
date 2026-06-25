/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 13:55:03 by tparis            #+#    #+#             */
/*   Updated: 2025/11/08 14:34:30 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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
	printf("isprint: %d\n", isprint(argv[1][0]));
	printf("ft_isprint: %d\n", ft_isprint(argv[1][0]));
}
*/
