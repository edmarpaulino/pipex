# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/07 16:04:57 by edpaulin          #+#    #+#              #
#    Updated: 2021/10/13 12:15:14 by edpaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a

SRC				=	./sources
SRCS			=	ft_isalpha.c \
					ft_isdigit.c \
					ft_isalnum.c \
					ft_isascii.c \
					ft_isprint.c \
					ft_strlen.c \
					ft_memset.c \
					ft_bzero.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_strlcpy.c \
					ft_strlcat.c \
					ft_toupper.c \
					ft_tolower.c \
					ft_strchr.c \
					ft_strrchr.c \
					ft_strncmp.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_strnstr.c \
					ft_atoi.c \
					ft_calloc.c \
					ft_strdup.c \
					ft_substr.c \
					ft_strjoin.c \
					ft_strtrim.c \
					ft_split.c \
					ft_itoa.c \
					ft_strmapi.c \
					ft_striteri.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_lstnew.c \
					ft_lstadd_front.c \
					ft_lstsize.c \
					ft_lstlast.c \
					ft_lstadd_back.c \
					ft_lstdelone.c \
					ft_lstclear.c \
					ft_lstiter.c \
					ft_lstmap.c \
					ft_strcmp.c \
					ft_strupper.c \
					ft_strlower.c \
					ft_strnlen.c \
					ft_nbrlen.c \
					ft_atof.c \
					ft_iswhitespace.c \
					ft_signal.c \
					ft_lastchr.c \
					ft_word_counter.c \
					ft_clear_split.c \
					get_next_line.c

INCS			=	-I ./includes

OBJ				=	./objects
OBJS			=	$(addprefix $(OBJ)/,$(SRCS:.c=.o))

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

RM				=	rm -rf

AR				=	ar rcs

.DEFAULT_GOAL	=	all

all:		$(NAME)

$(OBJ)/%.o:	$(SRC)/%.c
			mkdir -p $(@D)
			$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJ)/*.o

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re