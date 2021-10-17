# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/15 08:58:03 by edpaulin          #+#    #+#              #
#    Updated: 2021/10/16 11:56:32 by edpaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=pipex
LIBFT=./libft/libft.a
SRC=./sources
SRCS=main.c get_path.c pipex.c
OBJ=./objects
OBJS=$(addprefix $(OBJ)/, $(SRCS:.c=.o))
CC=cc
CFLAGS=-Wall -Wextra -Werror
INC=-I ./includes -I ./libft/includes
AR=ar rcs
RM=rm -rf
MKDIR=mkdir -p $(@D)
FSAN=-fsanitize=address -g3

.DEFAULT_GOAL:	all

all: $(NAME)

$(OBJ)/%.o:$(SRC)/%.c
	$(MKDIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBFT) -o $@

$(LIBFT):
	make -C ./libft

fsan: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(FSAN) $(INC) $(OBJS) $(LIBFT) -o $(NAME)

bonus:

clean:
	make clean -C ./libft
	$(RM) $(OBJ)

fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

norm:
	norminette */*

.PHONY: all bonus clean fclean re
