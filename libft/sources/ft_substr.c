/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:20:16 by edpaulin          #+#    #+#             */
/*   Updated: 2021/09/30 17:10:55 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	Allocates (with malloc(3)) and returns a substring from the string ’s’.
*	The substring begins at index ’start’ and is of maximum size ’len’.
*
* RETURN VALUES
*	The substring. NULL if the allocation fails.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_start_len;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	s_start_len = ft_strlen((s + start));
	if (s_start_len < len)
		len = s_start_len;
	++len;
	sub = (char *)malloc(len * sizeof(*sub));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, (s + start), len);
	return (sub);
}
