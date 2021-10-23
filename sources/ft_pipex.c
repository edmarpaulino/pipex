/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 10:57:57 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/23 19:25:23 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static void	ft_close_pipe(int pipe_end[2])
{
	close(pipe_end[0]);
	close(pipe_end[1]);
}

static void	ft_wait_pipe(pid_t pid_send, pid_t pid_receive)
{
	waitpid(pid_send, NULL, 0);
	waitpid(pid_receive, NULL, 0);
}

static int	ft_send_pipe(int pipe_end[2], t_vars *vars)
{
	int		fd_infile;
	char	*cmd_path;

	fd_infile = open(vars->infile, O_RDONLY);
	if (fd_infile == -1)
		return (ft_error_message("infile"));
	dup2(fd_infile, STDIN);
	dup2(pipe_end[1], STDOUT);
	close(fd_infile);
	ft_close_pipe(pipe_end);
	cmd_path = ft_get_cmd_path(vars->cmd1_args[0], vars->sys_path);
	if (!cmd_path)
		return (ft_error_message("cmd1"));
	if (execve(cmd_path, vars->cmd1_args, vars->envp) == -1)
		return (ft_error_message("cmd1"));
	return (1);
}

static int	ft_receive_pipe(int pipe_end[2], t_vars *vars)
{
	int		fd_outfile;
	char	*cmd_path;

	fd_outfile = open(vars->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd_outfile == -1)
		return (ft_error_message("outfile"));
	dup2(fd_outfile, STDOUT);
	dup2(pipe_end[0], STDIN);
	close(fd_outfile);
	ft_close_pipe(pipe_end);
	cmd_path = ft_get_cmd_path(vars->cmd2_args[0], vars->sys_path);
	if (!cmd_path)
		return (ft_error_message("cmd2"));
	if (execve(cmd_path, vars->cmd2_args, vars->envp) == -1)
		return (ft_error_message("cmd2"));
	return (1);
}

int	ft_pipex(t_vars *vars)
{
	int		pipe_end[2];
	pid_t	pid_send;
	pid_t	pid_receive;

	if (pipe(pipe_end) == -1)
		return (ft_error_message("pipe"));
	pid_send = fork();
	if (pid_send == -1)
		return (ft_error_message("fork send"));
	else if (pid_send == 0)
	{
		if (ft_send_pipe(pipe_end, vars) == -1)
			return (-1);
	}
	pid_receive = fork();
	if (pid_receive == -1)
		return (ft_error_message("fork receive"));
	else if (pid_receive == 0)
	{
		if (ft_receive_pipe(pipe_end, vars) == -1)
			return (-1);
	}
	ft_close_pipe(pipe_end);
	ft_wait_pipe(pid_send, pid_receive);
	return (1);
}
