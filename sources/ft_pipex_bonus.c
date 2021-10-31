/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 10:07:12 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/31 12:51:15 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

static int	ft_open_file(char *file_name, char open_option, t_data *data)
{
	int	fd;

	fd = FT_ERROR;
	if (open_option == FT_STDIN)
		fd = open(file_name, O_RDONLY);
	else if (open_option == FT_STDOUT)
	{
		if (ft_strcmp(data->argv[HERE_DOC], "here_doc") == FT_SUCCESS)
			fd = open(file_name, O_CREAT | O_RDWR | O_APPEND, 0644);
		else
			fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
	return (fd);
}

static void	ft_execute_command(t_data *data, int cmd)
{
	char	*cmd_path;
	char	**cmd_arguments;

	cmd_arguments = ft_split(data->argv[cmd], ' ');
	if (cmd_arguments != FT_NULL)
	{
		cmd_path = ft_get_cmd_path(cmd_arguments[CMD_NAME], data->system_path);
		if (cmd_path != FT_NULL)
		{
			if (execve(cmd_path, cmd_arguments, data->envp) == FT_ERROR)
				ft_clear_and_exit_bonus(data, FT_NULL, WITH_MESSAGE);
		}
		else
		{
			cmd_path = ft_strjoin(CMD_NF, cmd_arguments[CMD_NAME]);
			ft_clear_and_exit_bonus(data, cmd_path, WITH_MESSAGE);
		}
		free(cmd_path);
		ft_clear_and_exit_bonus(data, FT_NULL, WITHOUT_MESSAGE);
	}
	else
	{
		cmd_path = ft_strdup("pipex: error in command's argurments");
		ft_clear_and_exit_bonus(data, cmd_path, WITH_MESSAGE);
	}
}

static void	ft_child_process(int *end, int cmd_index, t_data *data)
{
	int	fd;

	close(end[0]);
	if (cmd_index == (data->argc - 2))
		ft_clear_and_exit_bonus(data, FT_NULL, WITHOUT_MESSAGE);
	else
	{
		if (cmd_index == 2)
		{
			fd = ft_open_file(data->argv[INFILE], FT_STDIN, data);
			if (fd == FT_ERROR)
				ft_clear_and_exit_bonus(data, FT_NULL, WITH_MESSAGE);
			dup2(fd, FT_STDIN);
			close(fd);
		}
		dup2(end[1], FT_STDOUT);
		close(end[1]);
		ft_execute_command(data, cmd_index);
	}
}

static void	ft_parent_process(int *end, int cmd_index, int pid, t_data *data)
{
	int	fd;

	close(end[1]);
	if (cmd_index == (data->argc - 2))
	{
		waitpid(pid, NULL, 0);
		fd = ft_open_file(data->argv[data->argc - 1], FT_STDOUT, data);
		if (fd != FT_ERROR)
		{
			dup2(fd, FT_STDOUT);
			close(fd);
			ft_execute_command(data, cmd_index);
		}
		ft_clear_and_exit_bonus(data, FT_NULL, WITHOUT_MESSAGE);
	}
}

int	ft_pipex_bonus(int cmd_index, t_data *data)
{
	int	ret_value;
	int	end[2];
	int	pid;

	ret_value = FT_SUCCESS;
	if (pipe(end) != FT_ERROR)
	{
		pid = fork();
		if (pid != FT_ERROR)
		{
			if (pid == CHILD_PROCESS)
				ft_child_process(end, cmd_index, data);
			else
			{
				ft_parent_process(end, cmd_index, pid, data);
				dup2(end[0], FT_STDIN);
				close(end[0]);
			}
		}
		else
			ret_value = ft_print_error_message(FT_NULL);
	}
	else
		ret_value = ft_print_error_message(FT_NULL);
	return (ret_value);
}
