/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:05:30 by tparis            #+#    #+#             */
/*   Updated: 2025/11/17 11:23:50 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t s)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (s == 0)
		return (src_len);
	i = 0;
	while ((i < s - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/*
#include <bsd/string.h>
#include <stdio.h>
int	main(void)
{
	char	dest1[] = "justatest";
	char	dest2[] = "justatest";
	char	src[] = "final";
	int	l = 5;
	int	i = 0;

	printf("strlcpy: %zu	",strlcpy(dest1, src, l));
	printf("ft_strlcpy: %zu\n", ft_strlcpy(dest2, src, l));
	while (i < 9)
	{
		printf("%c		%c\n", dest1[i], dest2[i]);
		i++;
	}
	return (0);
}
*/
