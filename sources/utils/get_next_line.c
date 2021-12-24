/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:43:22 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/24 11:04:23 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

static ssize_t	has_line(char *static_buffer)
{
	ssize_t	i;

	if (static_buffer)
	{
		i = 0;
		while (static_buffer[i] != '\n' && static_buffer[i])
			i++;
		if (static_buffer[i] == '\n')
			return (i);
	}
	return (-1);
}

static ssize_t	get_buffer(int fd, char **static_buffer)
{
	char	*buffer;
	char	*tmp;
	ssize_t	ret;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char *));
	if (!buffer)
		return (-1);
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		if (!*static_buffer)
			*static_buffer = ft_strdup(buffer);
		else
		{
			tmp = *static_buffer;
			*static_buffer = ft_strjoin(tmp, buffer);
			free(tmp);
		}
		if (has_line(*static_buffer) > 0)
			break ;
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (ret);
}

static void	get_line(char **static_buffer, char **line)
{
	ssize_t	i;
	char	*tmp;

	if (*static_buffer)
	{
		i = has_line(*static_buffer);
		if (i >= 0)
		{
			tmp = *static_buffer;
			*line = ft_substr(tmp, 0, i + 1);
			*static_buffer = ft_substr(tmp, i + 1, ft_strlen(tmp));
			free(tmp);
			if (ft_strlen(*static_buffer) == 0)
			{
				free(*static_buffer);
				*static_buffer = NULL;
			}
		}
		else
		{
			*line = ft_strdup(*static_buffer);
			free(*static_buffer);
			*static_buffer = NULL;
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*static_buffer[OPEN_MAX];
	char		*line;
	ssize_t		ret;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	ret = get_buffer(fd, &static_buffer[fd]);
	line = NULL;
	if (ret == -1)
	{
		if (static_buffer[fd])
			free(static_buffer[fd]);
	}
	else
		get_line(&static_buffer[fd], &line);
	return (line);
}
