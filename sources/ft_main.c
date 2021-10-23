/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:47:50 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/23 19:13:28 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;

	if (argc != 5)
	{
		ft_putendl_fd("wrong number of params", STDERR);
		return (1);
	}
	if (!ft_init(&vars, argv, envp))
	{
		ft_putendl_fd("Init error", STDERR);
		ft_clear_memory(&vars);
		return (1);
	}
	if (ft_pipex(&vars) == -1)
	{
		ft_clear_memory(&vars);
		return (1);
	}
	ft_clear_memory(&vars);
	return (0);
}
