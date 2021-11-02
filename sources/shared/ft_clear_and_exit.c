/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_and_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 10:15:10 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/01 11:59:37 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shared.h"

void	ft_clear_and_exit(t_data *data, char *message, char option)
{
	ft_clear_split(data->system_path);
	if (option == WITHOUT_MESSAGE)
		exit(EXIT_FAILURE);
	else if (option == WITH_MESSAGE)
	{
		if (message != FT_NULL)
			exit(ft_print_error_message(message));
		else
			exit(ft_print_error_message(FT_NULL));
	}
}
