/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 06:10:27 by hferraud          #+#    #+#             */
/*   Updated: 2022/11/23 02:31:38 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

float	get_coef_dir(t_pos p_start, t_pos p_end)
{
	long	dif_x;
	long	dif_y;

	dif_x = p_end.x - p_start.x;
	dif_y = p_end.y - p_start.y;
	return (dif_y / dif_x);
}

int	round_float(float nb)
{
	return ((int) nb + 0.5);
}

t_pos	get_pos(int x, int y)
{
	t_pos	point;

	point.x = x;
	point.y = y;
	return (point);
}

#include <stdio.h>

int	main(void)
{
	void	*mlx;
	void	*win;
	t_data	img;
	t_pos	origin = get_pos(250, 250);
	t_pos	ne = get_pos(200, 450);
	t_pos	nw = get_pos(350, 20);
	t_pos	se = get_pos(2, 499);
	t_pos	sw = get_pos(456, 150); //
	t_imgdata idata;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "fdf");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	idata.img = &img;
	idata.color = 0xff0000;
	draw_line(origin, sw, idata);
	draw_line(origin, ne, idata);
	draw_line(origin, nw, idata);
	draw_line(origin, se, idata);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
