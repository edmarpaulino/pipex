/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:00:30 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/27 21:01:12 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_start_len;

	if (!s)
		return (FT_NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	s_start_len = ft_strlen((s + start));
	if (s_start_len < len)
		len = s_start_len;
	++len;
	sub = (char *)malloc(len * sizeof(*sub));
	if (!sub)
		return (FT_NULL);
	ft_strlcpy(sub, (s + start), len);
	return (sub);
}
