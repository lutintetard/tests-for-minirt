/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:28:17 by tparis            #+#    #+#             */
/*   Updated: 2025/11/12 16:15:39 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*t;

	t = (unsigned char *)s;
	while (n > 0)
	{
		*t = '\0';
		t++;
		n--;
	}
}

/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	str1[] = "justatest";
	char	str2[] = "justatest";
	int	len = 9;
	int	st = 3;
	int	en = 2;
	int	i = 0;

	bzero(str1 + st, en);
	ft_bzero(str2 + st, en);

	printf("bzero:	ft_bzero:\n");
	while (i < len)
	{
		printf("%c	%c\n", str1[i], str2[i]);
		i++;
	}
	return (0);
}
*/
