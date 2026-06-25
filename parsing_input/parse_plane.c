/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 16:20:00 by tparis            #+#    #+#             */
/*   Updated: 2026/06/24 17:32:06 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic.h"

t_node	*parse_plane(const char *line)
{
	char	**tokens;
	t_plane	*plane;
	t_node	*node;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (NULL);
	plane = malloc(sizeof(t_plane));
	if (!plane)
		return (free_split(tokens), NULL);
	plane->coord = parse_coord(tokens[1]);
	plane->normal_vector = convert_coord_to_vector(parse_coord(tokens[2]));
	plane->color = rgb_to_uint(tokens[3]);
	node = malloc(sizeof(t_node));
	if (!node)
		return (free(plane), free_split(tokens), NULL);
	node->name = PLANE;
	node->obj = plane;
	node->next = NULL;
	free_split(tokens);
	return (node);
}

void	print_plane(t_plane *plane)
{
	printf("Plane:\n");
	printf("  Point: (%.2f, %.2f, %.2f)\n", plane->coord.x\
, plane->coord.y, plane->coord.z);
	printf("  Normal: (%.2f, %.2f, %.2f)\n",
		plane->normal_vector.x_axis,
		plane->normal_vector.y_axis,
		plane->normal_vector.z_axis);
	printf("  Color: #%06X\n", plane->color & 0xFFFFFF);
}

int	is_valid_plane(char *line, int nb_line)
{
	char	**tokens;
	int		valid;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	valid = 1;
	if (ft_strncmp(tokens[0], "pl", 2) != 0 || !tokens[1] \
|| !tokens[2] || !tokens[3])
		valid = 0;
	else if (!is_valid_color(tokens[3]))
		valid = 0;
	else if (!is_valid_vector(tokens[2]))
		valid = 0;
	free_split(tokens);
	if (valid == 0)
		printf("Invalid line [%d]: %s\n", nb_line, line);
	return (valid);
}
