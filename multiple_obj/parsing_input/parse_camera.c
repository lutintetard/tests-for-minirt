/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 12:30:37 by tparis            #+#    #+#             */
/*   Updated: 2026/06/24 17:30:41 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic.h"

t_node	*parse_camera(const char *line)
{
	char		**tokens;
	t_camera	*camera;
	t_node		*node;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (NULL);
	camera = malloc(sizeof(t_camera));
	if (!camera)
		return (free_split(tokens), NULL);
	camera->coord = parse_coord(tokens[1]);
	camera->orientation_vector = convert_coord_to_vector\
(parse_coord(tokens[2]));
	camera->fov = ft_atof(tokens[3]);
	camera->right = (t_vector){0, 0, 0};
	camera->up = (t_vector){0, 0, 0};
	node = malloc(sizeof(t_node));
	if (!node)
		return (free(camera), free_split(tokens), NULL);
	node->name = CAM;
	node->obj = camera;
	node->next = NULL;
	free_split(tokens);
	return (node);
}

void	print_camera(t_camera *camera)
{
	printf("Camera:\n");
	printf("  Point: (%.2f, %.2f, %.2f)\n", camera->coord.x\
, camera->coord.y, camera->coord.z);
	printf("  Orientation: (%.2f, %.2f, %.2f)\n",
		camera->orientation_vector.x_axis,
		camera->orientation_vector.y_axis,
		camera->orientation_vector.z_axis);
	printf("  FOV: %.2f\n", camera->fov);
}

int	is_valid_camera(char *line, int nb_line, int nb_cam)
{
	char	**tokens;
	int		valid;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	valid = 1;
	if (!is_valid_vector(tokens[2]))
		valid = 0;
	if (ft_atof(tokens[3]) < 0 || ft_atof(tokens[3]) > 180)
		valid = 0;
	if (nb_cam > 1)
		valid = 0;
	if (valid == 0)
		printf("Invalid line [%d]: %s\n", nb_line, line);
	return (free_split(tokens), valid);
}
