/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:17:01 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/27 21:17:55 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_clear_split(char **ptr)
{
	int	idx;

	idx = 0;
	while (ptr[idx] != FT_NULL)
	{
		free(ptr[idx]);
		idx++;
	}
	free(ptr);
}
