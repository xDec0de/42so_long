/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:13:58 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/03 20:56:41 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	cache_images(t_map map, int d)
{
	map.mlx = mlx_init();
	if (map.mlx != NULL)
		map.win = mlx_new_window(map.mlx, map.length * d, map.height * d,
				WINDOW_TITLE);
	if (map.win != NULL)
	{
		map.wall = mlx_xpm_file_to_image(map.mlx, ASSET_WALL, &d, &d);
		map.key = mlx_xpm_file_to_image(map.mlx, ASSET_KEY, &d, &d);
		map.ext = mlx_xpm_file_to_image(map.mlx, ASSET_DOOR, &d, &d);
		map.bg = mlx_xpm_file_to_image(map.mlx, ASSET_BG, &d, &d);
		map.pl.txt = mlx_xpm_file_to_image(map.mlx, ASSET_PLAYER, &d, &d);
	}
	return (map);
}

void	draw_texture(t_map *map, int x, int y, int d)
{
	if (map->arr[y][x] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall, x * d, y * d);
	else if (map->arr[y][x] == 'C')
		mlx_put_image_to_window(map->mlx, map->win, map->key, x * d, y * d);
	else if (map->arr[y][x] == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->bg, x * d, y * d);
	else if (map->arr[y][x] == 'E')
		mlx_put_image_to_window(map->mlx, map->win, map->ext, x * d, y * d);
	else if (map->arr[y][x] == 'P')
	{
		map->pl.x = x;
		map->pl.y = y;
		mlx_put_image_to_window(map->mlx, map->win, map->pl.txt, x * d, y * d);
	}
}

int	draw_map(t_map *map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	*map = cache_images(*map, 16);
	if (map->mlx == NULL || map->win == NULL)
		return (map_free(map->arr, map->height, 8));
	while (y < map->height)
	{
		x = 0;
		while (x < map->length)
		{
			draw_texture(map, x, y, 16);
			x++;
		}
		y++;
	}
	mlx_key_hook(map->win, handle_key, map);
	mlx_hook(map->win, 17, 0L, user_end, map);
	mlx_loop(map->mlx);
	return (map_free(map->arr, map->height, 0));
}

t_map	create_base_map(char **map, int map_height)
{
	t_map		res;

	res.arr = map;
	res.height = map_height;
	res.exits = 0;
	res.keys = 0;
	res.movements = 0;
	return (res);
}
