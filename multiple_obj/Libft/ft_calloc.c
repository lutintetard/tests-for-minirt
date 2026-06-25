/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:40:46 by tparis            #+#    #+#             */
/*   Updated: 2025/11/14 11:44:30 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

void	*ft_calloc(size_t num, size_t size)
{
	size_t	i;
	char	*ptr;

	ptr = malloc(num * size);
	if (ptr == NULL)
		return (0);
	i = 0;
	while (i < num * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

/*
#include <stdio.h>
#define INT_NUMBER 2
int	main(void)
{
	int	*st = (int *) ft_calloc(INT_NUMBER, sizeof(int));
	int	i = 0;

	if (st == NULL)
		return (0);
	while (i < INT_NUMBER)
	{
		printf("%d", st[i]);
		i++;
	}
	printf("\n");
	return (0);
}
*/
