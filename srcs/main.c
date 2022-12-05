/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 06:33:17 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/05 11:27:52 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"

void	clear_img(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < RES_X)
	{
		j = 0;
		while (j < RES_Y)
		{
			put_pixel(img, i, j, 0x000000);
			j++;
		}
		i++;
	}
}

void	init_img(t_data *img, void *mlx, int size_x, int size_y)
{
	img->img = mlx_new_image(mlx, size_x, size_y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->x_size = size_x;
	img->y_size = size_y;
}

void	init_fdf(t_fdf *fdf, char *map_name)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, RES_X, RES_Y, "fdf");
	init_img(&fdf->img, fdf->mlx, RES_X, RES_Y);
	fdf->map = parse_map(map_name);
	fdf->trans.x = .0;
	fdf->trans.y = .0;
	fdf->trans.z = fmaxf(fdf->map.height, fdf->map.width);
	fdf->rot.pitch = 1.3;
	fdf->rot.yaw = -3.9;
	fdf->rot.roll = 0.3;
}

void	start_fdf(t_fdf *fdf)
{
	draw_map(*fdf);
	mlx_hook(fdf->win, 2, (1L << 0), key_hook, fdf);
	//mlx_loop_hook(fdf->mlx, key_hook, fdf);
	mlx_loop(fdf->mlx);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		return (0);
	init_fdf(&fdf, argv[1]);
	start_fdf(&fdf);
	return (0);
}
