# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/22 19:35:50 by nnuno-ca          #+#    #+#              #
#    Updated: 2023/01/31 01:19:46 by nnuno-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./
VPATH = debug_utils ft_dprintf memory string type_conversion writers
RM = rm -rf
NAME = libft.a

DEBUG_UTILS = print_char_matrix print_int_array
FT_DPRINTF = ft_dprintf prt_hexa prt_int prt_ptr prt_str prt_unsigned
MEMORY = free_matrix ft_bzero ft_calloc ft_memchr\
		 ft_memcmp ft_memcpy ft_memmove ft_memset\
		 matrix_len
STRING =  ft_split ft_strchr ft_strcpy ft_strdup\
		  ft_strjoin ft_strlcat ft_strlcpy ft_strlen\
		  ft_strncmp ft_strnstr ft_strrchr ft_strtrim\
		  ft_substr is_all_digits is_alnum is_alpha\
		  is_only_digits is_only_spaces is_onstr join_free_both\
		  join_free join_freev2 only_spaces streq\
		  trim_free
TYPE_CONVERSION = fits_in_longlong ft_atoi ft_atol ft_atoll\
			  	  ft_itoa ft_lltoa ft_ltoa ft_utoa
WRITERS = ft_putnbr_fd
GENERAL = get_next_line

SRCS = $(addsuffix .c, $(DEBUG_UTILS))\
	   $(addsuffix .c, $(FT_DPRINTF))\
	   $(addsuffix .c, $(MEMORY))\
	   $(addsuffix .c, $(STRING))\
	   $(addsuffix .c, $(TYPE_CONVERSION))\
	   $(addsuffix .c, $(WRITERS))\
	   $(addsuffix .c, $(GENERAL))

OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME) clean

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJS)
	ar rc $(NAME) $(OBJS)
clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re run

.SILENT: