/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:06:48 by tparis            #+#    #+#             */
/*   Updated: 2025/11/17 16:40:27 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	char	*tdest;
	char	*tsrc;
	size_t	i;

	if ((!dest && !src) || (size == 0))
		return (dest);
	i = 0;
	tdest = dest;
	tsrc = (void *)src;
	while (i < size)
	{
		tdest[i] = tsrc[i];
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	str1[] = "justatest";
	char	str2[] = "justatest";
	char	str3[] = "final";
	int	l = 5;

	memcpy(str1, str3, l);
	printf("memcpy: %s\n", str1);
	ft_memcpy(str2, str3, l);
	printf("ft_memcpy: %s\n", str2);
}
*/
