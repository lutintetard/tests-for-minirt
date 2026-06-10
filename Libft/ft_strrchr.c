/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:10:21 by tparis            #+#    #+#             */
/*   Updated: 2025/11/17 15:39:23 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*r;

	r = 0;
	while (*s)
	{
		if ((char)c == *s)
			r = (char *)s;
		s++;
	}
	if ((char)c == 0)
		return ((char *)s);
	return (r);
}

/*
#include <stdio.h>
#include <string.h>
int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	printf("strrchr: %s\n", strrchr(argv[1], argv[2][0]));
	printf("ft_strrchr: %s\n", ft_strrchr(argv[1], argv[2][0]));
}
*/
