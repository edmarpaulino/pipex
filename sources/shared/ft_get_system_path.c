/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_system_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:45:23 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/27 21:15:26 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shared.h"

static int	ft_add_path_slash(char **system_path)
{
	int		path_idx;
	char	*temp;

	path_idx = 0;
	while (system_path[path_idx] != FT_NULL)
	{
		temp = system_path[path_idx];
		system_path[path_idx] = ft_strjoin(temp, "/");
		if (system_path[path_idx] == FT_NULL)
		{
			system_path[path_idx] = temp;
			free(temp);
			ft_clear_split(system_path);
			return (FT_ERROR);
		}
		free(temp);
		path_idx++;
	}
	return (FT_SUCCESS);
}

char	**ft_get_system_path(char **envp)
{
	int		path_idx;
	char	*path;
	char	**system_path;

	path_idx = 0;
	while (ft_strncmp(envp[path_idx], "PATH=", 5) != 0)
	{
		path_idx++;
	}
	if (envp[path_idx] == FT_NULL)
	{
		return (FT_NULL);
	}
	else
	{
		path = ft_strtrim(envp[path_idx], "PATH=");
		if (path == FT_NULL)
		{
			return (FT_NULL);
		}
		else
		{
			system_path = ft_split(path, ':');
			free(path);
			if (system_path == FT_NULL)
			{
				return (FT_NULL);
			}
			else
			{
				if (ft_add_path_slash(system_path) == FT_ERROR)
				{
					return (FT_NULL);
				}
			}
		}
	}
	return (system_path);
}
