# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 10:19:42 by daniema3          #+#    #+#              #
#    Updated: 2025/03/07 14:55:50 by daniema3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -I minilibx-linux
MLXFLAGS = -L minilibx-linux/ -lmlx -lXext -lX11

SRCS =	util/sl_calloc.c\
		util/sl_strchr.c\
		util/sl_strdup.c\
		util/sl_strjoin.c\
		util/sl_strlcpy.c\
		util/sl_strlen.c\
		util/sl_substr.c\
		util/printf/ft_printf.c\
		util/printf/write_num.c\
		util/printf/write_txt.c\
		so_long.c\
		map_reader.c\
		map_validator.c\
		gameplay_validator.c\
		asset_handler.c\
		player_handler.c\
		exit_sl.c

H_FILES =	so_long.h\
			util/sl_utils.h\
			util/printf/ft_printf.h

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
	norminette ${SRCS} ${H_FILES}

.PHONY: all clean fclean re norm
