# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 15:20:52 by edpaulin          #+#    #+#              #
#    Updated: 2021/10/27 21:25:33 by edpaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex
BONUS_NAME		=	pipex_bonus
BIN_DIR			=	./binaries
MANDATORY_BIN	=	$(addprefix $(BIN_DIR)/, $(NAME))
BONUS_BIN		=	$(addprefix $(BIN_DIR)/, $(BONUS_NAME))

SHARED_DIR		=	shared
SHARED_FILES	=	ft_print_error_message.c \
					ft_get_system_path.c
SHARED_PATH		=	$(addprefix $(SHARED_DIR)/, $(SHARED_FILES))

UTIL_DIR		=	utils
UTIL_FILES		=	ft_strlen.c \
					ft_putendl_fd.c \
					ft_strncmp.c \
					ft_strtrim.c \
					ft_strchr.c \
					ft_substr.c \
					ft_strdup.c \
					ft_split.c \
					ft_strlcpy.c \
					ft_strjoin.c \
					ft_clear_split.c
UTIL_PATH		=	$(addprefix $(UTIL_DIR)/, $(UTIL_FILES))

SRC_DIR			=	./sources
SRC_FILES		=	ft_main.c \
					ft_pipex.c \
					$(SHARED_PATH) \
					$(UTIL_PATH)

BONUS_DIR		=	./sources
BONUS_FILES		=	$(SHARED_PATH) \
					$(UTIL_PATH)

OBJ_DIR			=	./objects
OBJ_FILES		=	$(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
OBJ_BONUS_FILES	=	$(addprefix $(OBJ_DIR)/, $(BONUS_FILES:.c=.o))

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
INC				=	-I ./includes

# FIXME		->		REMOVE FSANITIZE
FS				=	-fsanitize=address -g3

MKDIR			=	mkdir -p $(@D)
AR				=	ar -rcs
RM				=	rm -rf

.DEFAULT_GOAL	=	all

all:				$(NAME)

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
	$(MKDIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME):			$(MANDATORY_BIN)

$(MANDATORY_BIN):	$(OBJ_FILES)
	$(MKDIR)
	$(RM) $(BONUS_BIN)
	$(CC) $(CFLAGS) $(FS) $(INC) $(OBJ_FILES) -o $(MANDATORY_BIN)
	cp $(MANDATORY_BIN) $(NAME)

bonus:				$(BONUS_BIN)

$(BONUS_BIN):		$(OBJ_BONUS_FILES)
	$(MKDIR)
	$(RM) $(MANDATORY_BIN)
	$(CC) $(CFLAGS) $(FS) $(INC) $(OBJ_BONUS_FILES) -o $(BONUS_BIN)
	cp $(BONUS_BIN) $(NAME)

clean:
	$(RM) $(OBJ_DIR) $(BIN_DIR)

fclean:				clean
	$(RM) $(NAME)

re:					fclean all

rebonus:			fclean bonus 

.PHONY:				all bonus clean fclean re rebonus
