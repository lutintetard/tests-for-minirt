/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:12:17 by tparis            #+#    #+#             */
/*   Updated: 2026/06/24 16:59:42 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic.h"

t_node	*find_shape(t_node *shape_list, int type)
{
	t_node	*obj;

	if (!shape_list)
		return (NULL);
	obj = shape_list;
	while (obj && obj->name != type)
		obj = obj->next;
	return (obj);
}
