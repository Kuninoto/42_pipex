# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 15:03:56 by nnuno-ca          #+#    #+#              #
#    Updated: 2023/01/29 03:23:30 by nnuno-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -I./mandatory/includes/
VPATH = mandatory mandatory/srcs mandatory/srcs/utils
LIBFT = ./libft/libft.a
RM = rm -rf

UTILS = destroy panic
GENERAL = init_data exec_pipe

NAME = pipex
SRCS = $(addsuffix .c, $(UTILS))\
	   $(addsuffix .c, $(GENERAL))\
	   main.c
OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o pipex

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all pipex clean fclean re

.SILENT:
