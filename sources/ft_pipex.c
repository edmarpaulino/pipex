/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:38:16 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/18 17:13:20 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static int	ft_open_file(char *file_name, char open_option)
{
	int	fd;

	fd = FT_ERROR;
	if (open_option == FT_STDIN)
		fd = open(file_name, O_RDONLY);
	else if (open_option == FT_STDOUT)
		fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	return (fd);
}

static void	ft_execute_command(t_data *data, int cmd)
{
	char	*cmd_path;
	char	**cmd_arguments;

	cmd_arguments = ft_get_argument_vector(data->argv[cmd]);
	if (cmd_arguments != FT_NULL)
	{
		cmd_path = ft_get_cmd_path(cmd_arguments[CMD_NAME], data->system_path);
		if (cmd_path != FT_NULL)
		{
			if (execve(cmd_path, cmd_arguments, data->envp) == FT_ERROR)
			{
				free(cmd_path);
				ft_clear_split(cmd_arguments);
				ft_clear_and_exit(data, FT_NULL, WITH_MESSAGE);
			}
		}
		else
		{
			ft_clear_split(cmd_arguments);
			ft_clear_and_exit(data, CMD_NF_ERR, WITH_MESSAGE);
		}
	}
	else
		ft_clear_and_exit(data, CMD_ARG_ERR, WITHOUT_MESSAGE);
}

static void	ft_child_process(int *end, t_data *data)
{
	int	fd;

	fd = ft_open_file(data->argv[INFILE], FT_STDIN);
	if (fd != FT_ERROR)
	{
		dup2(fd, FT_STDIN);
		dup2(end[1], FT_STDOUT);
		close(fd);
		ft_close_pipe(end);
		ft_execute_command(data, CMD1);
	}
	else
	{
		ft_close_pipe(end);
		ft_clear_and_exit(data, FT_NULL, WITH_MESSAGE);
	}
}

static void	ft_parent_process(int *end, t_data *data)
{
	int	fd;

	fd = ft_open_file(data->argv[OUTFILE], FT_STDOUT);
	if (fd != FT_ERROR)
	{
		dup2(fd, FT_STDOUT);
		dup2(end[0], FT_STDIN);
		close(fd);
		ft_close_pipe(end);
		ft_execute_command(data, CMD2);
	}
	else
	{
		ft_close_pipe(end);
		ft_clear_and_exit(data, FT_NULL, WITH_MESSAGE);
	}
}

int	ft_pipex(t_data *data)
{
	int	end[2];
	int	pid;
	int	ret_value;

	ret_value = FT_SUCCESS;
	if (pipe(end) != FT_ERROR)
	{
		pid = fork();
		if (pid != FT_ERROR)
		{
			if (pid == CHILD_PROCESS)
				ft_child_process(end, data);
			else
				ft_parent_process(end, data);
		}
		else
			ret_value = ft_print_error_message(FT_NULL);
	}
	else
		ret_value = ft_print_error_message(FT_NULL);
	return (ret_value);
}
