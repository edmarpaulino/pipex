/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:38:16 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/28 09:59:18 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	ft_pipex(t_data *data)
{
	int	ret_value;

	ret_value = 0;
	data->system_path = ft_get_system_path(data->envp);
	if (data->system_path != FT_NULL)
	{
		ft_putendl_fd("That's it", FT_STDOUT);
		ft_clear_split(data->system_path);
	}
	else
		ret_value = ft_print_error_message("System's path not found");
	return (ret_value);
}
