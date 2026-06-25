/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:07:05 by tparis            #+#    #+#             */
/*   Updated: 2025/11/14 16:26:11 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_striteri(char const *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (*s)
	{
		f(i, (char *)s);
		i++;
		s++;
	}
}

/*
#include <stdio.h>
void	ft_nextalpha(unsigned int i, char *c)
{
	(void)i;

	if (*c == 'z')
		*c = 'a';
	else
		*c = *c + 1;
}

int	main(void)
{
	char	str[] = "abcz";

	ft_striteri(str, ft_nextalpha);
	printf("%s\n", str);
	return (0);
}
*/
