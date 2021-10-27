# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 15:20:52 by edpaulin          #+#    #+#              #
#    Updated: 2021/10/27 19:36:51 by edpaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex
BONUS_NAME		=	pipex_bonus
BIN_DIR			=	./binaries
MANDATORY_BIN	=	$(addprefix $(BIN_DIR)/, $(NAME))
BONUS_BIN		=	$(addprefix $(BIN_DIR)/, $(BONUS_NAME))

SHARED_DIR		=	shared
SHARED_FILES	=	
SHARED_PATH		=	$(addprefix $(SHARED_DIR)/, $(SHARED_FILES))

UTIL_DIR		=	utils
UTIL_FILES		=	
UTIL_PATH		=	$(addprefix $(UTIL_DIR)/, $(UTIL_FILES))

SRC_DIR			=	./sources
SRC_FILES		=	$(SHARED_PATH) \
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
