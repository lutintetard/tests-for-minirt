/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 18:20:00 by tparis            #+#    #+#             */
/*   Updated: 2026/06/24 18:10:54 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic.h"

static char	*append_file_content(char *file_content, char *buffer)
{
	char	*tmp;

	tmp = file_content;
	file_content = ft_strjoin(file_content, buffer);
	free(tmp);
	return (file_content);
}

static char	*read_file_buffer(int fd, char *buffer, char *file_content)
{
	int	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (!file_content)
			file_content = ft_strdup(buffer);
		else
			file_content = append_file_content(file_content, buffer);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (file_content);
}

char	*read_file(const char *filename)
{
	int		fd;
	char	*buffer;
	char	*file_content;

	fd = open(filename, O_RDONLY);
	file_content = NULL;
	if (fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		close(fd);
		return (NULL);
	}
	file_content = read_file_buffer(fd, buffer, file_content);
	free(buffer);
	close(fd);
	return (file_content);
}
