/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:35:04 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/07 21:16:46 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	
*	DESCRIPTION
*	The strlcat() function concatenate strings with the same input
*	parameters and output result as snprintf(3).  It is designed to be
*	safer, more consistent, and less error prone replacements for the
*	easily misused function strncat(3).
*
*	The strlcat() take the full size of the destination buffer and
*	guarantee NUL-termination if there is room.  Note that room for the NUL
*	should be included in dstsize.
*
*	The strlcat() appends string src to the end of dst.  It will append at
*	most dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate,
*	unless dstsize is 0 or the original dst string was longer than dstsize
*	(in practice this should not happen as it means that either dstsize is
*	incorrect or that dst is not a proper string).
*
*	If the src and dst strings overlap, the behavior is undefined.
*
*	RETURN VALUES
*	Like snprintf(3), the strlcat() function return the total length of the
*	string they tried to create, that means the initial length of dst plus
*	the length of src.
*
*	If the return value is >= dstsize, the output string has been
*	truncated.  It is the caller's responsibility to handle this.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	src_len = (ft_strlen(src));
	dst_len = ft_strnlen(dst, dstsize);
	if (dstsize == dst_len)
		return (src_len + dstsize);
	dst += dst_len;
	while (--dstsize > dst_len && *src)
		*(dst++) = *(src++);
	*dst = '\0';
	return (dst_len + src_len);
}
