/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 07:55:53 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/04 01:37:26 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_hrz(t_vec_3d p_start, t_vec_3d p_end, t_data *imgdata)

{
	double	coef;
	double	exact_y;

	coef = (double)(p_end.y - p_start.y) / (double)(p_end.x - p_start.x);
	put_pixel(imgdata, p_start.x, p_start.y, 0xffffff);
	exact_y = p_start.y;
	while (p_start.x <= p_end.x)
	{
		exact_y += coef;
		p_start.y = (int)((exact_y) + 0.5);
		put_pixel(imgdata, p_start.x, p_start.y, 0xffffff);
		p_start.x++;
	}
}

void	draw_vrt(t_vec_3d p_start, t_vec_3d p_end, t_data *imgdata)
{
	double	coef;
	double	exact_x;

	coef = (double)(p_end.x - p_start.x) / (double)(p_end.y - p_start.y);
	put_pixel(imgdata, p_start.x, p_start.y, 0xffffff);
	exact_x = p_start.x;
	while (p_start.y <= p_end.y)
	{
		exact_x += coef;
		p_start.x = (int)((exact_x) + 0.5);
		put_pixel(imgdata, p_start.x, p_start.y, 0xffffff);
		p_start.y++;
	}
}

void	draw_line(t_vec_3d p_start, t_vec_3d p_end, t_data *imgdata)
{
	double	coef;

	if (p_start.x > p_end.x)
		return (draw_line(p_end, p_start, imgdata));
	coef = (double)(p_end.y - p_start.y) / (double)(p_end.x - p_start.x);
	if (coef > -0.5 && coef < 0.5)
		return (draw_hrz(p_start, p_end, imgdata));
	if (p_start.y > p_end.y)
		return (draw_vrt(p_end, p_start, imgdata));
	else
		return (draw_vrt(p_start, p_end, imgdata));
}
