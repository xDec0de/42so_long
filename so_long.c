/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:20:33 by danimart          #+#    #+#             */
/*   Updated: 2022/05/05 14:49:52 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	handle_key(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		close_win(mlx, 0);
	return (0);
}

int	close_win(t_mlx *mlx, int code)
{
	if (code == 0)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (code == 1)
		printf("Error\nInvalid input.\n");
	exit(code);
	return (0);
}

int	main(int argc, char **args)
{
	t_mlx	mlx;
	t_img	img;

	if (argc != 2 || parse_map_input(args))
		close_win(&mlx, 1);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 120, 120, "so_long");
	img.img = mlx_new_image(mlx.mlx, 120, 120);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	mlx_key_hook(mlx.win, handle_key, &mlx);
	mlx_hook(mlx.win, 17, 0L, close_win, &mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_loop(mlx.mlx);
}
