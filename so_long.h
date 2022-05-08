/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:23:44 by danimart          #+#    #+#             */
/*   Updated: 2022/05/08 16:23:09 by danimart         ###   ########.fr       */
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

typedef struct s_player {
	int	x;
	int	y;
}				t_player;

typedef struct s_map {
	char		**arr;
	int			height;
	int			length;
	int			collectables;
	int			exits;
	t_player	player;
}				t_map;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_mlx;

// so_long.c
void	draw_pixel(t_img *img, int x, int y, int color);
int		handle_key(int keycode, t_mlx *mlx);
int		close_win(int code);

// map_reader.c
int		map_free(char **map, int map_height, int return_value);
int		parse_map_input(char **args);

// map_handler.c
int		validate_map_objects(t_map map, int player_amount);
t_map	create_base_map(char **map, int map_height);

// gnl.c
char	*get_next_line(int fd);

// strutils.c
int		ft_strlen(char *str, int ignore_new_line);
char	*ft_strdup(char *s);
int		ft_strchr(char *s, char ch);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);

 // Debug, remove for final version.
 void leaks(void); 
 void print_map(char **map, int map_height, int map_length); 

#endif