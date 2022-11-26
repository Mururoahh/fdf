/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 06:10:27 by hferraud          #+#    #+#             */
/*   Updated: 2022/11/24 06:33:51 by hferraud         ###   ########lyon.fr   */
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
