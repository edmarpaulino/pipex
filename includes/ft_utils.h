/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:23:24 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/28 10:34:05 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# define FT_ERROR -1
# define FT_SUCCESS 1
# define FT_STDIN 0
# define FT_STDOUT 1
# define FT_STDERR 2
# define FT_NULL ((void *)0)
# define CHILD_PROCESS 0

// access - close - read - write - pipe - dup2 - execve - fork
# include <unistd.h>

// open
# include <fcntl.h>

// malloc - free
# include <stdlib.h>

// waitpid
# include <sys/wait.h>

// perror
# include <stdio.h>
# include <errno.h>

size_t	ft_strlen(const char *s);
void	ft_putendl_fd(char *str, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_clear_split(char **ptr);

#endif