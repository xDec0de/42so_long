# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 10:19:42 by daniema3          #+#    #+#              #
#    Updated: 2025/03/07 15:13:34 by daniema3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
MLX_PATH = minilibx-linux

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ${MLX_PATH}
MLXFLAGS = -L ${MLX_PATH}/ -lmlx -lXext -lX11

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

MLX_MAKEFILE_GEN_FILES =	Makefile.gen\
							${MLX_PATH}/Makefile.gen\
							${MLX_PATH}/test/Makefile.gen


all: $(NAME)

$(NAME): $(OBJS)
	make -C ${MLX_PATH}
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)

clean:
	make clean -C ${MLX_PATH}
	rm -rf $(MLX_MAKEFILE_GEN_FILES)
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(OBJS) $(NAME)

re: fclean $(NAME)

norm:
	norminette ${SRCS} ${H_FILES}

.PHONY: all clean fclean re norm
