/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 03:39:00 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/05 03:58:25 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"

int	key_hook(int keycode, t_fdf *fdf)
{
	clear_img(&fdf->img);
	if (keycode == KEY_UP)
		fdf->trans.y -= 0.5;
	else if (keycode == KEY_DOWN)
		fdf->trans.y += 0.5;
	else if (keycode == KEY_LEFT)
		fdf->trans.x += 0.5;
	else if (keycode == KEY_RIGHT)
		fdf->trans.x -= 0.5;
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
	else if (keycode == KEY_SPACE)
		fdf->trans.z -= 0.3;
	else if (keycode == KEY_E)
		fdf->trans.z += 0.3;
	else if (keycode == KEY_ESC)
		exit (0);
	draw_map(*fdf);
	return (keycode);
}
