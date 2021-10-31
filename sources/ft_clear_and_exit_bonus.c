/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_and_exit_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 10:15:10 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/31 12:30:40 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

void	ft_clear_and_exit_bonus(t_data *data, char *message, char option)
{
	if (option == WITHOUT_MESSAGE)
	{
		ft_clear_split(data->system_path);
		exit(EXIT_SUCCESS);
	}
	else if (option == WITHOUT_MESSAGE)
	{
		if (message != FT_NULL)
		{
			ft_clear_split(data->system_path);
			exit(ft_print_error_message(message));
		}
		else
		{
			ft_clear_split(data->system_path);
			exit(ft_print_error_message(FT_NULL));
		}
	}
}
