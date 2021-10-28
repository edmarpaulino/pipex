/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:29:44 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/28 11:37:47 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shared.h"

char	*ft_get_cmd_path(char *cmd_name, char **system_path)
{
	int		index;
	char	*cmd_path;

	index = 0;
	cmd_path = FT_NULL;
	while (system_path[index] != FT_NULL)
	{
		cmd_path = ft_strjoin(system_path[index], cmd_name);
		if (access(cmd_path, F_OK | X_OK) != FT_SUCCESS)
		{
			free(cmd_path);
			cmd_path = FT_NULL;
		}
		else
			break ;
	}
	return (cmd_path);
}
