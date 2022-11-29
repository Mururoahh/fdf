/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 06:33:17 by hferraud          #+#    #+#             */
/*   Updated: 2022/11/29 09:27:22 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	init_img(t_data *img, void *mlx, int size_x, int size_y)
{
	img->img = mlx_new_image(mlx, size_x, size_y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->x_size = size_x;
	img->y_size = size_y;
}

int	main(int argc, char **argv)
{
	t_map		*map;
	void		*mlx;
	void		*win;
	t_data		img;
	t_imgdata	idata;

	if (argc != 2)
		return (0);
	map = parse_map(argv[1]);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "fdf");
	init_img(&img, mlx, RES_X, RES_Y);
	idata.img = &img;
	idata.color = 0xff0000;
	draw_map(*map, idata);
	//draw_line(get_pos(250, 250), get_pos(350, 325), idata);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
