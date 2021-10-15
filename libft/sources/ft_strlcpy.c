/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:33:38 by edpaulin          #+#    #+#             */
/*   Updated: 2021/09/30 16:48:19 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	The strlcpy() function copy strings with the same input parameters and
*	output result as snprintf(3).  It is designed to be safer, more
*	consistent, and less error prone replacements for the easily misused
*	function strncpy(3).
*
*	The strlcpy() take the full size of the destination buffer and
*	guarantee NUL-termination if there is room.  Note that room for the NUL
*	should be included in dstsize.
*
*	The strlcpy() copies up to dstsize - 1 characters from the string src
*	to dst, NUL-terminating the result if dstsize is not 0.
*
*	If the src and dst strings overlap, the behavior is undefined.
*
*	RETURN VALUES
*	Besides quibbles over the return type (size_t versus int) and signal
*	handler safety (snprintf(3) is not entirely safe on some systems), the
*	following two are equivalent:
*
*		n = strlcpy(dst, src, len);
*		n = snprintf(dst, len, "%s", src);
*
*	Like snprintf(3), the strlcpy() function return the total length of the
*	string they tried to create, that means the length of src.
*
*	If the return value is >= dstsize, the output string has been
*	truncated.  It is the caller's responsibility to handle this.
*/

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
