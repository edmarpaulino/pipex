/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:16:06 by edpaulin          #+#    #+#             */
/*   Updated: 2021/09/30 17:09:42 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	The strdup() function allocates sufficient memory for a copy of the
*	string s1, does the copy, and returns a pointer to it. The pointer may
*	subsequently be used as an argument to the function free(3).
*
*	If insufficient memory is available, NULL is returned and errno is set
*	to ENOMEM.
*/

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ptr;

	len = (ft_strlen(s1) + 1);
	ptr = (char *)malloc(len * sizeof(*s1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, len);
	return (ptr);
}
