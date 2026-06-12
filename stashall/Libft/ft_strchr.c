/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:10:21 by tparis            #+#    #+#             */
/*   Updated: 2026/04/27 12:34:01 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	alpha;

	if (!s)
		return (0);
	alpha = (char)(c);
	while (*s)
	{
		if (alpha == *s)
			return ((char *)s);
		s++;
	}
	if (alpha == 0)
		return ((char *)s);
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	printf("strchr: %s\n", strchr(argv[1], argv[2][0]));
	printf("ft_strchr: %s\n", ft_strchr(argv[1], argv[2][0]));
}
*/
