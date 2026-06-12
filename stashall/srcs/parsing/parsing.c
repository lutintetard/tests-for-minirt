/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournea <lfournea@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:52:47 by lfournea          #+#    #+#             */
/*   Updated: 2026/04/29 13:52:59 by lfournea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_objects	*select_object(char **split)
{
	t_objects	*new_objects;

	new_objects = NULL;
	if (ft_strncmp(split[0], "sp", 3) == 0)
		new_objects = new_sphere(split);
	else if (ft_strncmp(split[0], "pl", 3) == 0)
		new_objects = new_plane(split);
	else if (ft_strncmp(split[0], "cy", 3) == 0)
		new_objects = new_cylinder(split);
	else if (ft_strncmp(split[0], "A", 2) == 0)
		new_objects = new_ambient(split);
	else if (ft_strncmp(split[0], "L", 2) == 0)
		new_objects = new_light(split);
	else if (ft_strncmp(split[0], "C", 2) == 0)
		new_objects = new_camera(split);
	return (new_objects);
}

int	addline(char *line, t_node **shape_list)
{
	t_objects	*object;
	char		**split;

	split = ft_split(line, ' ');
	if (!split || !split[0])
		return (-1);
	object = select_object(split);
	free_strs(split);
	if (!object)
		return (-1);
	add_object_to_list(shape_list, object);
	return (0);
}

t_node **parse_file(char *path)
{
	t_node		**shape_list;
	char		*line;
	int			fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	shape_list = malloc(sizeof(t_node *));
	if (!shape_list)
	{
		close(fd);
		return (NULL);
	}
	*shape_list = NULL;
	line = get_next_line(fd);
	while (line)
	{
		//printf("line: %s", line);
		if (addline(line, shape_list) < 0)
		{
			free(line);
			close(fd);
			return (NULL);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (shape_list);
}
