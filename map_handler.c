/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:13:58 by danimart          #+#    #+#             */
/*   Updated: 2022/05/09 13:34:22 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_map(t_map map)
{
	t_img	img;
	int		x;
	int		y;
	int		d;

	d = 16;
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.length * d, map.height * d, "so_long");
	img.img = mlx_xpm_file_to_image(map.mlx, "./img/wall.xpm", &d, &d);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_key_hook(map.win, handle_key, &map);
	mlx_hook(map.win, 17, 0L, user_end, &map);
	x = 0;
	y = 0;
	while(x < map.length) {
		y = 0;
		while(y < map.length) {
			if (x % 2 == 0)
				img.img = mlx_xpm_file_to_image(map.mlx, "./img/wall.xpm", &d, &d);
			else
				img.img = mlx_xpm_file_to_image(map.mlx, "./img/key.xpm", &d, &d);
			mlx_put_image_to_window(map.mlx, map.win, img.img, x * 16, y * 16);
			y++;
		}
		x++;
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
