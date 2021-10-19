/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:06:17 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/19 19:15:24 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static int	ft_add_slash(char **path)
{
	char	*tmp;

	while (*path)
	{
		tmp = *path;
		*path = ft_strjoin(tmp, "/");
		if (!*path)
		{
			*path = tmp;
			free(tmp);
			return (-1);
		}
		free(tmp);
		path++;
	}
	return (1);
}

char	**ft_get_path(char **envp)
{
	char	*str;
	char	**path;

	while (ft_strncmp(*envp, "PATH=", 5))
		envp++;
	str = ft_strtrim(*envp, "PATH=");
	path = ft_split(str, ':');
	free(str);
	if (!path)
		return (NULL);
	if (ft_add_slash(path) == -1)
		return (NULL);
	return (path);
}
