/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error_message.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:03:28 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/28 15:50:25 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shared.h"

int	ft_print_error_message(char *message)
{
	if (message != FT_NULL)
		ft_putendl_fd(message, FT_STDERR);
	else
		perror("Error");
	return (1);
}
