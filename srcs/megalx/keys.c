/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 03:39:00 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/13 05:49:26 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"
#include "draw_map.h"

void	elevate_map(t_map *map, double val)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->map[i][j].z *= val;
			j++;
		}
		i++;
	}
}

int	key_hook(int keycode, t_fdf *fdf)
{
	printf("%d\n", keycode);
	clear_img(&fdf->img);
	if (keycode == KEY_UP)
		fdf->trans.x += 0.5;
	else if (keycode == KEY_DOWN)
		fdf->trans.x -= 0.5;
	else if (keycode == KEY_LEFT)
		fdf->trans.y -= 0.5;
	else if (keycode == KEY_RIGHT)
		fdf->trans.y += 0.5;
	else if (keycode == KEY_A)
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
	else if (keycode == KEY_Z)
		elevate_map(&fdf->map, 1.1);
	else if (keycode == KEY_X)
		elevate_map(&fdf->map, 0.9);
	else if (keycode == KEY_C)
		fdf->draw_style = fdf->draw_style == 0;
	else if (keycode == KEY_O)
		fdf->proj_style = 0;
	else if (keycode == KEY_P)
		fdf->proj_style = 1;
	else if (keycode == KEY_SPACE)
		fdf->trans.z -= 1.3;
	else if (keycode == KEY_SHIFT)
		fdf->trans.z += 0.3;
	else if (keycode == KEY_ESC)
		exit (0);
	draw_map(*fdf);
	return (keycode);
}
