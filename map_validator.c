/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:55:46 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/04 22:37:24 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map_gameplay(t_map *map, int x, int y)
{
	int	points;

	points = 0;
	if (map->verify_arr[y][x] == '1')
		return (0);
	if (map->verify_arr[y][x] == 'E' || map->verify_arr[y][x] == 'C')
		points++;
	map->verify_arr[y][x] = '1';
	points += validate_map_gameplay(map, x + 1, y);
	points += validate_map_gameplay(map, x - 1, y);
	points += validate_map_gameplay(map, x, y + 1);
	points += validate_map_gameplay(map, x, y - 1);
	return (points);
}

void	create_verify_array(t_map *map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		map->verify_arr[y] = malloc(ft_strlen(map->arr[y], 0) * sizeof(char));
		while (x < map->length)
		{
			map->verify_arr[y][x] = map->arr[y][x];
			if (map->verify_arr[y][x] == 'P')
			{
				map->pl.x = x;
				map->pl.y = y;
			}
			x++;
		}
		y++;
	}
}

void	validate_map_structure(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	create_verify_array(map);
	while (i < map->height)
	{
		j = 0;
		while (j < map->length && (i == 0 || i == map->height - 1))
		{
			if (map->arr[i][j] != '1')
				exit_sl(map, MAP_STRCT_ERR, 9);
			j++;
		}
		if (map->arr[i][0] != '1' || map->arr[i][map->length - 1] != '1')
			exit_sl(map, MAP_STRCT_ERR, 9);
		i++;
	}
	if (!(validate_map_gameplay(map, map->pl.x, map->pl.y) == map->keys + 1))
		exit_sl(map, MAP_IMPOSSIBLE, 11);
	draw_map(map);
}

void	validate_map_objects(t_map *map)
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
		exit_sl(map, MAP_OBJ_ERR, 10);
	validate_map_structure(map);
}

void	validate_map_content(t_map map)
{
	int	i;
	int	j;

	map.length = ft_strlen(map.arr[0], 1);
	i = 1;
	while (i < map.height)
	{
		j = 0;
		if (ft_strlen(map.arr[i], 1) != map.length)
			exit_sl(&map, MAP_LEN_ERR, 7);
		while (map.arr[i][j] != '\0' && map.arr[i][j] != '\n')
		{
			if (map.arr[i][j] != '0' && map.arr[i][j] != '1'
				&& map.arr[i][j] != 'C' && map.arr[i][j] != 'E'
				&& map.arr[i][j] != 'P')
				exit_sl(&map, MAP_CONTENT_ERR, 4);
			j++;
		}
		i++;
	}
	if (map.height == 0 || map.length == 0)
		exit_sl(&map, MAP_EMPTY_ERR, 5);
	else if (map.length > MAX_MAP_LENGTH)
		exit_sl(&map, MAP_SIZE_ERR, 6);
	validate_map_objects(&map);
}
