/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_argument_vector.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:53:31 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/18 18:00:19 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shared.h"

static int	ft_handle_quotes(t_source *src, char *buffer, int i, char next_char)
{
	char	quote_pair;

	if (i != 0)
		ft_give_back_char(src);
	else
	{
		quote_pair = next_char;
		next_char = ft_get_next_char(src);
		while (quote_pair != next_char && next_char != END_OF_SOURCE)
		{
			buffer[i] = next_char;
			i++;
			next_char = ft_get_next_char(src);
		}
		if (next_char == END_OF_SOURCE)
		{
			free(buffer);
			return (-1);
		}
		ft_get_next_char(src);
	}
	return (i);
}

static char	*ft_get_token(t_source *src)
{
	char	*buffer;
	char	*token;
	char	next_char;
	int		i;

	buffer = ft_calloc((src->buf_size - src->cur_pos) + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	i = 0;
	ft_skip_white_spaces(src);
	next_char = ft_get_next_char(src);
	while (next_char != END_OF_SOURCE && i < src->buf_size)
	{
		if (ft_isspace(next_char))
			break ;
		else if ((next_char == '\'' || next_char == '\"') && i == 0)
		{
			i = ft_handle_quotes(src, buffer, i, next_char);
			if (i == -1)
				return (NULL);
			break ;
		}
		else
			buffer[i] = next_char;
		next_char = ft_get_next_char(src);
		i++;
	}
	buffer[i] = '\0';
	token = ft_strdup(buffer);
	free(buffer);
	if (!token)
		return (NULL);
	return (token);
}

static char	*ft_tokenize(t_source *src)
{
	char	*tok;

	if (!src || !src->buffer || src->buf_size == 0)
		return (NULL);
	if (src->cur_pos >= src->buf_size)
		return (NULL);
	tok = ft_get_token(src);
	if (!tok)
		return (NULL);
	return (tok);
}

static t_source	*ft_get_source(char *str)
{
	t_source	*src;

	src = malloc(sizeof(t_source));
	if (!src)
		return (NULL);
	src->buffer = ft_strdup(str);
	if (!src->buffer)
	{
		free(src);
		return (NULL);
	}
	src->buf_size = ft_strlen(src->buffer);
	src->cur_pos = -1;
	return (src);
}

char	**ft_get_argument_vector(char *str)
{
	t_source	*src;
	char		**argv;
	int			i;

	if (!str)
		return (NULL);
	src = ft_get_source(str);
	if (!src)
		return (NULL);
	argv = ft_calloc((src->buf_size / 2) + 1, sizeof(char *));
	if (!argv)
		return (NULL);
	i = 0;
	while (i < src->buf_size)
	{
		argv[i] = ft_tokenize(src);
		if (!argv[i])
			break ;
		i++;
	}
	free(src->buffer);
	free(src);
	argv[i] = NULL;
	return (argv);
}
