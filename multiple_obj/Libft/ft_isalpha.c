/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 13:55:03 by tparis            #+#    #+#             */
/*   Updated: 2025/11/08 14:07:17 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
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
	printf("isalpha: %d\n", isalpha(argv[1][0]));
	printf("ft_isalpha: %d\n", ft_isalpha(argv[1][0]));
}
*/
