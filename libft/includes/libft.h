/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 09:42:29 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/13 10:25:20 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

/*
*	content:	The data contained in the element. The void * allows to store 
*				any	kind of data.
*
*	next:		The next element’s address or NULL if it’s the last element.
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/*************************| PART 1 - LIBC FUNCTIONS |**************************/

//	No external functions

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);

//	Using malloc function

void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);

/*********************| PART 2 - ADDITIONAL FUNCTIONS |***********************/

//	Using malloc function

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

//	Using malloc & free functions

char	**ft_split(char const *s, char c);

//	Using write function

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//	No external functions

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/********************************| BONUS PART |*******************************/

//	Using malloc function

t_list	*ft_lstnew(void *content);

//	Using free function

void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));

//	Using malloc & free functions

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//	No external functions

void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**************************| ADDITIONAL FUNCTIONS |****************************/

int		ft_strcmp(const char *s1, const char *s2);
void	ft_strupper(char *str);
void	ft_strlower(char *str);
size_t	ft_strnlen(const char *str, size_t maxlen);
size_t	ft_nbrlen(ssize_t nbr, int base);
double	ft_atof(const char *str);
int		ft_iswhitespace(int c);
int		ft_signal(char c);
int		ft_lastchr(const char *str);
size_t	ft_word_counter(const char *str);
void	ft_clear_split(char **ptr);

#endif
