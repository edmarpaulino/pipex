/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:43:56 by edpaulin          #+#    #+#             */
/*   Updated: 2021/09/30 16:52:57 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	The strncmp() function lexicographically compare the null-terminated
*	strings s1 and s2.
*
*	The strncmp() function compares not more than n characters.  Because
*	strncmp() is designed for comparing strings rather than binary data,
*	characters that appear after a `\0' character are not compared.
*
*	RETURN VALUES
*	The strncmp() function return an integer greater than, equal to, or
*	less than 0, according as the string s1 is greater than, equal to, or
*	less than the string s2.  The comparison is done using unsigned
*	characters, so that `\200' is greater than `\0'.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (*s1 && *s2 && *s1 == *s2 && --n)
	{
		++s1;
		++s2;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
