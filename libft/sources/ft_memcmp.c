/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:59:06 by edpaulin          #+#    #+#             */
/*   Updated: 2021/09/30 16:57:16 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	The memcmp() function compares byte string s1 against byte string s2.
*	Both strings are assumed to be n bytes long.
*
*	RETURN VALUES
*	The memcmp() function returns zero if the two strings are identical,
*	otherwise returns the difference between the first two differing bytes
*	(treated as unsigned char values, so that `\200' is greater than `\0',
*	for example). Zero-length strings are always identical. This behavior
*	is not required by C and portable code should only depend on the sign
*	of the returned value.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!n)
		return (0);
	while (*(unsigned char *)s1 == *(unsigned char *)s2 && --n)
	{
		++s1;
		++s2;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
