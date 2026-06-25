/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:33:03 by tparis            #+#    #+#             */
/*   Updated: 2025/11/12 11:42:11 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *pointer, int value, size_t count)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = pointer;
	while (i < count)
	{
		*ptr = value;
		i++;
		ptr++;
	}
	return (pointer);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	str1[] = "test";
	char    str2[] = "test";
	char    c = '1';
	int	l = 4;
	
	memset(str1, c, l);
	printf("memset: %s\n", str1);
	ft_memset(str2, c, l);
	printf("ft_memset: %s\n", str2);
	return (0);
}
*/
