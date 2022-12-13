/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megalx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 01:56:51 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/13 04:24:50 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "megalx.h"

void	init_img(t_data *img, void *mlx, int size_x, int size_y)
{
	img->img = mlx_new_image(mlx, size_x, size_y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->bits_ratio = img->bits_per_pixel / 8;
	img->x_size = size_x;
	img->y_size = size_y;
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_ratio));
	*(unsigned int *)dst = color;
}
