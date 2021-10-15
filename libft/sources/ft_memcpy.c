/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:30:35 by edpaulin          #+#    #+#             */
/*   Updated: 2021/09/30 16:42:47 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	The memcpy() function copies n bytes from memory area src to memory
*	area dst.  If dst and src overlap, behavior is undefined.  Applications
*	in which dst and src might overlap should use memmove(3) instead.
*
*	RETURN VALUES
*	The memcpy() function returns the original value of dst.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (!dst && !src)
		return (NULL);
	while (n--)
		*(unsigned char *)(dst++) = *(unsigned char *)(src++);
	return (dst);
}
