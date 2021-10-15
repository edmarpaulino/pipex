/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:42:00 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/15 20:17:53 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	clean_memory(t_data *data)
{
	ft_clear_split(data->sys_path);
	free(data->infile);
	free(data->outfile);
	free(data->cmd1);
	free(data->cmd2);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc < 5 || !*envp)
	{
		perror("Error: ");
		exit(-1);
	}
	if (argc == 5)
	{
		data.infile = ft_strdup(argv[1]);
		data.outfile = ft_strdup(argv[4]);
		data.cmd1 = ft_strdup(argv[2]);
		data.cmd2 = ft_strdup(argv[3]);
	}
	if (!(data.sys_path = get_path(envp)))
		return (1);
	data.param1 = ft_split(data.cmd1, ' ');
	data.param2 = ft_split(data.cmd2, ' ');
	if (!pipex(&data, envp))
	{
		perror("Error: ");
		clean_memory(&data);
		return (1);
	}
	clean_memory(&data);
	ft_clear_split(data.param1);
	ft_clear_split(data.param2);
	return (0);
}
