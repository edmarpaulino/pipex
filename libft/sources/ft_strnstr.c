/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:08:24 by edpaulin          #+#    #+#             */
/*   Updated: 2021/09/30 16:58:10 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	The strnstr() function locates the first occurrence of the
*	null-terminated string needle in the string haystack, where not more
*	than len characters are searched. Characters that appear after a `\0'
*	character are not searched.  Since the strnstr() function is a FreeBSD
*	specific API, it should only be used when portability is not a concern.
*
*	RETURN VALUES
*	If needle is an empty string, haystack is returned; if needle occurs
*	nowhere in haystack, NULL is returned; otherwise a pointer to the first
*	character of the first occurrence of needle is returned.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	if (!needle[0])
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	while (*haystack && len-- >= needle_len)
	{
		if (!ft_strncmp(haystack, needle, needle_len))
			return ((char *)haystack);
		++haystack;
	}
	return (NULL);
}
