/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:05:07 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/04 05:28:17 by hferraud         ###   ########lyon.fr   */
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

void	get_projected_map(t_map *map, t_trans trans, t_rot rot)
{
	t_matrix	matrix;
	size_t		i;
	size_t		j;

	matrix = get_world_matrix(trans, rot);
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

t_map	map_cpy(t_map map)
{
	t_map	cpy;
	size_t	i;
	size_t	j;

	cpy.points = malloc(map.height * sizeof(t_vec_3d *));
	i = 0;
	while (i < map.height)
		cpy.points[i++] = malloc(map.width * sizeof(t_vec_3d));
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			cpy.points[i][j] = init_vect(map.points[i][j].x,
					map.points[i][j].y, map.points[i][j].z);
			j++;
		}
		i++;
	}
	cpy.height = map.height;
	cpy.width = map.width;
	return (cpy);
}

void	draw_map(t_fdf fdf)
{
	size_t		i;
	size_t		j;
	t_map		map;

	map = map_cpy(fdf.map);
	get_projected_map(&map, fdf.trans, fdf.rot);
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (i > 0)
				draw_line(map.points[i][j], map.points[i - 1][j], &fdf.img);
			if (j > 0)
				draw_line(map.points[i][j], map.points[i][j - 1], &fdf.img);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img.img, 0, 0);
}
