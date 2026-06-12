/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:39:33 by tparis            #+#    #+#             */
/*   Updated: 2025/11/12 16:06:31 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static size_t	ft_strlen(const char *s)
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

size_t	ft_strlcat(char *dst, const char *src, size_t s)
{
	size_t	i;
	size_t	dstlen;

	i = 0;
	dstlen = ft_strlen(dst);
	if (s <= dstlen)
		return (s + ft_strlen(src));
	while (src[i] && (dstlen + i < s - 1))
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + ft_strlen(src));
}

/*
#include <bsd/string.h>
#include <stdio.h>
int	main(void)
{
	char	dest1[] = "justatest";
	char	dest2[] = "justatest";
	char	src[] = "final";
	int	l = 16;

	printf("strlcat:	%s (%zu)\n", dest1, strlcat(dest1, src, l));
	printf("ft_strlcat:	%s (%zu)\n", dest2, ft_strlcat(dest2, src, l));
	return (0);
}
*/
