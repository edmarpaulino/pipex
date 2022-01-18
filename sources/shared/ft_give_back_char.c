/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_back_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:56:00 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/18 17:00:44 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shared.h"

void	ft_give_back_char(t_source *src)
{
	if (src->cur_pos < 0)
		return ;
	src->cur_pos--;
}
