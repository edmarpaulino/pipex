/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:46:25 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/01 10:23:15 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

static int	is_line(char *buffer)
{
	while (*buffer)
	{
		if (*(buffer++) == '\n')
			return (1);
	}
	return (0);
}

static void	clean_static_buffer(char **static_buffer, char **new_static_buffer)
{
	free(*new_static_buffer);
	*new_static_buffer = NULL;
	*static_buffer = NULL;
}

static char	*get_line(char **static_buffer, char **line)
{
	size_t	line_len;
	char	*new_static_buffer;

	line_len = 0;
	new_static_buffer = NULL;
	while ((*static_buffer)[line_len] != '\n' \
			&& (*static_buffer)[line_len] != '\0')
		++line_len;
	if ((*static_buffer)[line_len] == '\n')
	{
		*line = ft_substr(*static_buffer, 0, (line_len + 1));
		new_static_buffer = ft_strdup(&(*static_buffer)[line_len + 1]);
	}
	else
		*line = ft_strdup(*static_buffer);
	free(*static_buffer);
	*static_buffer = new_static_buffer;
	if (**line == '\0')
	{
		free(*line);
		*line = NULL;
	}
	if (*new_static_buffer == '\0')
		clean_static_buffer(static_buffer, &new_static_buffer);
	return (*line);
}

static char	*read_file(int fd, char **buffer)
{
	static char	*static_buffer[OPEN_MAX];
	char		*line;
	char		*temp;
	ssize_t		n;

	n = 1;
	if (!static_buffer[fd])
		static_buffer[fd] = ft_strdup("");
	while (!is_line(static_buffer[fd]) && n)
	{
		n = read(fd, *buffer, BUFFER_SIZE);
		if (n < 0)
		{
			free(buffer);
			free(static_buffer[fd]);
			return (NULL);
		}
		(*buffer)[n] = '\0';
		temp = static_buffer[fd];
		static_buffer[fd] = ft_strjoin(temp, *buffer);
		free(temp);
	}
	free(*buffer);
	*buffer = NULL;
	return (get_line(&static_buffer[fd], &line));
}

char	*get_next_line(int fd)
{
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(*buffer));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	return (read_file(fd, &buffer));
}
