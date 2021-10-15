/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:06:17 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/15 14:57:21 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **envp)
{
	int		i;
	char	*str;
	char	**my_path;
	char	*tmp;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		++i;
	str = ft_strtrim(envp[i], "PATH=");
	my_path = ft_split(str, ':');
	free(str);
	if (!my_path)
		return (NULL);
	i = -1;
	while (my_path[++i])
	{
		tmp = my_path[i];
		my_path[i] = ft_strjoin(tmp, "/");
		free(tmp);
	}
	return (my_path);
}
