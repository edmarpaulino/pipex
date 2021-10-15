/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:41:28 by edpaulin          #+#    #+#             */
/*   Updated: 2021/09/30 16:51:08 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	The strchr() function locates the first occurrence of c (converted to a
*	char) in the string pointed to by s.  The terminating null character is
*	considered to be part of the string; therefore if c is `\0', the
*	function locate the terminating `\0'.
*
*	RETURN VALUES
*	The function strchr() return a pointer to the located character, or
*	NULL if the character does not appear in the string.
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		++s;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
