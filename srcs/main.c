/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 06:33:17 by hferraud          #+#    #+#             */
/*   Updated: 2022/11/26 14:54:38 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_map	*map;
	int		i;
	int		j;

	if (argc != 2)
		return (0);
	map = parse_map(argv[1]);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			printf("%d ", map->points[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	// void	*mlx;
	// void	*win;
	// t_data	img;
	// t_pos	origin = get_pos(250, 250);
	// t_pos	ne = get_pos(450, 2); //
	// t_pos	nw = get_pos(250, 23); 
	// t_pos	se = get_pos(200, 250);
	// t_pos	sw = get_pos(250, 20); //
	// t_imgdata idata;

	// mlx = mlx_init();
	// win = mlx_new_window(mlx, 500, 500, "fdf");
	// img.img = mlx_new_image(mlx, 500, 500);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 		&img.endian);
	// idata.img = &img;
	// idata.color = 0xff0000;
	// draw_line(origin, ne, idata);
	// draw_line(origin, sw, idata);
	// draw_line(origin, nw, idata);
	// draw_line(origin, se, idata);
	// put_pixel(idata.img, origin.x, origin.y, 0x7FFF00);
	// put_pixel(idata.img, ne.x, ne.y, 0x7FFF00);
	// put_pixel(idata.img, nw.x, nw.y, 0x7FFF00);
	// put_pixel(idata.img, se.x, se.y, 0x7FFF00);
	// put_pixel(idata.img, sw.x, sw.y, 0x7FFF00);
	// mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	// mlx_loop(mlx);
	return (0);
}
