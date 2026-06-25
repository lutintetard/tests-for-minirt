/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 11:45:19 by tparis            #+#    #+#             */
/*   Updated: 2026/06/24 17:28:46 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic.h"

t_node	*parse_cylinder(const char *line)
{
	char		**tokens;
	t_cylinder	*cylinder;
	t_node		*node;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (NULL);
	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		return (free_split(tokens), NULL);
	cylinder->coord = parse_coord(tokens[1]);
	cylinder->axis_vector = convert_coord_to_vector(parse_coord(tokens[2]));
	cylinder->diameter = ft_atof(tokens[3]);
	cylinder->height = ft_atof(tokens[4]);
	cylinder->color = rgb_to_uint(tokens[5]);
	node = malloc(sizeof(t_node));
	if (!node)
		return (free(cylinder), free_split(tokens), NULL);
	node->name = CYL;
	node->obj = cylinder;
	node->next = NULL;
	free_split(tokens);
	return (node);
}

void	print_cylinder(t_cylinder *cylinder)
{
	printf("Cylinder:\n");
	printf("  Point: (%.2f, %.2f, %.2f)\n", cylinder->coord.x\
, cylinder->coord.y, cylinder->coord.z);
	printf("  Axis: (%.2f, %.2f, %.2f)\n",
		cylinder->axis_vector.x_axis,
		cylinder->axis_vector.y_axis,
		cylinder->axis_vector.z_axis);
	printf("  Diameter: %.2f\n", cylinder->diameter);
	printf("  Height: %.2f\n", cylinder->height);
	printf("  Color: #%06X\n", cylinder->color & 0xFFFFFF);
}

int	is_valid_cylinder(char *line, int nb_line)
{
	char	**tokens;
	int		valid;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	valid = 1;
	if (ft_strncmp(tokens[0], "cy", 1) != 0 || !tokens[1] || !tokens[2] \
|| !tokens[3] || !tokens[4] || !tokens[5])
		valid = 0;
	else if (!is_valid_vector(tokens[2]))
		valid = 0;
	else if (!is_valid_color(tokens[5]))
		valid = 0;
	else if (ft_atof(tokens[3]) <= 0.0 || ft_atof(tokens[4]) <= 0.0)
		valid = 0;
	free_split(tokens);
	if (valid == 0)
		printf("Invalid line [%d]: %s\n", nb_line, line);
	return (valid);
}
