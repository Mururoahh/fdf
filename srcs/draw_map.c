/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:05:07 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/05 03:41:05 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_map map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			printf("x = %f, y = %f\n", map.points[i][j].x, map.points[i][j].y);
			j++;
		}
		i++;
	}
}

void	get_projected_map(t_map *map, t_trans trans, t_rot rot)
{
	t_matrix	world_mat;
	t_matrix	proj_mat;
	size_t		i;
	size_t		j;

	world_mat = get_world_matrix(trans, rot);
	proj_mat = get_projection_matrix();
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->points[i][j] = apply_matrix(map->points[i][j], world_mat);
			map->points[i][j] = apply_matrix(map->points[i][j], proj_mat);
			map->points[i][j] = div_vect(map->points[i][j], map->points[i][j].w);
			map->points[i][j].x += 1.0;
			map->points[i][j].y += 1.0;
			map->points[i][j].x *= ((0.5 * RES_X));
			map->points[i][j].y *= ((0.5 * RES_Y));
			map->points[i][j].x = (int)(map->points[i][j].x + 0.5);
			map->points[i][j].y = (int)(map->points[i][j].y + 0.5);
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
	// FREE CPY
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img.img, 0, 0);
}
