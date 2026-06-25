/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:55:07 by tparis            #+#    #+#             */
/*   Updated: 2025/11/08 15:05:52 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

/*
#include <stdio.h>
#include <ctype.h>
int	main(int argc, char **argv)
{
	(void)argc;
	printf("toupper: %c\n", toupper(argv[1][0]));
	printf("ft_toupper: %c\n", ft_toupper(argv[1][0]));
}
*/
