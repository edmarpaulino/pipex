/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_and_exit_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 10:15:10 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/31 10:20:20 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

void	ft_clear_and_exit_bonus(t_data *data, char option)
{
	if (option == WITHOUT_MESSAGE)
	{
		ft_clear_split(data->system_path);
		exit(1);
	}
	else
	{
		ft_clear_split(data->system_path);
		exit(ft_print_error_message(FT_NULL));
	}
}
