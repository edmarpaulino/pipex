/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:38:16 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/27 21:23:33 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	ft_pipex(t_data *data)
{
	int	ret_value;

	ret_value = 0;
	data->system_path = ft_get_system_path(data->envp);
	if (data->system_path == FT_NULL)
	{
		ret_value = ft_print_error_message("System path not found");
	}
	else
	{
		ret_value = 0;
		ft_putendl_fd("That's it", FT_STDOUT);
	}
	ft_clear_split(data->system_path);
	return (ret_value);
}
