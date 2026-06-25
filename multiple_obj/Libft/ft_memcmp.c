/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:47:19 by tparis            #+#    #+#             */
/*   Updated: 2025/11/17 11:52:26 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *pt1, const void *pt2, size_t s)
{
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char *)pt1;
	t2 = (unsigned char *)pt2;
	while (s)
	{
		if (*t1 != *t2)
			return (*t1 - *t2);
		t1++;
		t2++;
		s--;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	st1[] = "test";
	char	st2[] = "tes1";
	int	l = 4;
	printf("memcmp:		%d\n", memcmp(st1, st2, l));
	printf("ft_memcmp:	%d\n", ft_memcmp(st1, st2, l));
	return (0);
}
*/
