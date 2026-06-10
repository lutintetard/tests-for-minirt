/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:27:33 by tparis            #+#    #+#             */
/*   Updated: 2025/11/12 14:46:17 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *buf, int c, size_t count)
{
	size_t			i;
	unsigned char	*t;

	t = (unsigned char *)buf;
	i = 0;
	while (i < count)
	{
		if (*t == (unsigned char)c)
		{
			return ((void *)t);
		}
		i++;
		t++;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	const char	s[] = "justatest";
	char		c = 'i';
	int		l = 9;

	printf("memchr:		%p \n", memchr(s, c, l));
	printf("ft_memchr:	%p \n", ft_memchr(s, c, l));
	return (0);
}
*/
