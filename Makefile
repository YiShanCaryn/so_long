# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yisho <yisho@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 13:11:07 by yisho             #+#    #+#              #
#    Updated: 2025/02/18 14:21:02 by yisho            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Igame_code -Ilibft -Imlx_linux -I/usr/include -O3

NAME = so_long

SRC = game_code/so_long.c \
	game_code/map_reader.c \
	game_code/map_check.c \
	game_code/exit_game.c \
	game_code/setting.c \
	game_code/window_reader.c\
	game_code/movement.c\
	game_code/move_check.c\
	game_code/floodfill_check.c\

OBJ = $(SRC:.c=.o)

MLX_DIR = mlx_linux

LIBFT = libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

all: $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
