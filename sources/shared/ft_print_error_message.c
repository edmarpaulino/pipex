/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error_message.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:03:28 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/18 17:31:44 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shared.h"

int	ft_print_error_message(char *message)
{
	if (message != FT_NULL)
	{
		ft_putendl_fd(message, FT_STDERR);
		if (ft_strcmp(message, CMD_NF_ERR) == 0)
			return (FT_CMD_NOT_FOUND);
	}
	else
		perror("pipex");
	return (FT_RET_ERROR);
}
