# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 15:20:52 by edpaulin          #+#    #+#              #
#    Updated: 2021/10/23 19:13:04 by edpaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex

MAN				=	$(UTLSS) $(SRCSS)

SRC				=	./sources
SRCS			=	ft_main.c \
					ft_init.c \
					ft_get_sys_path.c \
					ft_clear_memory.c \
					ft_pipex.c \
					ft_get_cmd_path.c \
					ft_error_message.c

UTL				=	./utils
UTLS			=	ft_strlen.c \
					ft_strlcpy.c \
					ft_putendl_fd.c \
					ft_strchr.c \
					ft_strjoin.c \
					ft_split.c \
					ft_clear_split.c \
					ft_strncmp.c \
					ft_strtrim.c \
					ft_substr.c \
					ft_strdup.c
UTLSS			=	$(addprefix $(UTL)/, $(UTLS))
SRCSS			=	$(addprefix $(SRC)/, $(SRCS))

OBJ				=	./objects
OBJS			=	$(addprefix $(OBJ)/, $($(basename MAN):.c=.o))

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
INC				=	-I ./includes

FS				=	-fsanitize=address -g3

DIR				=	mkdir -p $(@D)
AR				=	ar -rcs
RM				=	rm -rf

.DEFAULT_GOAL	=	all

all:		$(NAME)

$(OBJ)/%.o:		%.c
	$(DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME)

fsan:	$(OBJS)
	$(CC) $(CFLAGS) $(FS) $(INC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

rf:			fclean fsan

.PHONY:		all fsan clean fclean re rf
