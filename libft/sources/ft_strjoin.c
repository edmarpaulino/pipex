/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:24:10 by edpaulin          #+#    #+#             */
/*   Updated: 2021/09/30 17:11:53 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	Allocates (with malloc(3)) and returns a new string, which
*	is the result of the concatenation of ’s1’ and ’s2’.
*	RETURN VALUES
*	The new string. NULL if the allocation fails.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *)malloc((s1_len + s2_len + 1) * sizeof(*new_str));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, (s1_len + 1));
	ft_strlcpy((new_str + s1_len), s2, (s2_len + 1));
	return (new_str);
}
