/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_sys_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:34:41 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/22 20:40:33 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static int	ft_add_path_slash(char **sys_path)
{
	char	*tmp;
	int		i;

	i = 0;
	while (sys_path[i])
	{
		tmp = sys_path[i];
		sys_path[i] = ft_strjoin(tmp, "/");
		if (!sys_path[i])
		{
			sys_path[i] = tmp;
			free(tmp);
			ft_clear_split(sys_path);
			return (-1);
		}
		free(tmp);
		++i;
	}
	return (1);
}

char	**ft_get_sys_path(char **envp)
{
	char	**sys_path;
	char	*path;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		++i;
	path = ft_strtrim(envp[i], "PATH=");
	sys_path = ft_split(path, ':');
	free(path);
	if (!sys_path)
		return (NULL);
	if (ft_add_path_slash(sys_path) == -1)
		return (NULL);
	return (sys_path);
}
