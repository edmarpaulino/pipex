/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:27:33 by edpaulin          #+#    #+#             */
/*   Updated: 2021/09/30 16:37:05 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	The bzero() function writes n zeroed bytes to the string s.
*	If n is zero, bzero() does nothing.
*/

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(unsigned char *)(s++) = 0;
}
