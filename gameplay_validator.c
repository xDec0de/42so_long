/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_validator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:01:57 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/06 14:10:22 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_coord(t_map *map, int x, int y)
{
	int	points;

	if (map->verify_arr[y][x] == '1')
		return (0);
	points = 0;
	if (map->verify_arr[y][x] == 'E' || map->verify_arr[y][x] == 'C')
		points++;
	map->verify_arr[y][x] = 'P';
	return (points);
}

int	check_for_p(t_map *map, int x, int y, int *points)
{
	if (map->verify_arr[y][x] != 'P')
		return (0);
	*points += validate_coord(map, x + 1, y);
	*points += validate_coord(map, x - 1, y);
	*points += validate_coord(map, x, y + 1);
	*points += validate_coord(map, x, y - 1);
	map->verify_arr[y][x] = '1';
	return (1);
}

int	validate_map_gameplay(t_map *map)
{
	int	x;
	int	y;
	int	points;
	int	p_found;

	p_found = 1;
	points = 0;
	while (p_found != 0)
	{
		y = 1;
		p_found = 0;
		while (y < map->height - 1)
		{
			x = 1;
			while (x < map->length - 1)
			{
				if (check_for_p(map, x, y, &points))
					p_found++;
				x++;
			}
			y++;
		}
	}
	return (points);
}
