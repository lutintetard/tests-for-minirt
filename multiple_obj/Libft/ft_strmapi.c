/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:31:26 by tparis            #+#    #+#             */
/*   Updated: 2025/11/17 11:56:10 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dest;
	size_t	i;

	dest = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
#include <stdio.h>
char	ft_nextalpha(unsigned int i, char c)
{
	(void)i;

	if (c == 'z')
		return ('a');
	return (c + 1);
}

int	main(void)
	{
	char	*str = ft_strmapi("abcz", ft_nextalpha);

	if (!str)
		return (0);
	printf("%s\n", str);
	free(str);
	return (0);
}
*/
