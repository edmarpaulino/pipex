/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:42:33 by edpaulin          #+#    #+#             */
/*   Updated: 2021/09/30 16:52:21 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	The strrchr() function locates the last occurrence of c (converted to a
*	char) in the string pointed to by s.  The terminating null character is
*	considered to be part of the string; therefore if c is `\0', the
*	function locate the terminating `\0'.
*
*	RETURN VALUES
*	The function strrchr() return a pointer to the located character, or
*	NULL if the character does not appear in the string.
*/

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = NULL;
	while (*s)
	{
		if (*s == (char)c)
			ptr = (char *)s;
		++s;
	}
	if (*s == (char)c)
		ptr = (char *)s;
	return (ptr);
}
