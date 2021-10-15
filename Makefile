# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/15 08:58:03 by edpaulin          #+#    #+#              #
#    Updated: 2021/10/15 09:14:21 by edpaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=pipex
SRC=./sources
SRCS=main.c
OBJ=./objects
OBJS=$(addprefix $(OBJ)/, $(SRCS:.c=.o))
CC=cc
CFLAGS=-Wall -Wextra -Werror
INC=-I ./includes
AR=ar rcs
RM=rm -rf
MKDIR=mkdir -p $(@D)

.DEFAULT_GOAL:	all

all: $(NAME)

$(OBJ)/%.o:$(SRC)/%.c
	$(MKDIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INC) $(OBJS) -o $@

bonus:

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
