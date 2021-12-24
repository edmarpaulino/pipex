/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:05:51 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/27 21:06:33 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	if (!src)
		return (0);
	src_len = ft_strlen(src);
	if (dstsize)
	{
		while (--dstsize && *src)
			*(dst++) = *(src++);
		*dst = '\0';
	}
	return (src_len);
}
