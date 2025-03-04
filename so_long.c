/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:20:33 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/04 23:38:08 by daniema3         ###   ########.fr       */
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

void	exit_sl(t_map *map, char *msg, int code)
{
	int	i;

	if (map != NULL && map->mlx != NULL)
	{
		mlx_destroy_display(map->mlx);
		if (map->win != NULL)
			mlx_destroy_window(map->mlx, map->win);
		free_assets(map);
		free(map->mlx);
	}
	if (msg != NULL)
		ft_printf(msg);
	i = -1;
	if (map->arr != NULL)
		while (++i < map->height)
			free(map->arr[i]);
	i = -1;
	while (++i < map->height)
		free(map->verify_arr[i]);
	exit(code);
}

int	handle_key(int keycode, t_map *map)
{
	int	has_moved;

	has_moved = 0;
	if (keycode == KEY_ESC)
		user_end(map);
	else if (keycode == KEY_UP || keycode == KEY_W)
		has_moved = move_player(map, 0, -1);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		has_moved = move_player(map, -1, 0);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		has_moved = move_player(map, 0, 1);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		has_moved = move_player(map, 1, 0);
	if (has_moved)
		ft_printf("Movements: %d\n", ++map->movements);
	return (0);
}

int	main(int argc, char **args)
{
	if (argc != 2)
		exit_sl(NULL, INPUT_ERR, 1);
	parse_map_input(args);
}
