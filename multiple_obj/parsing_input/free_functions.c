/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 17:49:31 by tparis            #+#    #+#             */
/*   Updated: 2026/06/25 14:33:41 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	free_scene(t_node *scene, int free_obj)
{
	t_node	*tmp;

	while (scene)
	{
		tmp = scene;
		scene = scene->next;
		if (free_obj)
			free(tmp->obj);
		free(tmp);
	}
}
