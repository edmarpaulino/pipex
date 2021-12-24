/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:16:06 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/27 21:16:45 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_str;

	if (!s1 || !s2)
		return (FT_NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *)malloc((s1_len + s2_len + 1) * sizeof(*new_str));
	if (!new_str)
		return (FT_NULL);
	ft_strlcpy(new_str, s1, (s1_len + 1));
	ft_strlcpy((new_str + s1_len), s2, (s2_len + 1));
	return (new_str);
}
