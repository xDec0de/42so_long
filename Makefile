# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danimart <danimart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 10:19:42 by danimart          #+#    #+#              #
#    Updated: 2022/05/10 14:06:26 by danimart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# LMLX = -lmlx -framework OpenGL -framework AppKit
MLXFLAG = -lmlx -lXext -lX11

C_FILES =	so_long.c\
			map_reader.c\
			gnl.c strutils.c\
			map_handler.c\
			player_handler.c

O_FILES = $(C_FILES:.c=.o)

all: $(NAME)

$(NAME): $(O_FILES)
	$(CC) $(C_FLAGS) $(O_FILES) $(LMLX) -o $(NAME)

clean:
	rm -rf $(O_FILES)

fclean:
	rm -rf $(O_FILES) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
