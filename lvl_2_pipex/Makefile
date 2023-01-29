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
CFLAGS = -Wall -Wextra -Werror -I./mandatory/includes/
RM = rm -rf
LIBFT = ./libft/libft.a

NAME = pipex
SRCS = mandatory/srcs/utils/destroy.c\
	   mandatory/srcs/utils/panic.c\
	   mandatory/srcs/init_data.c\
	   mandatory/srcs/exec_pipe.c\
	   mandatory/main.c
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = bonus/ \
	   		 bonus/main.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o pipex

bonus: $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o pipex

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)
	
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
	
re: fclean all

run: all clean

.PHONY: all pipex bonus clean fclean re

.SILENT: