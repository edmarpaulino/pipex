/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 09:41:56 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/01 10:54:14 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

static int	ft_check_limiter(char *line, char *limiter)
{
	int	ret_value;
	int	check;

	check = FT_FALSE;
	if (ft_lastchr(line) == '\n')
	{
		check = FT_TRUE;
		line[ft_strlen(line) - 1] = '\0';
	}
	if (ft_strcmp(line, limiter) == FT_SUCCESS)
		ret_value = FT_TRUE;
	else
		ret_value = FT_FALSE;
	if (check == FT_TRUE)
		line[ft_strlen(line)] = '\n';
	return (ret_value);
}

void	ft_here_doc_bonus(t_data *data)
{
	int		end[2];
	char	*line;

	if (pipe(end) != FT_ERROR)
	{
		write(FT_STDOUT, "pipex here_doc> ", 16);
		line = get_next_line(FT_STDIN);
		while (line != FT_NULL \
				&& ft_check_limiter(line, data->argv[LIMITER]) != FT_TRUE)
		{
			if (write(end[1], line, ft_strlen(line)) == FT_ERROR)
				ft_print_error_message("Cannot write a line on pipe");
			free(line);
			write(FT_STDOUT, "pipex here_doc> ", 16);
			line = get_next_line(FT_STDIN);
		}
		if (line != FT_NULL)
			free(line);
	}
	else
		ft_clear_and_exit(data, FT_NULL, WITH_MESSAGE);
	dup2(end[0], FT_STDIN);
	if (ft_close_pipe(end) == FT_ERROR)
		ft_clear_and_exit(data, FT_NULL, WITH_MESSAGE);
}
