/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:20:33 by danimart          #+#    #+#             */
/*   Updated: 2022/05/10 14:17:54 by danimart         ###   ########.fr       */
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
	int	res;

	res = 1;
	if (keycode == 53)
		user_end(map);
	if (keycode == 13 || keycode == 126)
		res = move_player_up(map);
	if (keycode == 1 || keycode == 125)
		res = move_player_down(map);
	if (keycode == 2 || keycode == 124)
		res = move_player_right(map);
	if (keycode == 0 || keycode == 123)
		res = move_player_left(map);
	if (res == 0)
		printf("Movements: %d\n", ++map->movements);
	return (0);
}

int	close_win(int code)
{
	if (code == 1)
		printf(INPUT_ERR"\e[0m\n");
	else if (code == 2)
		printf(MAP_FORMAT_ERR"\e[0m\n");
	else if (code == 3)
		printf(MAP_OPEN_ERR"\e[0m\n");
	else if (code == 4)
		printf(MAP_CONTENT_ERR"\e[0m\n");
	else if (code == 5)
		printf(MAP_EMPTY_ERR"\e[0m\n");
	else if (code == 6)
		printf(MAP_SIZE_ERR"\e[0m\n");
	else if (code == 7)
		printf(MAP_LEN_ERR"\e[0m\n");
	else if (code == 8)
		printf(MLX_ERR"\e[0m\n");
	else if (code == 9)
		printf(MAP_STRCT_ERR"\e[0m\n");
	else if (code == 10)
		printf(MAP_OBJ_ERR"\e[0m\n");
	else if (code == 11)
		printf(MAP_PLYR_ERR"\e[0m\n");
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
