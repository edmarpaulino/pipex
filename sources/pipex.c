/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:30:31 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/15 20:21:25 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(t_data *data, char **envp)
{
	int		fd[2];
	pid_t	pid;
	int		status;
	int		i;
	char	*binarie;
	if (!data)
		return (-1);
	// printf("this is the input file:		%s\n", data->infile);
	// printf("this is the cmd1:		%s\n", data->cmd1);
	// printf("this is the cmd2:		%s\n", data->cmd2);
	// printf("this is the output file:	%s\n", data->outfile);
	if (pipe(fd) == -1)
	 return (0);
	if ((pid = fork()) == -1)
		return (0);
	if (pid > 0)
	{
		close(fd[1]);
		waitpid(pid, &status, 0);
		i = -1;
		while (data->sys_path[++i])
		{
			binarie = ft_strjoin(data->sys_path[i], data->cmd2);
			if (!access(binarie, status))
				execve(binarie, data->param2, envp);
		}
		close(fd[0]);
		return (1);
	}
	else
	{
		close(fd[0]);
		i = -1;
		while (data->sys_path[++i])
		{
			binarie = ft_strjoin(data->sys_path[i], data->cmd1);
			if (!access(binarie, status))
				execve(binarie, data->param1, envp);
		}
		close(fd[1]);
		return (1);
	}
	return (1);
}
