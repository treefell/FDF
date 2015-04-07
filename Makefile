# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chuang <chuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/14 17:34:15 by chuang            #+#    #+#              #
#    Updated: 2015/03/24 21:47:28 by chuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS = -Wall -Werror -Wextra

SRC = get_next_line.c\
	  main.c\
	  print.c\
	  retrieve.c\
	  tracer.c\
	  color.c

OBJS = $(SRC:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	Make -C libft
	Make -C minilibx_macos
	gcc $(OBJS) -I libft -L ./libft -L ./minilibx_macos -framework OpenGL -framework AppKit -lft -lmlx -o $(NAME)

%.o:%.c
	gcc -o $@ -c $< $(CFLAGS) -I./includes -I./libft/includes

fclean:
	make -C libft clean
	$(RM) $(OBJS)
	$(RM) $(NAME)


re: fclean all

.PHONY: all clean fclean re
