/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparis <tparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:44:57 by tparis            #+#    #+#             */
/*   Updated: 2026/04/24 17:32:08 by tparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_verify_and_join(char *tmp, char *buff)
{
	char		*keep;
	ssize_t		len;

	keep = NULL;
	len = 0;
	if (tmp)
	{
		keep = ft_strdup(tmp);
		free (tmp);
		len = ft_strlen(keep) + ft_strlen(buff);
		tmp = malloc(len + 1);
		if (!tmp)
			return (NULL);
		ft_memcpy(tmp, keep, ft_strlen(keep));
		tmp[ft_strlen(keep)] = '\0';
		ft_memcpy(ft_strchr(tmp, '\0'), buff, ft_strlen(buff));
		tmp[len] = '\0';
		free(keep);
	}
	else if (!tmp)
		tmp = ft_strdup(buff);
	return (tmp);
}

void	ft_extract(char **tmp)
{
	char	*keep;

	keep = ft_strdup(ft_strchr(*tmp, '\n') + 1);
	free(*tmp);
	*tmp = keep;
}

char	*ft_return_line(char **tmp, char **buff, ssize_t readed)
{
	char	*line;
	int		calc;

	line = NULL;
	if (*tmp && **tmp && readed == 0)
	{
		line = ft_strdup(*tmp);
		free(*tmp);
		*tmp = NULL;
		free(*buff);
		*buff = NULL;
		return (line);
	}
	if (ft_strchr(*tmp, '\n'))
	{
		calc = ft_strlen(*tmp) - ft_strlen(ft_strchr(*tmp, '\n')) + 1;
		line = ft_substr(*tmp, 0, calc);
		ft_extract(tmp);
		return (line);
	}
	free(*tmp);
	*tmp = NULL;
	free(*buff);
	*buff = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*buff;
	ssize_t		readed;

	buff = NULL;
	readed = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (readed != 0)
	{
		if ((ft_strchr(tmp, '\n') != NULL))
			return (ft_return_line(&tmp, &buff, readed));
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed <= 0)
			break ;
		buff[readed] = '\0';
		tmp = ft_verify_and_join(tmp, buff);
		free(buff);
		buff = NULL;
	}
	return (ft_return_line(&tmp, &buff, readed));
}
