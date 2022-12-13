/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 07:55:53 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/13 05:45:39 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "draw_map.h"
#include "clipping.h"
#include "megalx.h"

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

void	draw_points(t_map map, t_fdf fdf)
{
	size_t		i;
	size_t		j;
	double		x;
	double		y;
	double		z;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			x = map.map[i][j].x;
			y = map.map[i][j].y;
			z = map.map[i][j].z;
			if (x >= 0 && x < RES_X && y >= 0 && y < RES_Y && z > .1)
				put_pixel(&fdf.img, x, y, COLOR);
			j++;
		}
		i++;
	}
}

void	draw_hrz(t_vec_3d p_start, t_vec_3d p_end, t_fdf *fdf)

{
	double	coef;
	double	exact_y;

	coef = (p_end.y - p_start.y) / (p_end.x - p_start.x);
	put_pixel(&fdf->img, p_start.x, p_start.y, COLOR);
	exact_y = p_start.y;
	while (p_start.x <= p_end.x)
	{
		exact_y += coef;
		p_start.y = (int)((exact_y) + 0.5);
		put_pixel(&fdf->img, p_start.x, p_start.y, COLOR);
		p_start.x++;
	}
}

void	draw_vrt(t_vec_3d p_start, t_vec_3d p_end, t_fdf *fdf)
{
	double	coef;
	double	exact_x;

	coef = (p_end.x - p_start.x) / (p_end.y - p_start.y);
	put_pixel(&fdf->img, p_start.x, p_start.y, COLOR);
	exact_x = p_start.x;
	while (p_start.y <= p_end.y)
	{
		exact_x += coef;
		p_start.x = (int)((exact_x) + 0.5);
		put_pixel(&fdf->img, p_start.x, p_start.y, COLOR);
		p_start.y++;
	}
}

void	draw_line(t_vec_3d p_start, t_vec_3d p_end, t_fdf *fdf)
{
	double	coef;

	if (p_start.x > p_end.x)
		return (draw_line(p_end, p_start, fdf));
	if (!line_clipping(&p_start, &p_end) || p_start.z < .1 || p_end.z < .1)
		return ;
	coef = (p_end.y - p_start.y) / (p_end.x - p_start.x);
	if (coef > -0.5 && coef < 0.5)
		return (draw_hrz(p_start, p_end, fdf));
	if (p_start.y > p_end.y)
		return (draw_vrt(p_end, p_start, fdf));
	else
		return (draw_vrt(p_start, p_end, fdf));
}
