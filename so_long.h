/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:23:44 by danimart          #+#    #+#             */
/*   Updated: 2022/05/06 11:46:00 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# define INPUT_ERR "Error\n\e[0;31mInvalid input, usage\
\e[1;30m: \e[0;33m./so_long map_name.ber\e[0m\n"
# define MAP_FORMAT_ERR "Error\n\e[0;31mInvalid map format, maps must match\
\e[1;30m: \e[0;33m./map_name.ber\e[0m\n"
# define MAP_OPEN_ERR "Error\n\e[0;31mMap file could not be opened.\e[0m\n"
# define MAP_CONTENT_ERR "Error\n\e[0;31mInvalid map content.\e[0m\n"
# define BUFFER_SIZE 10
# define FD_SIZE 1024

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
int		close_win(t_mlx *mlx, int code);

// map_reader.c
int		parse_map_input(char **args);

// gnl.c
char	*get_next_line(int fd);

// strutils.c
int		ft_strlen(char *str);
char	*ft_strdup(char *s);
int		ft_strchr(char *s, char ch);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);

#endif