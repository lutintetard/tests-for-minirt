/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:55:07 by tparis            #+#    #+#             */
/*   Updated: 2026/06/24 17:32:39 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic.h"

t_node	*parse_sphere(const char *line)
{
	char		**tokens;
	t_sphere	*sphere;
	t_node		*node;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (NULL);
	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (free_split(tokens), NULL);
	sphere->color = rgb_to_uint(tokens[3]);
	sphere->coord = parse_coord(tokens[1]);
	sphere->diameter = ft_atof(tokens[2]);
	node = malloc(sizeof(t_node));
	if (!node)
		return (free(sphere), free_split(tokens), NULL);
	node->name = SPHERE;
	node->obj = sphere;
	node->next = NULL;
	free_split(tokens);
	return (node);
}

void	print_sphere(t_sphere *sphere)
{
	printf("Sphere:\n");
	printf("  Center: (%.2f, %.2f, %.2f)\n", sphere->coord.x\
, sphere->coord.y, sphere->coord.z);
	printf("  Diameter: %.2f\n", sphere->diameter);
	printf("  Color: #%06X\n", sphere->color & 0xFFFFFF);
}

int	is_valid_sphere(char *line, int nb_line)
{
	char	**tokens;
	int		valid;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	valid = 1;
	if (ft_strncmp(tokens[0], "sp", 2) != 0 || !tokens[1] \
|| !tokens[2] || !tokens[3])
		valid = 0;
	else if (!is_valid_color(tokens[3]))
		valid = 0;
	else if (ft_atof(tokens[2]) <= 0.0)
		valid = 0;
	free_split(tokens);
	if (valid == 0)
		printf("Invalid line [%d]: %s\n", nb_line, line);
	return (valid);
}
