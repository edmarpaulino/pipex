/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:36:22 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/22 20:42:35 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

t_vars	*ft_init(t_vars *vars, char **argv, char **envp)
{
	vars->infile = argv[1];
	vars->cmd1 = argv[2];
	vars->cmd2 = argv[3];
	vars->outfile = argv[4];
	vars->sys_path = ft_get_sys_path(envp);
	if (!vars->sys_path)
		return (NULL);
	vars->cmd1_args = ft_split(argv[2], ' ');
	if (!vars->cmd1_args)
	{
		ft_clear_split(vars->sys_path);
		return (NULL);
	}
	vars->cmd2_args = ft_split(argv[3], ' ');
	if (!vars->cmd2_args)
	{
		ft_clear_split(vars->sys_path);
		ft_clear_split(vars->cmd1_args);
		return (NULL);
	}
	vars->envp = envp;
	return (vars);
}
