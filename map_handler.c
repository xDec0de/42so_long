/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:13:58 by danimart          #+#    #+#             */
/*   Updated: 2022/05/08 13:53:21 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

t_map	set_player(t_map map, int x, int y)
{
	map.player.x = x;
	map.player.y = y;
	return (map);
}

int	validate_map_objects(t_map map)
{
	int		i;
	int		j;
	int		exits;

	i = 0;
	exits = 0;
	while (i < map.height)
	{
		j = 0;
		while (map.arr[i][j] != '\0')
		{
			if (map.arr[i][j] == 'E')
				exits++;
			else if (map.arr[i][j] == 'C')
				map.collectables++;
			j++;
		}
		i++;
	}
	if (exits == 0 || map.collectables == 0)
		return (map_free(map.arr, map.height, 10));
	return (map_free(map.arr, map.height, 0));
}
