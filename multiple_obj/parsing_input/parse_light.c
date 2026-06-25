/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 11:54:19 by tparis            #+#    #+#             */
/*   Updated: 2026/06/24 17:29:42 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic.h"

t_node	*parse_light(const char *line)
{
	char	**tokens;
	t_light	*light;
	t_node	*node;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (NULL);
	light = malloc(sizeof(t_light));
	if (!light)
		return (free_split(tokens), NULL);
	light->coord = parse_coord(tokens[1]);
	light->bright_ratio = ft_atof(tokens[2]);
	light->color = rgb_to_uint(tokens[3]);
	node = malloc(sizeof(t_node));
	if (!node)
		return (free(light), free_split(tokens), NULL);
	node->name = LIGHT;
	node->obj = light;
	node->next = NULL;
	free_split(tokens);
	return (node);
}

void	print_light(t_light *light)
{
	printf("Light:\n");
	printf("  Point: (%.2f, %.2f, %.2f)\n", light->coord.x\
, light->coord.y, light->coord.z);
	printf("  Brightness: %.2f\n", light->bright_ratio);
	printf("  Color: #%06X\n", light->color & 0xFFFFFF);
}

int	is_valid_light(char *line, int nb_line, int nb_light)
{
	char	**tokens;
	int		valid;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	valid = 1;
	if (ft_strncmp(tokens[0], "L", 1) != 0 || !tokens[1] \
|| !tokens[2] || !tokens[3])
		valid = 0;
	else if (!is_valid_color(tokens[3]))
		valid = 0;
	else if (ft_atof(tokens[2]) <= 0.0 || ft_atof(tokens[2]) > 1.0)
		valid = 0;
	if (nb_light > 1)
		valid = 0;
	free_split(tokens);
	if (valid == 0)
		printf("Invalid line [%d]: %s\n", nb_line + 1, line);
	return (valid);
}
