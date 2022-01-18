/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_peek_next_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:57:31 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/18 16:57:44 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shared.h"

char	ft_peek_next_char(t_source *src)
{
	if (!src || !src->buffer)
		return (ERRCHAR);
	if (src->cur_pos == src->buf_size)
		return (END_OF_SOURCE);
	return (src->buffer[src->cur_pos + 1]);
}
