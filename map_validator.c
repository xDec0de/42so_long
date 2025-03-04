/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:55:46 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/04 21:36:46 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map_gameplay(t_map *map, int x, int y, char **arr)
{
	int	points;

	points = 0;
	if (arr[y][x] == '1')
		return (0);
	if (arr[y][x] == 'E' || arr[y][x] == 'C')
		points++;
	arr[y][x] = '1';
	points += validate_map_gameplay(map, x + 1, y, arr);
	points += validate_map_gameplay(map, x - 1, y, arr);
	points += validate_map_gameplay(map, x, y + 1, arr);
	points += validate_map_gameplay(map, x, y - 1, arr);
	return (points);
}

void	clone_map_to_array(t_map *map, char **arr)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		arr[y] = malloc(ft_strlen(map->arr[y], 0) * sizeof(char));
		while (x < map->length)
		{
			arr[y][x] = map->arr[y][x];
			if (arr[y][x] == 'P')
			{
				map->pl.x = x;
				map->pl.y = y;
			}
			x++;
		}
		y++;
	}
}

int	validate_map_structure(t_map *map)
{
	int		i;
	int		j;
	char	*arr[MAX_MAP_HEIGHT];

	i = 0;
	clone_map_to_array(map, arr);
	while (i < map->height)
	{
		j = 0;
		while (j < map->length && (i == 0 || i == map->height - 1))
		{
			if (map->arr[i][j] != '1')
				return (map_free(map->arr, map->height, 9));
			j++;
		}
		if (map->arr[i][0] != '1' || map->arr[i][map->length - 1] != '1')
			return (map_free(map->arr, map->height, 9));
		i++;
	}
	if (validate_map_gameplay(map, map->pl.x, map->pl.y, arr) == map->keys + 1)
		return (draw_map(map));
	return (11);
}

int	validate_map_objects(t_map *map)
{
	int		y;
	int		x;
	int		player_amount;

	y = 0;
	player_amount = 0;
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
	if (map->exits != 1 || map->keys == 0 || player_amount != 1)
		return (map_free(map->arr, map->height, 10));
	return (validate_map_structure(map));
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
	else if (map.length > MAX_MAP_LENGTH)
		return (map_free(map.arr, map.height, 6));
	return (validate_map_objects(&map));
}