/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 07:55:53 by hferraud          #+#    #+#             */
/*   Updated: 2022/11/26 10:43:39 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pos	pos_cpy(t_pos pos)
{
	t_pos	cpy;

	cpy.x = pos.x;
	cpy.y = pos.y;
	return (cpy);
}

t_pos	get_delta(t_pos p_up, t_pos p_down)
{
	t_pos	delta;

	if (p_up.x >= p_down.x)
	{
		delta.x = p_up.x - p_down.x;
		delta.y = p_up.y - p_down.y;
	}
	else
	{
		delta.x = p_down.x - p_up.x;
		delta.y = p_up.y - p_down.y;
	}
	return (delta);
}

void	draw_hrz(t_pos p_start, t_pos p_end, double coef, t_imgdata imgdata)

{
	double	exact_y;
	t_pos	p_curr;

	p_curr.x = p_start.x;
	p_curr.y = p_start.y;
	exact_y = p_curr.y;
	put_pixel(imgdata.img, p_curr.x, p_curr.y, imgdata.color);
	while (p_curr.x < p_end.x)
	{
		exact_y += coef;
		p_curr.y = (int)((exact_y) + 0.5);
		put_pixel(imgdata.img, p_curr.x, p_curr.y, imgdata.color);
		p_curr.x++;
	}
}

void	draw_vrt(t_pos p_start, t_pos p_end, double coef, t_imgdata imgdata)
{
	double	exact_x;
	t_pos	p_curr;

	p_curr.x = p_start.x;
	p_curr.y = p_start.y;
	exact_x = p_curr.x;
	put_pixel(imgdata.img, p_curr.x, p_curr.y, imgdata.color);
	while (p_curr.x < p_end.x)
	{
		exact_x += fabs(coef);
		p_curr.x = (int)((exact_x + coef) + 0.5);
		put_pixel(imgdata.img, p_curr.x, p_curr.y, imgdata.color);
		if (p_curr.y < p_end.y)
			p_curr.y++;
		else
			p_curr.y--;
	}
}

void	draw_line(t_pos p_start, t_pos p_end, t_imgdata imgdata)
{
	t_pos	p_right;
	t_pos	p_left;
	t_pos	delta;
	int		d_y_abs;

	if (p_start.x >= p_end.x)
	{
		p_right = pos_cpy(p_start);
		p_left = pos_cpy(p_end);
	}
	else
	{
		p_right = pos_cpy(p_end);
		p_left = pos_cpy(p_start);
	}
	delta.x = (p_right.x - p_left.x);
	delta.y = (p_right.y - p_left.y);
	d_y_abs = delta.y;
	if (delta.y < 0)
		d_y_abs = -delta.y;
	if (delta.x > d_y_abs)
		draw_hrz(p_left, p_right, (double)delta.y / (double)delta.x, imgdata);
	else
		draw_vrt(p_left, p_right, (double)delta.x / (double)delta.y, imgdata);
}
