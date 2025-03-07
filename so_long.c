/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:20:33 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/07 14:37:22 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		ft_printf(MOVEMENT_MSG, ++map->movements);
	return (0);
}

int	main(int argc, char **args)
{
	if (argc != 2)
		exit_sl(NULL, INPUT_ERR, INPUT_ERRC);
	parse_map_input(args);
}
