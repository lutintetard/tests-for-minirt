/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:41:00 by tparis            #+#    #+#             */
/*   Updated: 2025/11/17 22:55:12 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

static int	ft_countdigit(int nb)
{
	int	count;

	if (nb == -2147483648)
		return (11);
	count = 0;
	if (nb < 0)
	{
		count++;
		nb = nb * -1;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		count++;
	}
	count++;
	return (count);
}

char	*ft_itoa(int n)
{
	int		sizen;
	char	*dest;
	int		t;

	t = n;
	sizen = ft_countdigit(n);
	dest = (char *)malloc(sizen + 1 * sizeof(char));
	if (!dest)
		return (NULL);
	dest[sizen--] = '\0';
	while (sizen >= 0)
	{
		dest[sizen--] = ft_abs(t % 10) + '0';
		t = t / 10;
	}
	if (n < 0)
		dest[0] = '-';
	return (dest);
}

/*
#include <stdio.h>
int	main(void)
{
	char	*dest = ft_itoa(-2147483648);
	if (!dest)
		return (0);
	printf("%s\n", dest);
	free(dest);
	return (0);
}
*/
