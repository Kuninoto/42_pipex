# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 15:03:56 by nnuno-ca          #+#    #+#              #
#    Updated: 2023/01/07 23:05:01 by nnuno-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBFT = ./libft/libft.a

NAME = pipex
SRCS = mandatory/srcs/get_nbr_args.c\
	   mandatory/srcs/exec_pipe.c\
	   mandatory/main.c
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = bonus/srcs/utils/get_nbr_args.c\
			 bonus/srcs/init_cmd_list.c\
			 bonus/srcs/exec_pipe.c\
			 bonus/srcs/utils/destroy_cmd_list.c\
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

.SILENT: