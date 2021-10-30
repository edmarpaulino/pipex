/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 09:35:13 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/30 13:46:35 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

int	ft_init_bonus(t_data *data)
{
	int	ret_value;
	int	cmd_index;

	ret_value = FT_SUCCESS;
	if (ft_strcmp(data->argv[HERE_DOC], "here_doc") == FT_SUCCESS)
	{
		cmd_index = 3;
		ft_here_doc_bonus(data);
	}
	else
		cmd_index = 2;
	while (cmd_index < (data->argc - 1))
	{
		ret_value = ft_pipex_bonus(cmd_index, data);
		cmd_index++;
	}
	return (ret_value);
}
