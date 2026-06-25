/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:55:07 by tparis            #+#    #+#             */
/*   Updated: 2025/11/08 15:07:47 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

/*
#include <stdio.h>
#include <ctype.h>
int	main(int argc, char **argv)
{
	(void)argc;
	printf("tolower: %c\n", tolower(argv[1][0]));
	printf("ft_tolower: %c\n", ft_tolower(argv[1][0]));
}
*/
