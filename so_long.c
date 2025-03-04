/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:20:33 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/04 21:36:08 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	user_end(t_map *map)
{
	if (map != NULL && map->mlx != NULL && map->win != NULL)
		mlx_destroy_window(map->mlx, map->win);
	exit(0);
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

int	close_win(int code)
{
	if (code == 1)
		ft_printf(INPUT_ERR"\e[0m\n");
	else if (code == 2)
		ft_printf(MAP_FORMAT_ERR"\e[0m\n");
	else if (code == 3)
		ft_printf(MAP_OPEN_ERR"\e[0m\n");
	else if (code == 4)
		ft_printf(MAP_CONTENT_ERR"\e[0m\n");
	else if (code == 5)
		ft_printf(MAP_EMPTY_ERR"\e[0m\n");
	else if (code == 6)
		ft_printf(MAP_SIZE_ERR"\e[0m\n");
	else if (code == 7)
		ft_printf(MAP_LEN_ERR"\e[0m\n");
	else if (code == 8)
		ft_printf(MLX_ERR"\e[0m\n");
	else if (code == 9)
		ft_printf(MAP_STRCT_ERR"\e[0m\n");
	else if (code == 10)
		ft_printf(MAP_OBJ_ERR"\e[0m\n");
	else if (code == 11)
		ft_printf(MAP_IMPOSSIBLE"\e[0m\n");
	exit(code);
	return (code);
}

int	main(int argc, char **args)
{
	int		map_error;

	if (argc != 2)
		close_win(1);
	map_error = parse_map_input(args);
	if (map_error != 0)
		close_win(map_error);
}
