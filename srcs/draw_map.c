/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:05:07 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/02 11:22:55 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec_3d	init_3d_pos(double x, double y, double z)
{
	t_vec_3d	vec_3d;

	vec_3d.x = x;
	vec_3d.y = y;
	vec_3d.z = z;
	vec_3d.w = 1;
	return (vec_3d);
}

t_vec_3d	**init_3d_map(t_map map)
{
	t_vec_3d	**map_3d;
	int			i;
	int			j;

	map_3d = malloc(map.height * sizeof(t_vec_3d *));
	if (map_3d == NULL)
		return (NULL);
	i = 0;
	while (i < map.height)
	{
		map_3d[i] = malloc(map.width * sizeof(t_vec_3d));
		if (map_3d[i] == NULL)
			return (NULL);
		j = 0;
		while (j < map.width)
		{
			map_3d[i][j] = init_3d_pos(i, j, map.points[i][j]);
			j++;
		}
		i++;
	}
	return (map_3d);
}

void	apply_matrix_to_map(t_vec_3d **map_3d, t_matrix matrix, int height, int width)
{
	t_vec_3d	vec;
	int			i;
	int			j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			vec.x = map_3d[i][j].x;
			vec.y = map_3d[i][j].y;
			vec.z = map_3d[i][j].z;
			vec = apply_matrix(vec, matrix);
			map_3d[i][j].x = vec.x;
			map_3d[i][j].y = vec.y;
			map_3d[i][j].z = vec.z;
			j++;
		}
		i++;
	}
}

t_pos	**init_projected_map(int height, int width)
{
	t_pos		**proj_map;
	int			i;

	proj_map = malloc(height * sizeof(t_vec_3d *));
	if (proj_map == NULL)
	{
		//ERRNO
		exit(1);
	}
	i = 0;
	while (i < height)
	{
		proj_map[i] = malloc(width * sizeof(t_vec_3d));
		if (proj_map[i] == NULL)
		{
			//ERRNO
			exit(1);
		}
		i++;
	}
	return (proj_map);
}

t_pos	**get_projected_map(t_vec_3d **map_3d, int height, int width)
{
	t_pos		**proj_map;
	t_matrix	matrix;
	int			i;
	int			j;

	proj_map = init_projected_map(height, width);
	matrix = get_world_matrix();
	apply_matrix_to_map(map_3d, matrix, height, width);
	matrix = get_projection_matrix();
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			map_3d[i][j].z = map_3d[i][j].z - 40.0;
			map_3d[i][j] = apply_matrix(map_3d[i][j], matrix);
			map_3d[i][j] = div_vect(map_3d[i][j], map_3d[i][j].w);
			map_3d[i][j] = add_vect(map_3d[i][j], init_vect(1.0, 1.0, .0));
			proj_map[i][j].x = map_3d[i][j].x * (0.5 * (float)RES_X) + 0.5;
			proj_map[i][j].y = map_3d[i][j].y * (0.5 * (float)RES_Y) + 0.5;
			j++;
		}
		i++;
	}
	return (proj_map);
}

void	draw_map(t_map raw_map, t_imgdata imgdata)
{
	t_vec_3d	**map_3d;
	t_pos		**proj_map;
	int			i;
	int			j;

	map_3d = init_3d_map(raw_map);
	proj_map = get_projected_map(map_3d, raw_map.height, raw_map.width);
	i = 0;
	while (i < raw_map.height)
	{
		j = 0;
		while (j < raw_map.width)
		{
			if (i > 0)
				draw_line(proj_map[i][j], proj_map[i - 1][j], imgdata);
			if (j > 0)
				draw_line(proj_map[i][j], proj_map[i][j - 1], imgdata);
			j++;
		}
		i++;
	}
}
