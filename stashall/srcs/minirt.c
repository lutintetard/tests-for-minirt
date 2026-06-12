/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:38:39 by tparis            #+#    #+#             */
/*   Updated: 2026/06/10 14:32:30 by lfournea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>
# include <X11/keysym.h>

/*
int	input_key(int keysym, t_minirt *minirt)
{
	if (keysym == XK_Escape)
		close_win(minirt);
	return (0);
}

int	main(int argc, char **argv)
{
	t_minirt	minirt;
	t_node		**shape_list;
	
	if (argc != 2)
		exit_msg("put ONE filename as arg\n", 1);
	shape_list = parse_file(argv[1]);
	if (!shape_list)
		exit_msg("Error parsing scene file\n", 1);
	print_list_objects(*shape_list);
	free_objects_list(*shape_list);
	free(shape_list);
	minirt.mlx = mlx_init();
	if (!minirt.mlx)
		exit_msg("Error creating mlx\n", 1);
	minirt.win = mlx_new_window(minirt.mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
	if (!minirt.win)
		exit_msg("Error creating window\n", 1);
	printf("test\n");
	minirt.img = mlx_new_image(minirt.mlx, WIN_WIDTH, WIN_HEIGHT);	
	if (minirt.img == NULL)
		return (1);
	//mlx_key_hook(minirt.win, (void *)input_key, &minirt);
	mlx_hook(minirt.win, 17, 0, (void *)close_win, &minirt);
	mlx_loop(minirt.mlx);
	return (0);
}
*/

int	main(void)
//fonction experimentale pour tester une unique figure
{
	t_minirt	minirt;
	
	minirt.mlx = mlx_init();
	if (!minirt.mlx)
		exit_msg("Error creating mlx\n", 1);
	minirt.win = mlx_new_window(minirt.mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
	if (!minirt.win)
		exit_msg("Error creating window\n", 1);
	printf("test\n");
	minirt.img = mlx_new_image(minirt.mlx, WIN_WIDTH, WIN_HEIGHT);	
	if (minirt.img == NULL)
		return (1);
	mlx_hook(minirt.win, 17, 0, (void *)close_win, &minirt);
	mlx_loop(minirt.mlx);
	return (0);
}
