/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 03:39:00 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/14 09:34:01 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"
#include "draw_map.h"

void	elevate_map(t_map *map, int key)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (key == KEY_X)
				map->map[i][j].z *= 1.1;
			else
				map->map[i][j].z *= 0.9;
			j++;
		}
		i++;
	}
}

void	alpha_key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_A)
		fdf->rot.pitch -= 0.1;
	else if (keycode == KEY_D)
		fdf->rot.pitch += 0.1;
	else if (keycode == KEY_W)
		fdf->rot.yaw += 0.1;
	else if (keycode == KEY_S)
		fdf->rot.yaw -= 0.1;
	else if (keycode == KEY_Q)
		fdf->rot.roll += 0.1;
	else if (keycode == KEY_E)
		fdf->rot.roll -= 0.1;
	else if (keycode == KEY_Z || keycode == KEY_X)
		elevate_map(&fdf->map, keycode);
	else if (keycode == KEY_C)
		fdf->draw_style = fdf->draw_style == DRAW_POINT;
	else if (keycode == KEY_O)
		fdf->proj_style = PROJ_ISO;
	else if (keycode == KEY_P)
		fdf->proj_style = PROJ_PERSP;
	else if (keycode == KEY_M)
		fdf->trans.z -= 1.3;
	else if (keycode == KEY_N)
		fdf->trans.z += 1.3;
}

void	extra_key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_UP)
		fdf->trans.x += 0.5;
	else if (keycode == KEY_DOWN)
		fdf->trans.x -= 0.5;
	else if (keycode == KEY_LEFT)
		fdf->trans.y -= 0.5;
	else if (keycode == KEY_RIGHT)
		fdf->trans.y += 0.5;
	else if (keycode == KEY_ESC)
		exit (0);
}

int	key_hook(int keycode, t_fdf *fdf)
{
	clear_img(&fdf->img);
	if (keycode >= KEY_A && keycode <= KEY_M)
		alpha_key_hook(keycode, fdf);
	else
		extra_key_hook(keycode, fdf);
	draw_map(*fdf);
	return (keycode);
}
