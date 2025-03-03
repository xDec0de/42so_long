/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:55:46 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/03 20:56:47 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map_objects(t_map *map, int player_amount)
{
	int		y;
	int		x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->length)
		{
			if (map->arr[y][x] == 'E')
				map->exits++;
			else if (map->arr[y][x] == 'C')
				map->keys++;
			else if (map->arr[y][x] == 'P')
				player_amount++;
			x++;
		}
		y++;
	}
	if (map->exits == 0 || map->keys == 0)
		return (map_free(map->arr, map->height, 10));
	else if (player_amount != 1)
		return (map_free(map->arr, map->height, 11));
	return (draw_map(map));
}

int	validate_map_structure(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.length && (i == 0 || i == map.height - 1))
		{
			if (map.arr[i][j] != '1')
				return (map_free(map.arr, map.height, 9));
			j++;
		}
		if (map.arr[i][0] != '1' || map.arr[i][map.length - 1] != '1')
			return (map_free(map.arr, map.height, 9));
		i++;
	}
	return (validate_map_objects(&map, 0));
}

int	validate_map_content(t_map map)
{
	int	i;
	int	j;

	map.length = ft_strlen(map.arr[0], 1);
	i = 1;
	while (i < map.height)
	{
		j = 0;
		if (ft_strlen(map.arr[i], 1) != map.length)
			return (map_free(map.arr, map.height, 7));
		while (map.arr[i][j] != '\0' && map.arr[i][j] != '\n')
		{
			if (map.arr[i][j] != '0' && map.arr[i][j] != '1'
				&& map.arr[i][j] != 'C' && map.arr[i][j] != 'E'
				&& map.arr[i][j] != 'P')
				return (map_free(map.arr, map.height, 4));
			j++;
		}
		i++;
	}
	if (map.height == 0 || map.length == 0)
		return (map_free(map.arr, map.height, 5));
	else if (map.length > 1024)
		return (map_free(map.arr, map.height, 6));
	return (validate_map_structure(map));
}