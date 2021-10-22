/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:47:50 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/22 20:43:54 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;
	int		i;

	if (argc != 5)
	{
		ft_putendl_fd("wrong number of params", STDERR);
		return (1);
	}
	if (!ft_init(&vars, argv, envp))
	{
		ft_putendl_fd("Init error", STDERR);
		return (1);
	}
	ft_clear_split(vars.sys_path);
	ft_clear_split(vars.cmd1_args);
	ft_clear_split(vars.cmd2_args);
	return (0);
}

//	printf("this is infile name: %s\n", vars.infile);
//	i = 0;
//	while (vars.cmd1_args[i])
//	{
//		printf("%s\n", vars.cmd1_args[i]);
//		i++;
//	}
//	i = 0;
//	while (vars.cmd2_args[i])
//	{
//		printf("%s\n", vars.cmd2_args[i]);
//		i++;
//	}
//	printf("this is outfile name: %s\n", vars.outfile);
//	i = 0;
//	while (vars.sys_path[i])
//	{
//		printf("%s\n", vars.sys_path[i]);
//		i++;
//	}
