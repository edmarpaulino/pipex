/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 19:54:45 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/27 21:26:13 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		ret_value;
	t_data	data;

	ret_value = 0;
	if (argc != 5)
	{
		ret_value = ft_print_error_message("Wrong number of params");
	}
	else
	{
		data.argc = argc;
		data.argv = argv;
		data.envp = envp;
		ret_value = ft_pipex(&data);
	}
	return (ret_value);
}
