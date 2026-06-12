/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:04:27 by tparis            #+#    #+#             */
/*   Updated: 2026/04/28 14:29:54 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../minirt.h"

int nb_str(char **strs)
{
    int i;

    if (!strs)
        return (0);

    i = 0;
    while (strs[i])
        i++;
    return (i);
}

int is_in_list(char *str, char **list)
{
    if (!str || !list)
 		return 0;

    for (int i = 0; list[i]; i++)
    {
        if (strcmp(str, list[i]) == 0)
            return 1;
    }
    return 0;
}

void add_object_to_list(t_node **list, t_objects *new_object)
{
	t_node	*new_node;

	if (!list || !new_object)
		return;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->structure = new_object;
	new_node->next = *list;
	*list = new_node;
}

float	ft_atof(const char *str)
{
	int		sign;
	float	result;
	float	fraction;

	sign = 1;
	result = 0.0f;
	fraction = 0.1f;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;

	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;

	while (ft_isdigit(*str))
	{
		result = result * 10.0f + (*str - '0');
		str++;
	}

	if (*str == '.')
	{
		str++;
		while (ft_isdigit(*str))
		{
			result = result + (*str - '0') * fraction;
			fraction *= 0.1f;
			str++;
		}
	}

	return (result * sign);
}