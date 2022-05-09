/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:20:33 by danimart          #+#    #+#             */
/*   Updated: 2022/05/09 13:30:45 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	user_end(t_map *map)
{
	printf("\n\e[0;36mClose window call by user with exit code \e[1;34m0\e[0m\n\n");  // debug, remove for final version.
	mlx_destroy_window(map->mlx, map->win);
	exit(0);
}

int	handle_key(int keycode, t_map *map)
{
	if (keycode == 53)
		user_end(map);
	return (0);
}

int	close_win(int code)
{
	printf("\n\e[0;36mClose window call with exit code \e[1;34m%d\e[0m\n\n", code); // debug, remove for final version.
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
		printf(MAP_HEIGHT_ERR"\e[0m\n");
	else if (code == 7)
		printf(MAP_LEN_ERR"\e[0m\n");
	else if (code == 8)
		printf(MAP_SIZE_ERR"\e[0m\n");
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

	atexit(leaks);
	if (argc != 2)
		close_win(1);
	map_error = parse_map_input(args);
	if (map_error != 0)
		close_win(map_error);
}
