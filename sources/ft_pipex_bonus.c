/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 10:07:12 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/30 13:46:47 by edpaulin         ###   ########.fr       */
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

static int	ft_execute_command(t_data *data, int cmd)
{
	int		ret_value;
	char	*cmd_path;
	char	**cmd_arguments;

	ret_value = FT_SUCCESS;
	cmd_arguments = ft_split(data->argv[cmd], ' ');
	if (cmd_arguments != FT_NULL)
	{
		cmd_path = ft_get_cmd_path(cmd_arguments[CMD_NAME], data->system_path);
		if (cmd_path == FT_NULL)
		{
			cmd_path = ft_strjoin(CMD_NF, cmd_arguments[CMD_NAME]);
			ret_value = ft_print_error_message(cmd_path);
		}
		else
		{
			if (execve(cmd_path, cmd_arguments, data->envp) == FT_ERROR)
				ret_value = ft_print_error_message(NULL);
		}
		free(cmd_path);
		ft_clear_split(cmd_arguments);
	}
	else
		ret_value = ft_print_error_message("Error in command's agurments");
	return (ret_value);
}

static int	ft_child_process(int *end, int cmd_index, t_data *data)
{
	int	fd;
	int	ret_value;

	ret_value = FT_SUCCESS;
	if (cmd_index == 2)
	{
		fd = ft_open_file(data->argv[INFILE], FT_STDIN, data);
		if (fd != FT_ERROR)
		{
			dup2(fd, FT_STDIN);
			dup2(end[1], FT_STDOUT);
			close(fd);
			ft_close_pipe(end);
			ret_value = ft_execute_command(data, cmd_index);
		}
		else
		{
			ret_value = ft_print_error_message(FT_NULL);
			ft_close_pipe(end);
		}
	}
	else
	{
		dup2(end[1], FT_STDOUT);
		ret_value = ft_execute_command(data, cmd_index);
	}
	return (ret_value);
}

static int	ft_parent_process(int *end, int cmd_index, t_data *data)
{
	int	fd;
	int	ret_value;

	ret_value = FT_SUCCESS;
	fd = ft_open_file(data->argv[data->argc - 1], FT_STDOUT, data);
	if (fd != FT_ERROR)
	{
		dup2(fd, FT_STDOUT);
		dup2(end[0], FT_STDIN);
		close(fd);
		ft_close_pipe(end);
		ret_value = ft_execute_command(data, cmd_index);
	}
	else
	{
		ret_value = ft_print_error_message(FT_NULL);
		ft_close_pipe(end);
	}
	return (ret_value);
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
			if (pid == CHILD_PROCESS && cmd_index < (data->argc - 2))
			{
				ret_value = ft_child_process(end, cmd_index, data);
				dup2(end[0], FT_STDIN);
				ft_close_pipe(end);
			}
			else if (cmd_index == (data->argc - 2))
				ret_value = ft_parent_process(end, cmd_index, data);
		}
		else
			ret_value = ft_print_error_message(FT_NULL);
	}
	else
		ret_value = ft_print_error_message(FT_NULL);
	return (ret_value);
}
