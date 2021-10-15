/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:43:22 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/13 12:14:01 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

/*
*	GET_NEXT_LINE
*
*	DESCRIPTION
*	Write a function which returns a line read from a
*	file descriptor.
*	
*	RETURN VALUES
*	Read line: correct behavior.
*	NULL: nothing else to read or an error occurred.
*/

static int	is_line(char *buffer)
{
	while (*buffer)
	{
		if (*(buffer++) == '\n')
			return (1);
	}
	return (0);
}

static void	att_buffer(char **static_buffer, char **buffer)
{
	char	*temp;

	temp = *static_buffer;
	*static_buffer = ft_strjoin(temp, *buffer);
	free(temp);
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
	return (*line);
}

static char	*read_file(int fd, char **buffer)
{
	static char	*static_buffer[OPEN_MAX];
	char		*line;
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
		att_buffer(&static_buffer[fd], buffer);
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
