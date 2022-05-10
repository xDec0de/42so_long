# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danimart <danimart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 10:19:42 by danimart          #+#    #+#              #
#    Updated: 2022/05/10 13:11:55 by danimart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long
CC=gcc

INPUT_ERR?=Error\n\e[0;31mInvalid input, usage\e[1;30m:\
 \e[0;33m./so_long map_name.ber\e[1;30m.\e[0m

MAP_FORMAT_ERR?=Error\n\e[0;31mInvalid map format, maps must match\
 \e[0;33mmap_name.ber\e[1;30m.\e[0m

MAP_OPEN_ERR?=Error\n\e[0;31mMap file could not be opened,\
wrong name maybe?\e[0m

MAP_EMPTY_ERR?=Error\n\e[0;31mInvalid map content\e[1;30m:\
\e[0;31mMap is empty\e[1;30m.\e[0m

MAP_CONTENT_ERR?=Error\n\e[0;31mInvalid map content\e[1;30m:\
\e[0;31mMap contains illegal characters\e[1;30m.\e[0m

MAP_LEN_ERR?=Error\n\e[0;31mInvalid map content\e[1;30m:\
\e[0;31mMap is not a rectangle, some lines are so_long haha\e[1;30m.\e[0m

MAP_SIZE_ERR?=Error\n\e[0;31mInvalid map content\e[1;30m:\
\e[0;31mMap is too big, max map dimensions are \e[0;33m1024x1024\e[1;30m.\e[0m

MAP_STRCT_ERR?=Error\n\e[0;31mInvalid map content\e[1;30m:\
\e[0;31mMap must be closed with walls\e[1;30m.\e[0m

MAP_OBJ_ERR?=Error\n\e[0;31mInvalid map content\e[1;30m:\
\e[0;31mRequired objects are missing \e[1;30m(\e[0;31mMap\
must have at least one exit and one collectable\e[1;30m).\e[0m

MAP_PLYR_ERR?=Error\n\e[0;31mInvalid map content\e[1;30m:\
\e[0;31mMap must have one player\e[1;30m.\e[0m

MLX_ERR?=Error\n\e[0;31mMlx error\e[1;30m.\e[0m

CFLAGS= -DINPUT_ERR='"$(INPUT_ERR)"' -DMAP_FORMAT_ERR='"$(MAP_FORMAT_ERR)"'\
-DMAP_OPEN_ERR='"$(MAP_OPEN_ERR)"' -DMAP_EMPTY_ERR='"$(MAP_EMPTY_ERR)"'\
-DMAP_CONTENT_ERR='"$(MAP_CONTENT_ERR)"' -DMAP_SIZE_ERR='"$(MAP_SIZE_ERR)"'\
-DMAP_LEN_ERR='"$(MAP_LEN_ERR)"' -DMAP_STRCT_ERR='"$(MAP_STRCT_ERR)"'\
-DMAP_OBJ_ERR='"$(MAP_OBJ_ERR)"' -DMAP_PLYR_ERR='"$(MAP_PLYR_ERR)"'\
-DNAME='"$(NAME)"' -DMLX_ERR='"$(MLX_ERR)"' -Wall -Werror -Wextra

SANITIZE=-g3 -fsanitize=address
C_FILES=so_long.c map_reader.c gnl.c strutils.c map_handler.c player_handler.c
LMLX = -lmlx -framework OpenGL -framework AppKit

O_FILES=$(C_FILES:.c=.o)

all: $(NAME)
headermk:
	@printf "\n\e[1;31m> \e[1;36mMaking \e[1;34m$(NAME)\e[1;36m...\
	\n\n\e[0;35mCommands\e[1;30m:\n"
$(NAME): headermk $(O_FILES)
	@printf "\n\e[0;33m-\e[1;32m "
	$(CC)$(C_FLAGS) $(O_FILES) $(LMLX) -o $(NAME)
	@printf "\n\033[0m"
clean:
	@printf "\n\e[1;31m> \e[1;36mRemoving \e[1;34m$(NAME)\e[1;36m's objects...\
	\e[1;30m\n\n"
	@printf "\e[0;33m-\e[1;32m "
	rm -rf $(O_FILES)
	@printf "\n\033[0m"
fclean:
	@printf "\n\e[1;31m> \e[1;36mRemoving \e[1;34m$(NAME)\e[1;36m...\
	\e[1;30m\n\n"
	@printf "\e[0;33m-\e[1;32m "
	rm -rf $(NAME) $(O_FILES)
	@printf "\n\033[0m"
sanitize: headermk $(O_FILES)
	@printf "\n\e[1;31m- \e[0;33mSanitize enabled\n\e[0;33m-\e[1;32m "
	$(CC)$(C_FLAGS) $(O_FILES) $(LMLX) -o $(NAME) $(SANITIZE)
	@printf "\n\033[0m"
re: fclean $(NAME)
.PHONY: all clean fclean re