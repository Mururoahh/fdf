/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:05:07 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/04 01:58:23 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_matrix_to_map(t_vec_3d **map_3d, t_matrix matrix, int height,
		int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			map_3d[i][j] = apply_matrix(map_3d[i][j], matrix);
			j++;
		}
		i++;
	}
}

void	get_projected_map(t_map *map)
{
	t_matrix	matrix;
	size_t		i;
	size_t		j;

	matrix = get_world_matrix();
	apply_matrix_to_map(map->points, matrix, map->height, map->width);
	matrix = get_projection_matrix();
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->points[i][j] = apply_matrix(map->points[i][j], matrix);
			map->points[i][j] = div_vect(map->points[i][j], map->points[i][j].w);
			map->points[i][j].x += 1.0;
			map->points[i][j].y += 1.0;
			map->points[i][j].x *= (int)((0.5 * (float)RES_X) + 0.5);
			map->points[i][j].y *= (int)((0.5 * (float)RES_Y) + 0.5);
			j++;
		}
		i++;
	}
}

void	draw_map(t_fdf *fdf)
{
	size_t		i;
	size_t		j;

	get_projected_map(&fdf->map);
	i = 0;
	while (i < fdf->map.height)
	{
		j = 0;
		while (j < fdf->map.width)
		{
			if (i > 0)
				draw_line(fdf->map.points[i][j], fdf->map.points[i - 1][j], &fdf->img);
			if (j > 0)
				draw_line(fdf->map.points[i][j], fdf->map.points[i][j - 1], &fdf->img);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
}
