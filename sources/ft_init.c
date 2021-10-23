/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:36:22 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/23 10:47:48 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static void	ft_set_ptrs_null(t_vars *vars)
{
	vars->infile = NULL;
	vars->cmd1 = NULL;
	vars->cmd2 = NULL;
	vars->outfile = NULL;
	vars->sys_path = NULL;
	vars->cmd1_args = NULL;
	vars->cmd2_args = NULL;
	vars->envp = NULL;
}

t_vars	*ft_init(t_vars *vars, char **argv, char **envp)
{
	ft_set_ptrs_null(vars);
	vars->infile = argv[1];
	vars->cmd1 = argv[2];
	vars->cmd2 = argv[3];
	vars->outfile = argv[4];
	vars->sys_path = ft_get_sys_path(envp);
	if (!vars->sys_path)
		return (NULL);
	vars->cmd1_args = ft_split(argv[2], ' ');
	if (!vars->cmd1_args)
		return (NULL);
	vars->cmd2_args = ft_split(argv[3], ' ');
	if (!vars->cmd2_args)
		return (NULL);
	vars->envp = envp;
	return (vars);
}
