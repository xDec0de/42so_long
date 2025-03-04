/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:01:13 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/04 15:42:16 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player(t_map *map, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = map->pl.x + x;
	new_y = map->pl.y + y;
	if (map->arr[new_y][new_x] == '1')
		return (0);
	else if (map->arr[new_y][new_x] == 'E')
	{
		if (map->keys == 0)
			user_end(map);
		return (0);
	}
	else if (map->arr[new_y][new_x] == 'C')
		map->keys--;
	map->arr[map->pl.y][map->pl.x] = '0';
	update_asset(map, map->pl.x, map->pl.y);
	map->arr[new_y][new_x] = 'P';
	update_asset(map, new_x, new_y);
	return (1);
}
