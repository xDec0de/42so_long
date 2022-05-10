/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:01:13 by danimart          #+#    #+#             */
/*   Updated: 2022/05/10 14:10:06 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	redraw_texture(t_map map, char id, int y, int x)
{
	void	*img;

	if (id == 'P')
		img = map.pl.txt;
	else
		img = map.bg;
	mlx_put_image_to_window(map.mlx, map.win, img, x * 16, y * 16);
}

int	move_player_up(t_map *map)
{
	if (map->arr[map->pl.y - 1][map->pl.x] == '1')
		return (1);
	else if (map->arr[map->pl.y - 1][map->pl.x] == 'E')
	{
		if (map->collectables == 0)
			user_end(map);
		return (1);
	}
	else if (map->arr[map->pl.y - 1][map->pl.x] == 'C')
		map->collectables--;
	map->arr[map->pl.y - 1][map->pl.x] = 'P';
	map->arr[map->pl.y][map->pl.x] = '0';
	redraw_texture(*map, 'P', map->pl.y - 1, map->pl.x);
	redraw_texture(*map, '0', map->pl.y, map->pl.x);
	map->pl.y--;
	return (0);
}

int	move_player_down(t_map *map)
{
	if (map->arr[map->pl.y + 1][map->pl.x] == '1')
		return (1);
	else if (map->arr[map->pl.y + 1][map->pl.x] == 'E')
	{
		if (map->collectables == 0)
			user_end(map);
		return (1);
	}
	else if (map->arr[map->pl.y + 1][map->pl.x] == 'C')
		map->collectables--;
	map->arr[map->pl.y + 1][map->pl.x] = 'P';
	map->arr[map->pl.y][map->pl.x] = '0';
	redraw_texture(*map, 'P', map->pl.y + 1, map->pl.x);
	redraw_texture(*map, '0', map->pl.y, map->pl.x);
	map->pl.y++;
	return (0);
}

int	move_player_right(t_map *map)
{
	if (map->arr[map->pl.y][map->pl.x + 1] == '1')
		return (1);
	else if (map->arr[map->pl.y][map->pl.x + 1] == 'E')
	{
		if (map->collectables == 0)
			user_end(map);
		return (1);
	}
	else if (map->arr[map->pl.y][map->pl.x + 1] == 'C')
		map->collectables--;
	map->arr[map->pl.y][map->pl.x + 1] = 'P';
	map->arr[map->pl.y][map->pl.x] = '0';
	redraw_texture(*map, 'P', map->pl.y, map->pl.x + 1);
	redraw_texture(*map, '0', map->pl.y, map->pl.x);
	map->pl.x++;
	return (0);
}

int	move_player_left(t_map *map)
{
	if (map->arr[map->pl.y][map->pl.x - 1] == '1')
		return (1);
	else if (map->arr[map->pl.y][map->pl.x - 1] == 'E')
	{
		if (map->collectables == 0)
			user_end(map);
		return (1);
	}
	else if (map->arr[map->pl.y][map->pl.x - 1] == 'C')
		map->collectables--;
	map->arr[map->pl.y][map->pl.x - 1] = 'P';
	map->arr[map->pl.y][map->pl.x] = '0';
	redraw_texture(*map, 'P', map->pl.y, map->pl.x - 1);
	redraw_texture(*map, '0', map->pl.y, map->pl.x);
	map->pl.x--;
	return (0);
}
