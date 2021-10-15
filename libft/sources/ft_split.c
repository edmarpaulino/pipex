/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:49:37 by edpaulin          #+#    #+#             */
/*   Updated: 2021/09/30 17:14:39 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	Allocates (with malloc(3)) and returns an array of strings obtained by
*	splitting ’s’ using the character ’c’ as a delimiter. The array must be
*	ended by a NULL pointer.
*
*	RETURN VALUES
*	The array of new strings resulting from the split.
*	NULL if the allocation fails.
*/

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
		return (NULL);
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
			return (NULL);
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
		return (NULL);
	count = ft_count_split(s, c);
	split = (char **)malloc((count + 1) * sizeof(*split));
	if (!split)
		return (NULL);
	return (ft_get_split(split, (char *)s, c, count));
}
