/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:07:51 by edpaulin          #+#    #+#             */
/*   Updated: 2021/09/30 17:15:51 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	Applies the function ’f’ to each character of the string ’s’ to create
*	a new string (with malloc(3)) resulting from successive applications of 
*	’f’.
*
*	RETURN VALUES
*	The string created from the successive applications of ’f’. Returns
*	NULL if the allocation fails.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	new_str = (char *)malloc((ft_strlen(s) + 1) * sizeof(*new_str));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = (*f)(i, s[i]);
		++i;
	}
	new_str[i] = '\0';
	return (new_str);
}
