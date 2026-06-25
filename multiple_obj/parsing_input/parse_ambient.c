/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:04:03 by tparis            #+#    #+#             */
/*   Updated: 2026/06/24 17:18:11 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic.h"

t_node	*parse_ambient(const char *line)
{
	char		**tokens;
	t_ambient	*ambient;
	t_node		*node;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (NULL);
	ambient = malloc(sizeof(t_ambient));
	if (!ambient)
		return (free(tokens), NULL);
	ambient->bright_ratio = ft_atof(tokens[1]);
	ambient->color = rgb_to_uint(tokens[2]);
	node = malloc(sizeof(t_node));
	if (!node)
		return (free(ambient), free_split(tokens), NULL);
	node->name = AMBIENT;
	node->obj = ambient;
	node->next = NULL;
	free_split(tokens);
	return (node);
}

void	print_ambient(t_ambient *ambient)
{
	printf("Ambient:\n");
	printf("  Brightness: %.2f\n", ambient->bright_ratio);
	printf("  Color: #%06X\n", ambient->color & 0xFFFFFF);
}

int	is_valid_ambient(char *line, int nb_line, int nb_ambient)
{
	char	**tokens;
	int		valid;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	valid = 1;
	if (ft_atof(tokens[1]) < 0.0 || ft_atof(tokens[1]) > 1.0)
		valid = 0;
	if (!is_valid_color(tokens[2]))
		valid = 0;
	if (nb_ambient > 1)
		valid = 0;
	if (valid == 0)
		printf("Invalid line [%d]: %s\n", nb_line, line);
	return (free_split(tokens), valid);
}
