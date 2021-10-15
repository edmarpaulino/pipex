/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_counter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:48:38 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/11 12:21:23 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_word_counter(const char *str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!ft_iswhitespace(str[i]) \
			&& (ft_iswhitespace(str[i + 1]) || !str[i + 1]))
			++count;
		++i;
	}
	return (count);
}
