# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knedzing <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/05 10:58:35 by knedzing          #+#    #+#              #
#    Updated: 2018/08/15 08:44:29 by knedzing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3D

SRC = main.c \
	  drawer.c \
	  drawline.c \
	  get_next_line/get_next_line.c \
	  handle_key_press.c \
	  cross.c \
	  errors.c \
	  inits.c \

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

FLAGSMLX = -L/usr/local/include -lmlx -framework OpenGL -framework AppKit

LIBFT = -L./get_next_line/libft -lft

CC = gcc

INCLUDES = ./includes

LIBFT_PATH = ./get_next_line/libft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) -I$(INCLUDES)  $(FLAGSMLX) $(LIBFT)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all
