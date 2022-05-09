/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:13:58 by danimart          #+#    #+#             */
/*   Updated: 2022/05/09 14:17:02 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	cache_images(t_map map, int d)
{
	int	z;

	z = 0;
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.length * d, map.height * d, "so_long");
	mlx_key_hook(map.win, handle_key, &map);
	mlx_hook(map.win, 17, 0L, user_end, &map);
	map.wall.img = mlx_xpm_file_to_image(map.mlx, "./img/wall.xpm", &d, &d);
	map.wall.addr = mlx_get_data_addr(map.wall.img, &z, &z, &z);
	map.key.img = mlx_xpm_file_to_image(map.mlx, "./img/key.xpm", &d, &d);
	map.key.addr = mlx_get_data_addr(map.key.img, &z, &z, &z);
	map.ext.img = mlx_xpm_file_to_image(map.mlx, "./img/door.xpm", &d, &d);
	map.ext.addr = mlx_get_data_addr(map.ext.img, &z, &z, &z);
	map.bg.img = mlx_xpm_file_to_image(map.mlx, "./img/bg.xpm", &d, &d);
	map.bg.addr = mlx_get_data_addr(map.bg.img, &z, &z, &z);
	return (map);
}

int	draw_map(t_map map)
{
	int		x;
	int		y;
	int		d;

	d = 16;
	x = 0;
	y = 0;
	map = cache_images(map, d);
	print_map(map.arr, map.height, map.length);
	while(y < map.height) {
		x = 0;
		while(x < map.length) {
			if (map.arr[y][x] == '1')
				mlx_put_image_to_window(map.mlx, map.win, map.wall.img, x * 16, y * 16);
			else if (map.arr[y][x] == 'C')
				mlx_put_image_to_window(map.mlx, map.win, map.key.img, x * 16, y * 16);
			else if (map.arr[y][x] == '0')
				mlx_put_image_to_window(map.mlx, map.win, map.bg.img, x * 16, y * 16);
			else if (map.arr[y][x] == 'E')
				mlx_put_image_to_window(map.mlx, map.win, map.ext.img, x * 16, y * 16);
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
	res.player = p;
	return (res);
}

int	create_player(t_map map, int x, int y)
{
	map.player.x = x;
	map.player.y = y;
	return (1);
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
				player_amount += create_player(map, x, y);
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
