/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 10:37:26 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/23 10:39:43 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_clear_memory(t_vars *vars)
{
	if (vars->sys_path)
		ft_clear_split(vars->sys_path);
	if (vars->cmd1_args)
		ft_clear_split(vars->cmd1_args);
	if (vars->cmd2_args)
		ft_clear_split(vars->cmd2_args);
}
