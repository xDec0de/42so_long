/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:13:58 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/04 14:40:12 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_asset(t_map map, char *path, int size)
{
	return mlx_xpm_file_to_image(map.mlx, path, &size, &size);
}

t_map	cache_assets(t_map map, int d)
{
	map.mlx = mlx_init();
	if (map.mlx != NULL)
		map.win = mlx_new_window(map.mlx, map.length * d, map.height * d,
				WINDOW_TITLE);
	if (map.win != NULL)
	{
		map.assets.wall = get_asset(map, ASSET_WALL, d);
		map.assets.key = get_asset(map, ASSET_KEY, d);
		map.assets.exit = get_asset(map, ASSET_DOOR, d);
		map.assets.bg = get_asset(map, ASSET_BG, d);
		map.assets.player = get_asset(map, ASSET_PLAYER, d);
	}
	return (map);
}

void	put_asset(t_map *map, void *asset, int x, int y, int size)
{
	mlx_put_image_to_window(map->mlx, map->win, asset, x * size, y * size);
}

void	draw_asset(t_map *map, int x, int y, int d)
{
	if (map->arr[y][x] == '1')
		put_asset(map, map->assets.wall, x, y, d);
	else if (map->arr[y][x] == 'C')
		put_asset(map, map->assets.key, x, y, d);
	else if (map->arr[y][x] == '0')
		put_asset(map, map->assets.bg, x, y, d);
	else if (map->arr[y][x] == 'E')
		put_asset(map, map->assets.exit, x, y, d);
	else if (map->arr[y][x] == 'P')
	{
		map->pl.x = x;
		map->pl.y = y;
		put_asset(map, map->assets.player, x, y, d);
	}
}

int	draw_map(t_map *map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	*map = cache_assets(*map, 16);
	if (map->mlx == NULL || map->win == NULL)
		return (map_free(map->arr, map->height, 8));
	while (y < map->height)
	{
		x = 0;
		while (x < map->length)
		{
			draw_asset(map, x, y, 16);
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
