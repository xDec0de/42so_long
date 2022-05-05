/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:20:33 by danimart          #+#    #+#             */
/*   Updated: 2022/05/05 13:11:02 by danimart         ###   ########.fr       */
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
		close_win(mlx);
	return (0);
}

void	close_win(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

int	main(void)
{
	t_mlx	mlx;
	t_img	img;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 120, 120, "so_long");
	img.img = mlx_new_image(mlx.mlx, 120, 120);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	mlx_key_hook(mlx.win, handle_key, &mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_loop(mlx.mlx);
}
