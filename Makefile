# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maducham <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/17 16:11:26 by maducham          #+#    #+#              #
#    Updated: 2016/05/17 16:21:51 by maducham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, fclean, clean, re

NAME = fdf

CC = gcc

LIB = libft/libft.a minilibx_macos/libmlx.a

OBJ = 		main.o \
			calcul_coord.o \
			create_elem.o \
			display_image_to_window.o \
			display_window.o \
			draw_segment.o \
			get_next_line.o \
			hooks.o \
			list_push_back.o \
			parser.o \
			utils.o \

FLAG = -g -Wall -Wextra -Werror

LIBGRPH = -framework OpenGL -framework Appkit

INC = fdf.h

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(FLAG) -o $(NAME) $(LIB) $(OBJ) $(LIBGRPH)

$(LIB):
	make -C libft/
	make -C minilibx_macos/

%.o : %.c $(INC)
	$(CC) -c $(FLAG) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -rf $(NAME)

re: fclean all
