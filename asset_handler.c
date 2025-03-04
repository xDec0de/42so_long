/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:13:58 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/04 22:38:45 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_asset(t_map map, char *path)
{
	int	size;

	size = ASSET_SIZE;
	return (mlx_xpm_file_to_image(map.mlx, path, &size, &size));
}

t_map	cache_assets(t_map map)
{
	map.mlx = mlx_init();
	if (map.mlx != NULL)
		map.win = mlx_new_window(map.mlx,
				map.length * ASSET_SIZE, map.height * ASSET_SIZE, WINDOW_TITLE);
	if (map.win != NULL)
	{
		map.assets.wall = get_asset(map, ASSET_WALL);
		map.assets.key = get_asset(map, ASSET_KEY);
		map.assets.exit = get_asset(map, ASSET_DOOR);
		map.assets.bg = get_asset(map, ASSET_BG);
		map.assets.player = get_asset(map, ASSET_PLAYER);
	}
	return (map);
}

void	put_asset(t_map *map, void *asset, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->win, asset,
		x * ASSET_SIZE, y * ASSET_SIZE);
}

void	update_asset(t_map *map, int x, int y)
{
	if (map->arr[y][x] == '1')
		put_asset(map, map->assets.wall, x, y);
	else if (map->arr[y][x] == 'C')
		put_asset(map, map->assets.key, x, y);
	else if (map->arr[y][x] == '0')
		put_asset(map, map->assets.bg, x, y);
	else if (map->arr[y][x] == 'E')
		put_asset(map, map->assets.exit, x, y);
	else if (map->arr[y][x] == 'P')
	{
		map->pl.x = x;
		map->pl.y = y;
		put_asset(map, map->assets.player, x, y);
	}
}

void	draw_map(t_map *map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	*map = cache_assets(*map);
	if (map->mlx == NULL || map->win == NULL)
		exit_sl(map, MLX_ERR, 8);
	while (y < map->height)
	{
		x = 0;
		while (x < map->length)
		{
			update_asset(map, x, y);
			x++;
		}
		y++;
	}
	mlx_key_hook(map->win, handle_key, map);
	mlx_hook(map->win, 17, 0L, user_end, map);
	mlx_loop(map->mlx);
	exit_sl(map, NULL, 0);
}
