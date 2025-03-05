/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_sl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:30:37 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/05 18:39:46 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	user_end(t_map *map)
{
	exit_sl(map, NULL, 0);
	return (0);
}

void	free_assets(t_map *map)
{
	if (map->assets.bg != NULL)
		mlx_destroy_image(map->mlx, map->assets.bg);
	if (map->assets.exit != NULL)
		mlx_destroy_image(map->mlx, map->assets.exit);
	if (map->assets.key != NULL)
		mlx_destroy_image(map->mlx, map->assets.key);
	if (map->assets.player != NULL)
		mlx_destroy_image(map->mlx, map->assets.player);
	if (map->assets.wall != NULL)
		mlx_destroy_image(map->mlx, map->assets.wall);
}

void	free_arrays(t_map *map)
{
	int	i;

	i = 0;
	if (map->arr != NULL)
	{
		while (i < map->height)
		{
			free(map->arr[i]);
			i++;
		}
	}
	free(map->arr);
	map->arr = NULL;
	i = 0;
	if (map->verify_arr == NULL)
		return ;
	while (i < map->height)
	{
		free(map->verify_arr[i]);
		i++;
	}
	// free(map->verify_arr);
}

void	exit_sl(t_map *map, char *msg, int code)
{
	if (msg != NULL)
		ft_printf(msg);
	if (map == NULL)
		exit(code);
	if (map->mlx != NULL)
	{
		if (map->win != NULL)
			mlx_destroy_window(map->mlx, map->win);
		free_assets(map);
		mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
	free_arrays(map);
	free(map);
	exit(code);
}
