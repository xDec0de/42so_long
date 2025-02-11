# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 10:19:42 by daniema3          #+#    #+#              #
#    Updated: 2025/02/11 14:48:29 by daniema3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I minilibx-linux
#MLXFLAGS = -L mlx/ -lmlx -lXext -lX11

SRCS =	so_long.c\
		map_reader.c\
		gnl.c strutils.c\
		map_handler.c\
		player_handler.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
