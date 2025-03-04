/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:01:13 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/04 14:06:12 by daniema3         ###   ########.fr       */
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

int	move_player(t_map *map, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = map->pl.x+ x;
	new_y = map->pl.y+ y;
	if (map->arr[new_y][new_x] == '1')
		return (1);
	else if (map->arr[new_y][new_x] == 'E')
	{
		if (map->keys == 0)
			user_end(map);
		return (1);
	}
	else if (map->arr[new_y][new_x] == 'C')
		map->keys--;
	map->arr[new_y][new_x] = 'P';
	map->arr[map->pl.y][map->pl.x] = '0';
	redraw_texture(*map, 'P', new_y, new_x);
	redraw_texture(*map, '0', map->pl.y, map->pl.x);
	map->pl.x = new_x;
	map->pl.y = new_y;
	return (0);
}
