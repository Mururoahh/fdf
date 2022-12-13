/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 06:10:27 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/13 05:54:38 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include "parser.h"
#include "megalx.h"
#include "draw_map.h"
#include "keys.h"

void	init_proj_data(t_proj *data)
{
	data->z_near = .1;
	data->z_far = 1000.0;
	data->fov = 90.0;
	data->aspect_ratio = (double)RES_Y / RES_X;
	data->fov_rad = 1.0 / tanl(data->fov * 0.5 / 180.0 * M_PI);
	data->z_ratio = data->z_far / (data->z_far - data->z_near);
}

void	init_fdf(t_fdf *fdf, char *map_name)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, RES_X, RES_Y, "fdf");
	init_img(&fdf->img, fdf->mlx, RES_X, RES_Y);
	fdf->map = parse_map(map_name);
	fdf->draw_style = 1; //ENUM
	fdf->trans.x = .0;
	fdf->trans.y = .0;
	fdf->trans.z = fmax(fdf->map.height, fdf->map.width);
	fdf->rot.pitch = 1.3;
	fdf->rot.yaw = -3.9;
	fdf->rot.roll = 0.3;
	fdf->proj_style = 0;
	init_proj_data(&fdf->proj);
}

void	start_fdf(t_fdf *fdf)
{
	draw_map(*fdf);
	mlx_hook(fdf->win, 2, (1L << 0), key_hook, fdf);
	mlx_loop(fdf->mlx);
}
