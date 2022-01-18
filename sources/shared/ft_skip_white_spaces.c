/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_white_spaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:58:08 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/18 17:09:19 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shared.h"

void	ft_skip_white_spaces(t_source *src)
{
	int	c;

	if (!src || !src->buffer)
		return ;
	c = ft_peek_next_char(src);
	while (c != END_OF_SOURCE && ft_isspace(c))
	{
		ft_get_next_char(src);
		c = ft_peek_next_char(src);
	}
}
