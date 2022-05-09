/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:13:58 by danimart          #+#    #+#             */
/*   Updated: 2022/05/09 15:57:47 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	cache_images(t_map map, int d)
{
	int	z;

	z = 0;
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.length * d, map.height * d, NAME);
	mlx_key_hook(map.win, handle_key, &map);
	mlx_hook(map.win, 17, 0L, user_end, &map);
	map.wall = mlx_xpm_file_to_image(map.mlx, "./img/wall.xpm", &d, &d);
	map.key = mlx_xpm_file_to_image(map.mlx, "./img/key.xpm", &d, &d);
	map.ext = mlx_xpm_file_to_image(map.mlx, "./img/door.xpm", &d, &d);
	map.bg = mlx_xpm_file_to_image(map.mlx, "./img/bg.xpm", &d, &d);
	map.pl.txt = mlx_xpm_file_to_image(map.mlx, "./img/player.xpm", &d, &d);
	return (map);
}

void	draw_texture(t_map map, int x, int y, int d)
{
	if (map.arr[y][x] == '1')
		mlx_put_image_to_window(map.mlx, map.win, map.wall, x * d, y * d);
	else if (map.arr[y][x] == 'C')
		mlx_put_image_to_window(map.mlx, map.win, map.key, x * d, y * d);
	else if (map.arr[y][x] == '0')
		mlx_put_image_to_window(map.mlx, map.win, map.bg, x * d, y * d);
	else if (map.arr[y][x] == 'E')
		mlx_put_image_to_window(map.mlx, map.win, map.ext, x * d, y * d);
	else if (map.arr[y][x] == 'P')
	{
		map.pl.x = x;
		map.pl.y = y;
		mlx_put_image_to_window(map.mlx, map.win, map.pl.txt, x * d, y * d);
	}
}

int	draw_map(t_map map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	map = cache_images(map, 16);
	print_map(map.arr, map.height, map.length);
	while (y < map.height)
	{
		x = 0;
		while (x < map.length)
		{
			draw_texture(map, x, y, 16);
			x++;
		}
		y++;
	}
	mlx_loop(map.mlx);
	return (map_free(map.arr, map.height, 0));
}

t_map	create_base_map(char **map, int map_height)
{
	t_map		res;
	t_player	p;

	res.arr = map;
	res.height = map_height;
	res.length = 0;
	res.collectables = 0;
	p.x = -1;
	p.y = -1;
	res.pl = p;
	return (res);
}

int	validate_map_objects(t_map map, int player_amount)
{
	int		y;
	int		x;

	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.length)
		{
			if (map.arr[y][x] == 'E')
				map.exits++;
			else if (map.arr[y][x] == 'C')
				map.collectables++;
			else if (map.arr[y][x] == 'P')
				player_amount++;
			x++;
		}
		y++;
	}
	if (map.exits == 0 || map.collectables == 0)
		return (map_free(map.arr, map.height, 10));
	else if (player_amount != 1)
		return (map_free(map.arr, map.height, 11));
	return (draw_map(map));
}
