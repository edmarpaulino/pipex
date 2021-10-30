/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:45:49 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/30 13:48:58 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		ret_value;
	t_data	data;

	ret_value = FT_SUCCESS;
	if (argc >= 5 || (argc >= 6 && ft_strcmp(argv[HERE_DOC], "here_doc") == 0))
	{
		data.system_path = ft_get_system_path(envp);
		if (data.system_path != FT_NULL)
		{
			data.argc = argc;
			data.argv = argv;
			data.envp = envp;
			ret_value = ft_init_bonus(&data);
			ft_clear_split(data.system_path);
		}
		else
			ret_value = ft_print_error_message("system's path not found");
	}
	else
		ret_value = ft_print_error_message("Wrong number of parameters");
	return (ret_value);
}
