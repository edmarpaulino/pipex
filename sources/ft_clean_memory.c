/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:25:41 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/19 19:35:17 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_clean_memory(t_data *data)
{
	ft_clear_split(data->sys_path);
	free(data->infile);
	free(data->outfile);
	free(data->cmd1);
	free(data->cmd2);
}
