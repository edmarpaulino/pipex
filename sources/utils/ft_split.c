/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:04:27 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/27 21:05:40 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

static size_t	ft_count_split(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			++count;
		++s;
	}
	return (count);
}

static size_t	ft_splitlen(char const *split, char c)
{
	size_t	len;

	len = 0;
	while (split[len] != c && split[len])
		++len;
	return (len);
}

static char	*ft_splitcpy(char const *src, char c)
{
	size_t	len;
	char	*dst;

	len = (ft_splitlen(src, c) + 1);
	dst = (char *)malloc(len * sizeof(*dst));
	if (!dst)
		return (FT_NULL);
	ft_strlcpy(dst, src, len);
	return (dst);
}

static char	**ft_get_split(char **split, char *str, char c, size_t count)
{
	size_t	index;

	index = 0;
	while (index < count)
	{
		if (index)
			str = ft_strchr(str, c);
		while (*str == c)
			++str;
		split[index] = ft_splitcpy(str, c);
		if (!split[index])
		{
			while (index--)
				free(split[index]);
			return (FT_NULL);
		}
		++index;
	}
	split[index] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	count;

	if (!s)
		return (FT_NULL);
	count = ft_count_split(s, c);
	split = (char **)malloc((count + 1) * sizeof(*split));
	if (!split)
		return (FT_NULL);
	return (ft_get_split(split, (char *)s, c, count));
}
