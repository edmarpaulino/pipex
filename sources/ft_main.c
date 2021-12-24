/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 19:54:45 by edpaulin          #+#    #+#             */
/*   Updated: 2021/11/01 10:54:22 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		ret_value;
	t_data	data;

	ret_value = FT_SUCCESS;
	if (argc == 5)
	{
		data.system_path = ft_get_system_path(envp);
		if (data.system_path != FT_NULL)
		{
			data.argc = argc;
			data.argv = argv;
			data.envp = envp;
			ret_value = ft_pipex(&data);
			ft_clear_split(data.system_path);
		}
		else
			ret_value = ft_print_error_message("System's path not found");
	}
	else
		ret_value = ft_print_error_message("Wrong number of parameters");
	return (ret_value);
}
