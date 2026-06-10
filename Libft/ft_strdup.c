/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:22:28 by tparis            #+#    #+#             */
/*   Updated: 2025/11/17 16:04:06 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	*ft_strdup(const char *str)
{
	char	*dest;
	int		i;

	dest = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	*src = "this is a normal test";
	char	*dest;

	dest = ft_strdup(src);
	if (!dest)
		return (0);
	printf("%s\n", dest);
	free(dest);
	return (0);
}
*/
