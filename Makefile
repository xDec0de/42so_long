# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 10:19:42 by daniema3          #+#    #+#              #
#    Updated: 2025/03/04 17:27:28 by daniema3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I minilibx-linux
MLXFLAGS = -L minilibx-linux/ -lmlx -lXext -lX11

SRCS =	strutils.c\
		gnl.c\
		printf/ft_printf.c\
		printf/write_num.c\
		printf/write_txt.c\
		so_long.c\
		map_reader.c\
		map_validator.c\
		asset_handler.c\
		player_handler.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS) $(NAME)

re: fclean $(NAME)

norm:
	norminette ${SRCS} so_long.h

.PHONY: all clean fclean re norm
