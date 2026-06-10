/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:56:53 by tparis            #+#    #+#             */
/*   Updated: 2025/11/12 12:26:26 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	ft_strncmp(const char *s1, const char *s2, size_t l)
{
	while ((*s1 && *s2) && (*s1 == *s2) && --l)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

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

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	biglen;
	size_t	litlen;
	size_t	i;

	if (!*little)
		return ((char *)big);
	biglen = ft_strlen(big);
	litlen = ft_strlen(little);
	if ((litlen > biglen) || (litlen > len))
		return (0);
	i = 0;
	while (i <= len - litlen)
	{
		if (ft_strncmp(big, little, litlen) == 0)
			return ((char *)big);
		i++;
		big++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	char	*big = "justatest";
	char	*little = "at";
	int	l = 9;

	printf("strnstr: %s\n", strnstr(big, little, l));
	printf("ft_strnstr: %s\n", ft_strnstr(big, little, l));
	return (0);
}
*/
