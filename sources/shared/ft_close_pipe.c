/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:37:09 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/29 11:39:56 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shared.h"

int	ft_close_pipe(int *end)
{
	int	ret_value;

	ret_value = 0;
	if (close(end[0]) == FT_ERROR)
		ret_value = ft_print_error_message("end[0]");
	if (close(end[1]) == FT_ERROR)
		ret_value = ft_print_error_message("end[1]");
	return (ret_value);
}
