/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:17:20 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/23 12:24:10 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char	*ft_get_cmd_path(char *cmd, char **sys_path)
{
	char	*cmd_path;
	int		i_sys_path;

	i_sys_path = 0;
	while (sys_path[i_sys_path])
	{
		cmd_path = ft_strjoin(sys_path[i_sys_path], cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i_sys_path++;
	}
	return (NULL);
}
