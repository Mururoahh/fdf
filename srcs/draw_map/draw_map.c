/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:05:07 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/14 08:38:36 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "draw_map.h"
#include "matrices.h"

void	draw_map_lines(t_map map, t_fdf fdf)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (i > 0)
				draw_line(map.map[i][j], map.map[i - 1][j], &fdf);
			if (j > 0)
				draw_line(map.map[i][j], map.map[i][j - 1], &fdf);
			j++;
		}
		i++;
	}
}

void	draw_map_points(t_map map, t_fdf fdf)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (map.map[i][j].x >= 0 && map.map[i][j].x < RES_X
			&& map.map[i][j].y >= 0 && map.map[i][j].y < RES_Y
			&& map.map[i][j].z > .1)
				put_pixel(&fdf.img, map.map[i][j].x, map.map[i][j].y, COLOR);
			j++;
		}
		i++;
	}
}

void	draw_map(t_fdf fdf)
{
	t_map		map;

	map = map_cpy(fdf.map);
	get_projected_map(&map, fdf);
	if (fdf.draw_style == 1)
		draw_map_lines(map, fdf);
	else
		draw_map_points(map, fdf);
	free_map(map);
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img.img, 0, 0);
}
