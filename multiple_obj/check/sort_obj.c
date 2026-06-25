/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 14:15:01 by tparis            #+#    #+#             */
/*   Updated: 2026/06/25 14:31:19 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic.h"

t_node *copy_node(t_node *src)
{
    t_node *new;

    new = malloc(sizeof(t_node));
    if (!new)
        return NULL;

    new->name = src->name;
    new->obj = src->obj;
    new->next = NULL;
    return new;
}

t_node *copy_list_obj(t_node *scene)
{
    t_node *new_list;
    t_node *tail;
    t_node *copy;

    new_list = NULL;
    tail = NULL;

    while (scene)
    {
        if (scene->name < 3)
        {
            copy = copy_node(scene);
            if (!copy)
                return new_list;

            if (!new_list)
            {
                new_list = copy;
                tail = copy;
            }
            else
            {
                tail->next = copy;
                tail = copy;
            }
        }
        scene = scene->next;
    }
    return new_list;
}