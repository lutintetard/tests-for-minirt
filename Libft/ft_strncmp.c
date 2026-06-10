/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:11:35 by tparis            #+#    #+#             */
/*   Updated: 2025/11/17 11:38:56 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t l)
{
	if (l == 0)
		return (0);
	while ((*s1 && *s2) && (*s1 == *s2) && --l)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/*
#include <stdio.h>
#include <string.h>
int	main(int argc, char **argv)
{
	(void)argc;
	int	st;
	int	ftst;

	st = strncmp(argv[1], argv[2], 4);
	ftst = ft_strncmp(argv[1], argv[2], 4);
	printf("strcomp: %d\nft_strcmp: %d\n", st, ftst);
	return (0);
}
*/
