/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_offsets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournea <lfournea@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:22:51 by lfournea          #+#    #+#             */
/*   Updated: 2026/04/29 17:59:08 by lfournea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	find_offsets(int pixel, t_win_view win)
// dans cette fonction on determine les facteurs par lesquels il faut multiplier
// les vecteurs directionnels pour obtenir le bons rayons;
// pour des raisons de lisibilite peut etre plus intuitif compter avec des
// coordonnees negatives
{
	int	x_coor;
	int	y_coor;

	x_coor = pixel % WIN_WIDTH;
	y_coor = pixel / WIN_WIDTH;
	win.offset_right = (-1) * win.width + 2 * x_coor * win.pixel_size;
	win.offset_up = win.height - 2 * y_coor * win.pixel_size;
}
