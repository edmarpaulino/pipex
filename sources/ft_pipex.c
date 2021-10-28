/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:38:16 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/28 11:38:02 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static int	ft_open_file(char *file_name, char open_option)
{
	int	fd;

	if (open_option == FT_STDIN)
		fd = open(file_name, O_RDONLY);
	else if (open_option == FT_STDOUT)
		fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	else
		fd = FT_ERROR;
	return (fd);
}

static int	ft_child_process(int *end, t_data *data)
{
	int		fd;
	int		ret_value;
	char	*cmd_path;
	char	**cmd_arguments;

	if (close(end[0]) != FT_ERROR)
	{
		fd = ft_open_file(data->argv[1], FT_STDIN);
		dup2(fd, FT_STDIN);
		close(fd);
		dup2(end[1], FT_STDOUT);
		close(end[1]);
		cmd_arguments = ft_split(data->argv[CMD1], ' ');
		cmd_path = ft_get_cmd_path(cmd_arguments[CMD_NAME], data->system_path);
		if (execve(cmd_path, cmd_arguments, data->envp) == FT_ERROR)
			ret_value = ft_print_error_message(NULL);
	}
	else
		ret_value = ft_print_error_message(NULL);
	return (ret_value);
}

static int	ft_parent_process(int *end, t_data *data)
{
	
}

int	ft_pipex(t_data *data)
{
	int	end[2];
	int	pid;
	int	ret_value;

	ret_value = 0;
	if (pipe(end) != FT_ERROR)
	{
		pid = fork();
		if (pid != FT_ERROR)
		{
			if (pid == CHILD_PROCESS)
				ft_child_process(end, data);
			else
			{
				ft_parent_process(end, data);
				ft_close_pipe(end);
			}
		}
		else
			ret_value = ft_print_error_message(FT_NULL);
	}
	else
		ret_value = ft_print_error_message(FT_NULL);
	return (ret_value);
}
