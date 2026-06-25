/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:12:11 by tparis            #+#    #+#             */
/*   Updated: 2025/11/17 16:56:15 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static size_t	ft_strlcpy(char *dst, const char *src, size_t s)
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

static int	ft_isin(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
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

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*dest;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_isin(s1[start], set) && s1[start])
		start++;
	if (start >= (int)ft_strlen(s1))
	{
		dest = (char *)malloc(1 * sizeof(char));
		if (!dest)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	while (ft_isin(s1[end], set))
		end--;
	dest = (char *)malloc((end - start + 2) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1 + start, end - start + 2);
	return (dest);
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	(void)argc;
	char	*str = ft_strtrim(argv[1], argv[2]);

	if(!str)
		return (0);
	printf("%s\n", str);
	free(str);
	return (0);
}
*/
