/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:23:44 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/05 16:45:58 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "printf/ft_printf.h"

# define BUFFER_SIZE 1024

# define MAX_MAP_HEIGHT 1024
# define MAX_MAP_LENGTH 1024

# define INPUT_ERR "Error\n\e[0;31mInvalid input, usage\e[1;30m: \
 \e[0;33m./so_long map_name.ber\e[1;30m.\e[0m"
# define INPUT_ERRC 1

# define MAP_EXTENSION_ERR "Error\n\e[0;31mInvalid map format, maps must have \
the \e[0;33m.ber \e[0;31mIextension\e[1;30m.\e[0m"
# define MAP_EXTENSION_ERRC 2

# define MALLOC_ERR "Error\n\e[0;31mMalloc failed\e[1;30m.\e[0m"
# define MALLOC_ERRC 3

# define MAP_OPEN_ERR "Error\n\e[0;31mMap file could not be opened, \
wrong name maybe?\e[0m"
# define MAP_OPEN_ERRC 4

# define READ_ERR "Error\n\e[0;31mRead failed\e[1;30m.\e[0m"
# define READ_ERRC 4

# define MAP_EMPTY_ERR "Error\n\e[0;31mInvalid map content\e[1;30m: \
\e[0;31mMap is empty\e[1;30m.\e[0m"

# define MAP_CONTENT_ERR "Error\n\e[0;31mInvalid map content\e[1;30m: \
\e[0;31mMap contains illegal characters\e[1;30m.\e[0m"

# define MAP_LEN_ERR "Error\n\e[0;31mInvalid map content\e[1;30m: \
\e[0;31mMap is not a rectangle, some lines are... So_long\e[1;30m.\e[0m"

# define MAP_SIZE_ERR "Error\n\e[0;31mInvalid map content\e[1;30m:\
 \e[0;31mMap is too big.\e[1;30m.\e[0m"

# define MAP_STRCT_ERR "Error\n\e[0;31mInvalid map content\e[1;30m: \
\e[0;31mMap must be closed with walls\e[1;30m.\e[0m"

# define MAP_OBJ_ERR "Error\n\e[0;31mInvalid map content\e[1;30m: \
\e[0;31mMissing or too many objects. \e[1;30m(\e[0;31mMap\
 must have only one exit, one player and at least one\
 collectable\e[1;30m).\e[0m"

# define MAP_IMPOSSIBLE "Error\n\e[0;31mInvalid map content\e[1;30m: \
\e[0;31mMap is impossible to win, please nerf\e[1;30m.\e[0m"

# define MLX_ERR "Error\n\e[0;31mMlx error\e[1;30m.\e[0m"

# define WINDOW_TITLE "so_long"

# define ASSET_SIZE 16
# define ASSET_WALL "./assets/wall.xpm"
# define ASSET_KEY "./assets/key.xpm"
# define ASSET_DOOR "./assets/door.xpm"
# define ASSET_BG "./assets/bg.xpm"
# define ASSET_PLAYER "./assets/player.xpm"

# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_player
{
	int		x;
	int		y;
}				t_player;

typedef struct s_assets
{
	void		*wall;
	void		*key;
	void		*bg;
	void		*exit;
	void		*player;
}				t_assets;

typedef struct s_map
{
	char		**arr;
	char		*verify_arr[MAX_MAP_HEIGHT];
	int			height;
	int			length;
	int			keys;
	int			exits;
	int			movements;
	void		*mlx;
	void		*win;
	t_assets	assets;
	t_player	pl;
}				t_map;

// so_long.c
int		handle_key(int keycode, t_map *map);

// map_reader.c
void	parse_map_input(char **args);

// map_validator.c
void	validate_map_content(t_map map);

// asset_handler.c
void	update_asset(t_map *map, int x, int y);
void	draw_map(t_map *map);

// player_handler.c
int		move_player(t_map *map, int x, int y);

// gnl.c
char	*get_next_line(int fd);

/*
 - String utility (strutils.c)
 */

int		ft_strlen(const char *str, int ignore_new_line);
char	*ft_strdup(char *s);
int		ft_strchr(char *s, char ch);

/**
 * @brief Joins two strings (`s1` and `s2`). Optionally
 * freeing both strings.
 * 
 * @param s1 The first string, will be at the beginning of
 * the new string.
 * @param s2 The second string, will be appeneded to `s2` on
 * a new string.
 * @param free_strs Whether to free `s1` and `s2` or not.
 * 
 * @return A new string allocated with `malloc`. The
 * length of this string will be the length of `s1` + `s2`,
 * reserving one extra space to null-terminate the string.
 * `NULL` will be returned if either `s1` or `s2` are `NULL`,
 * or if `malloc` fails to allocate the new string.
 */
char	*ft_strjoin(char *s1, char *s2, int free_strs);

char	*ft_substr(char *s, int start, int len);

/*
 - Free & exit (exit_sl.c)
 */
int		user_end(t_map *map);
void	exit_sl(t_map *map, char *msg, int code);

#endif