/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:24:00 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/27 21:25:02 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ptr;

	len = (ft_strlen(s1) + 1);
	ptr = (char *)malloc(len * sizeof(*s1));
	if (!ptr)
		return (FT_NULL);
	ft_strlcpy(ptr, s1, len);
	return (ptr);
}
