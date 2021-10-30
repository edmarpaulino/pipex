/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 09:41:56 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/30 09:59:32 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

static int	ft_check_limiter(char *line, char *limiter)
{
	int	ret_value;

	line[ft_strlen(line) - 1] = '\0';
	if (ft_strcmp(line, limiter) == FT_SUCCESS)
		ret_value = FT_TRUE;
	else
		ret_value = FT_FALSE;
	return (ret_value);
}

void	ft_here_doc_bonus(t_data *data)
{
	int		end[2];
	char	*line;

	if (pipe(end) != FT_ERROR)
	{
		line = get_next_line(FT_STDIN);
		write(FT_STDOUT, "pipex here_doc> ", 16);
		while (line != FT_NULL \
				&& ft_check_limiter(line, data->argv[LIMITER]) != FT_TRUE)
		{
			if (write(end[1], line, ft_strlen(line)) == FT_ERROR)
				ft_print_error_message("Cannot write a line on pipe");
			free(line);
			line = get_next_line(FT_STDIN);
			write(FT_STDOUT, "pipex here_doc> ", 16);
		}
	}
	else
	{
		ft_clear_split(data->system_path);
		exit(ft_print_error_message(FT_NULL));
	}
	dup2(end[0], FT_STDIN);
	ft_close_pipe(end);
}
