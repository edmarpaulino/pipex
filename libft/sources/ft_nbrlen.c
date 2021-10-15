/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:18:47 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/07 22:07:08 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(ssize_t nbr, int base)
{
	size_t	len;

	len = 0;
	while (nbr != 0)
	{
		nbr /= base;
		++len;
	}
	return (len);
}
