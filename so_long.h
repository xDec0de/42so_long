/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:23:44 by danimart          #+#    #+#             */
/*   Updated: 2022/05/05 14:59:04 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>

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

void	draw_pixel(t_img *img, int x, int y, int color);

int		handle_key(int keycode, t_mlx *mlx);
int		close_win(t_mlx *mlx, int code);

int		parse_map_input(char **args);
int		string_size(char *str);
char	*get_map_extension(void);

#endif