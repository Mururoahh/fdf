/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:05:07 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/09 17:39:52 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_projected_map(t_map *map, t_trans trans, t_rot rot, t_proj proj)
{
	t_matrix	world_mat;
	t_matrix	proj_mat;
	size_t		i;
	size_t		j;

	world_mat = get_world_matrix(trans, rot);
	proj_mat = get_projection_matrix(proj);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->map[i][j] = apply_matrix(map->map[i][j], world_mat);
			map->map[i][j] = apply_matrix(map->map[i][j], proj_mat);
			map->map[i][j].x /= map->map[i][j].w;
			map->map[i][j].y /= map->map[i][j].w;
			map->map[i][j].x += 1.0;
			map->map[i][j].y += 1.0;
			map->map[i][j].x *= ((0.5 * RES_X));
			map->map[i][j].y *= ((0.5 * RES_Y));
			map->map[i][j].x = (int)(map->map[i][j].x + 0.5);
			map->map[i][j].y = (int)(map->map[i][j].y + 0.5);
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

	cpy.map = malloc(map.height * sizeof(t_vec_3d *));
	i = 0;
	while (i < map.height)
		cpy.map[i++] = malloc(map.width * sizeof(t_vec_3d));
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			cpy.map[i][j] = init_vect(map.map[i][j].x,
					map.map[i][j].y, map.map[i][j].z);
			j++;
		}
		i++;
	}
	cpy.height = map.height;
	cpy.width = map.width;
	return (cpy);
}

void	free_map(t_map map)
{
	size_t	i;

	i = 0;
	while (i < map.height)
	{
		free(map.map[i]);
		i++;
	}
	free(map.map);
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
			if (x >= 0 && x < RES_X && y >= 0 && y < RES_Y && z > 0)
				put_pixel(&fdf.img, x, y, COLOR);
			j++;
		}
		i++;
	}
}

void	draw_map(t_fdf fdf)
{
	size_t		i;
	size_t		j;
	t_map		map;

	map = map_cpy(fdf.map);
	get_projected_map(&map, fdf.trans, fdf.rot, fdf.proj);
	i = 0;
	if (fdf.draw_style == 1)
	{
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
	else
		draw_points(map, fdf);
	free_map(map);
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img.img, 0, 0);
}
