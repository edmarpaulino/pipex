/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:42:00 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/19 19:33:27 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	if (argc != 5)
	{
		ft_putendl_fd("wrong number of arguments", 2);
		return (1);
	}
	data.infile = ft_strdup(argv[1]);
	data.outfile = ft_strdup(argv[4]);
	data.cmd1 = ft_strdup(argv[2]);
	data.cmd2 = ft_strdup(argv[3]);
	data.sys_path = ft_get_path(envp);
	if (!data.sys_path)
		return (1);
	data.param1 = ft_split(data.cmd1, ' ');
	data.param2 = ft_split(data.cmd2, ' ');
	if (ft_pipex(&data, envp) == -1)
	{
		ft_clean_memory(&data);
		return (1);
	}
	ft_clean_memory(&data);
	ft_clear_split(data.param1);
	ft_clear_split(data.param2);
	return (0);
}
