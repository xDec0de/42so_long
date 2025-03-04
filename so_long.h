/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:23:44 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/04 15:34:34 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFFER_SIZE 1024

# define INPUT_ERR "Error\n\e[0;31mInvalid input, usage\e[1;30m: \
 \e[0;33m./so_long map_name.ber\e[1;30m.\e[0m"

# define MAP_FORMAT_ERR "Error\n\e[0;31mInvalid map format, maps must have \
the extension \e[0;33m.ber\e[1;30m.\e[0m"

# define MAP_OPEN_ERR "Error\n\e[0;31mMap file could not be opened, \
wrong name maybe?\e[0m"

# define MAP_EMPTY_ERR "Error\n\e[0;31mInvalid map content\e[1;30m: \
\e[0;31mMap is empty\e[1;30m.\e[0m"

# define MAP_CONTENT_ERR "Error\n\e[0;31mInvalid map content\e[1;30m: \
\e[0;31mMap contains illegal characters\e[1;30m.\e[0m"

# define MAP_LEN_ERR "Error\n\e[0;31mInvalid map content\e[1;30m: \
\e[0;31mMap is not a rectangle, some lines are... So_long\e[1;30m.\e[0m"

# define MAP_SIZE_ERR "Error\n\e[0;31mInvalid map content\e[1;30m:\
 \e[0;31mMap is too big, max map dimensions are\
 \e[0;33m1024x1024\e[1;30m.\e[0m"

# define MAP_STRCT_ERR "Error\n\e[0;31mInvalid map content\e[1;30m: \
\e[0;31mMap must be closed with walls\e[1;30m.\e[0m"

# define MAP_OBJ_ERR "Error\n\e[0;31mInvalid map content\e[1;30m: \
\e[0;31mRequired objects are missing \e[1;30m(\e[0;31mMap\
must have at least one exit and one collectable\e[1;30m).\e[0m"

# define MAP_PLYR_ERR "Error\n\e[0;31mInvalid map content\e[1;30m: \
\e[0;31mMap must have one player\e[1;30m.\e[0m"

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
int		user_end(t_map *map);
int		close_win(int code);

// map_reader.c
int		map_free(char **map, int map_height, int return_value);
int		parse_map_input(char **args);

// map_validator.c
int		validate_map_content(t_map map);

// asset_handler.c
void	update_asset(t_map *map, int x, int y);
int		draw_map(t_map *map);

// player_handler.c
int		move_player(t_map *map, int x, int y);

// gnl.c
char	*get_next_line(int fd);

// strutils.c
int		ft_strlen(char *str, int ignore_new_line);
char	*ft_strdup(char *s);
int		ft_strchr(char *s, char ch);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);

#endif