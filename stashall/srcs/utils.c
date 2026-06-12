/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:48:58 by tparis            #+#    #+#             */
/*   Updated: 2026/04/28 15:11:40 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	exit_msg(char *msg, int code)
{
	ft_putstr_fd(msg, 1);
	exit(code);
}

void	free_minirt(t_minirt *minirt)
{
	mlx_destroy_window(minirt->mlx, minirt->win);
	mlx_destroy_display(minirt->mlx);
	free(minirt->mlx);
}

int	close_win(t_minirt *minirt)
{
	free_minirt(minirt);
	exit(0);
	return (0);
}
