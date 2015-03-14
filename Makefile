# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chuang <chuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/14 17:34:15 by chuang            #+#    #+#              #
#    Updated: 2015/03/14 18:25:18 by chuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS = -Wall -Werror -Wextra

SRC = get_next_line.c\
	  main.c\
	  print.c\
	  retrieve.c\
	  tracer.c\

OBJS = $(SRC:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	Make -C libft
	Make -C minilibx_macos
	gcc $(OBJS) -L ./libft  -L ./minilibx_macos -lft -o $(NAME)

%.o:%.c
	gcc -o $@ -c $< $(CFLAGS) -I./includes -I./libft/includes

fclean:
	make -C libft clean
	rm -f $(OBJS)

re: fclean all

.PHONY: all clean fclean re
