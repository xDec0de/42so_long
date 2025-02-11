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

SANITIZE = -g3 -fsanitize=address
C_FILES = so_long.c map_reader.c gnl.c strutils.c map_handler.c player_handler.c

O_FILES = $(C_FILES:.c=.o)

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
