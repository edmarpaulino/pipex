/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_system_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:45:23 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/02 16:26:20 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shared.h"

static void	ft_add_path_slash(char **system_path)
{
	int		index;
	char	*temp;

	if (system_path != FT_NULL)
	{
		index = 0;
		while (system_path[index] != FT_NULL)
		{
			temp = system_path[index];
			system_path[index] = ft_strjoin(temp, "/");
			if (system_path[index] == FT_NULL)
			{
				system_path[index] = temp;
				ft_clear_split(system_path);
				system_path = FT_NULL;
				break ;
			}
			free(temp);
			index++;
		}
	}
}

char	**ft_get_system_path(char **envp)
{
	int		index;
	char	*path;
	char	**system_path;

	index = 0;
	system_path = FT_NULL;
	if (envp != FT_NULL)
	{
		while (ft_strncmp(envp[index], "PATH=", 5) != 0)
			index++;
		if (envp[index] != FT_NULL)
		{
			path = ft_strtrim(envp[index], "PATH=");
			if (path != FT_NULL)
			{
				system_path = ft_split(path, ':');
				free(path);
				ft_add_path_slash(system_path);
			}
		}
	}
	return (system_path);
}
