/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 12:18:38 by tparis            #+#    #+#             */
/*   Updated: 2026/06/24 18:29:56 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic.h"

t_node	*new_node(char	*line)
{
	t_node	*node;

	if (ft_strncmp(line, "sp ", 3) == 0)
		node = parse_sphere(line);
	else if (ft_strncmp(line, "pl ", 3) == 0)
		node = parse_plane(line);
	else if (ft_strncmp(line, "cy ", 3) == 0)
		node = parse_cylinder(line);
	else if (ft_strncmp(line, "L ", 2) == 0)
		node = parse_light(line);
	else if (ft_strncmp(line, "A ", 2) == 0)
		node = parse_ambient(line);
	else if (ft_strncmp(line, "C ", 2) == 0)
		node = parse_camera(line);
	return (node);
}

t_node	*parse_lines(char *file_content)
{
	t_node	*scene;
	t_node	*node;
	char	**lines;
	int		i;

	scene = NULL;
	lines = ft_split(file_content, '\n');
	if (!lines)
		return (NULL);
	if (scan_lines(lines) == 0)
		return (free_split(lines), NULL);
	i = -1;
	while (lines[++i])
	{
		node = new_node(lines[i]);
		if (node)
		{
			if (!scene)
				scene = node;
			else
				add_node(scene, node);
		}
	}
	return (free_split(lines), scene);
}

t_node	*parse_scene(const char *filename)
{
	t_node	*scene;
	char	*file_content;

	scene = NULL;
	file_content = read_file(filename);
	if (DEBUG)
		printf("File content:\n%s\n", file_content);
	if (!file_content)
		return (NULL);
	scene = parse_lines(file_content);
	free(file_content);
	return (scene);
}
