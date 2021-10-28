/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:38:16 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/28 10:23:42 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	ft_pipex(t_data *data)
{
	int	ret_value;

	ret_value = 0;
	if (data != FT_NULL)
		ft_putendl_fd("That's it", FT_STDOUT);
	return (ret_value);
}
