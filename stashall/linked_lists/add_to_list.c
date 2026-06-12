/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournea <lfournea@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 15:24:50 by lfournea          #+#    #+#             */
/*   Updated: 2026/04/30 15:35:32 by lfournea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

int	add_to_list(t_node **list, void *structure)
{
	t_node	*first;
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (1);
	new_node->structure = structure;
	new_node->next = NULL;
	first = *list;
	if (first == NULL)
	{
		*list = new_node;
		return (0);
	}
	while (first->next)
		first = first->next;
	first->next = new_node;
	return (0);	
}
