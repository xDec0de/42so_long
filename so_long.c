/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:20:33 by danimart          #+#    #+#             */
/*   Updated: 2022/05/07 16:11:02 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	user_end(t_mlx *mlx)
{
	printf("\n\e[0;36mClose window call by user with exit code \e[1;34m0\e[0m\n\n");  // debug, remove for final version.
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

int	handle_key(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		user_end(mlx);
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
	exit(code);
	return (0);
}

int	main(int argc, char **args)
{
	t_mlx	mlx;
	t_img	img;
	int		map_error;

	atexit(leaks);
	if (argc != 2)
		close_win(1);
	map_error = parse_map_input(args);
	if (map_error != 0)
		close_win(map_error);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 120, 120, "so_long");
	img.img = mlx_new_image(mlx.mlx, 120, 120);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	mlx_key_hook(mlx.win, handle_key, &mlx);
	mlx_hook(mlx.win, 17, 0L, user_end, &mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_loop(mlx.mlx);
}
