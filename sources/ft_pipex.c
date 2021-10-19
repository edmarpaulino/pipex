/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:30:31 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/19 19:20:34 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static void	close_pipe(int end[2])
{
	close(end[0]);
	close(end[1]);
}

static int	child1(t_data *data, int end[2], char **envp)
{
	char	*cmd;
	int		fd;

	fd = open(data->infile, O_RDONLY);
	if (fd == -1)
	{
		perror("Could not open infile");
		return (-1);
	}
	dup2(end[1], STDOUT_FILENO);
	dup2(fd, STDIN_FILENO);
	close_pipe(end);
	close(fd);
	cmd = ft_get_cmd_path(data->sys_path, data->param1[0]);
	if (!cmd)
	{
		perror("Command not found");
		return (-1);
	}
	if (execve(cmd, data->param1, envp) == -1)
		perror("Could not execve cmd1");
	free(cmd);
	return (-1);
}

static int	child2(t_data *data, int end[2], char **envp)
{
	char	*cmd;
	int		fd;

	fd = open(data->outfile, O_CREAT | O_WRONLY | O_RDONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Could not create outfile");
		return (-1);
	}
	dup2(end[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	close_pipe(end);
	cmd = ft_get_cmd_path(data->sys_path, data->param2[0]);
	if (!cmd)
	{
		perror("Command not found");
		return (-1);
	}
	if (execve(cmd, data->param2, envp) == -1)
		perror("Could not execve cmd2");
	free(cmd);
	return (-1);
}

int	ft_pipex(t_data *data, char **envp)
{
	int		end[2];
	int		pid1;
	int		pid2;

	if (pipe(end) == -1)
		return (-1);
	pid1 = fork();
	if (pid1 == -1)
		return (-1);
	if (pid1 == 0)
	{
		if (child1(data, end, envp) == -1)
			return (-1);
	}
	pid2 = fork();
	if (pid2 == -1)
		return (-1);
	if (pid2 == 0)
	{
		if (child2(data, end, envp) == -1)
			return (-1);
	}
	close_pipe(end);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (1);
}
