/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:35:13 by tparis            #+#    #+#             */
/*   Updated: 2025/11/12 10:13:06 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

/*
#include <stdio.h>
#include <string.h>
int	main(int argc, char **argv)
{
	(void)argc;
	printf("strlen: %lu\n", strlen(argv[1]));
	printf("ft_strlen: %lu\n", ft_strlen(argv[1]));
}
*/
