/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 06:10:27 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/19 06:28:11 by hferraud         ###   ########lyon.fr   */
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
	fdf->draw_style = DRAW_LINE;
	fdf->trans.x = .0;
	fdf->trans.y = .0;
	fdf->trans.z = fmax(fdf->map.height, fdf->map.width);
	fdf->rot.pitch = (M_PI / 4.0);
	fdf->rot.yaw = (M_PI / 5.0);
	fdf->rot.roll = (M_PI / 6);
	fdf->proj_style = PROJ_ISO;
	init_proj_data(&fdf->proj);
}

void	start_fdf(t_fdf *fdf)
{
	draw_map(*fdf);
	mlx_hook(fdf->win, ON_KEYDOWN, (1L << 0), key_hook, fdf);
	mlx_hook(fdf->win, ON_DESTROY, 0L, exit_hook, fdf);
	mlx_loop(fdf->mlx);
}
