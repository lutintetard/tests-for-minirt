/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 13:55:03 by tparis            #+#    #+#             */
/*   Updated: 2025/11/08 14:30:03 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
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
	printf("isascii: %d\n", isascii(argv[1][0]));
	printf("ft_isascii: %d\n", ft_isascii(argv[1][0]));
}
*/
