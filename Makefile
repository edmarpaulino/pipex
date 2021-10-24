# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 15:20:52 by edpaulin          #+#    #+#              #
#    Updated: 2021/10/24 18:25:52 by edpaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex

SRC_DIR			=	./sources
SRC_FILES		=	ft_main.c \
					ft_init.c \
					ft_get_sys_path.c \
					ft_clear_memory.c \
					ft_pipex.c \
					ft_get_cmd_path.c \
					ft_error_message.c

UTL_DIR			=	./utils
UTL_FILES		=	ft_strlen.c \
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

SRC_PATH		=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))
UTL_PATH		=	$(addprefix $(UTL_DIR)/, $(UTL_FILES))

FILES			=	$(UTL_PATH) $(SRC_PATH)

OBJ_DIR			=	./objects
OBJ_FILES		=	$(addprefix $(OBJ_DIR)/, $($(basename FILES):.c=.o))

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
INC				=	-I ./includes

FS				=	-fsanitize=address -g3

MKDIR			=	mkdir -p $(@D)
AR				=	ar -rcs
RM				=	rm -rf

.DEFAULT_GOAL	=	all

all:		$(NAME)

$(OBJ_DIR)/%.o:		%.c
	$(MKDIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME):	$(OBJ_FILES)
	$(CC) $(CFLAGS) $(INC) $(OBJ_FILES) -o $(NAME)

fsan:	$(OBJ_FILES)
	$(CC) $(CFLAGS) $(FS) $(INC) $(OBJ_FILES) -o $(NAME)

clean:
	$(RM) $(OBJ_DIR)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

rf:			fclean fsan

.PHONY:		all fsan clean fclean re rf
