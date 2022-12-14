/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 01:34:55 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/14 09:16:32 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "draw_map.h"

void	transform_vect(t_vec_3d *vec, t_fdf fdf)
{
	t_matrix	world_mat;
	double		half_res_x;
	double		half_res_y;

	half_res_x = 0.5 * RES_X;
	half_res_y = 0.5 * RES_Y;
	world_mat = get_world_matrix(fdf.trans, fdf.rot);
	*vec = apply_matrix(*vec, world_mat);
	if (fdf.proj_style == 1)
	{
		*vec = apply_matrix(*vec, get_perspective_matrix(fdf.proj));
		(*vec).x /= (*vec).w;
		(*vec).y /= (*vec).w;
		(*vec).x = ((*vec).x + 1.0) * (half_res_x);
		(*vec).y = ((*vec).y + 1.0) * (half_res_y);
	}
	else
	{
		*vec = apply_matrix(*vec, get_scale_matrix(1000 / fdf.trans.z));
		(*vec).x = ((*vec).x + 1.0) + (half_res_x);
		(*vec).y = ((*vec).y + 1.0) + (half_res_y);
	}
	(*vec).x = (int)((*vec).x + 0.5);
	(*vec).y = (int)((*vec).y + 0.5);
}

void	get_projected_map(t_map *map, t_fdf fdf)
{
	t_matrix	world_mat;
	size_t		i;
	size_t		j;

	world_mat = get_world_matrix(fdf.trans, fdf.rot);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			transform_vect(&map->map[i][j], fdf);
			j++;
		}
		i++;
	}
}

t_map	init_map(size_t height, size_t width)
{
	t_map	map;
	size_t	i;

	map.map = malloc(height * sizeof(t_vec_3d *));
	if (map.map == NULL)
		exit(1);
	i = 0;
	while (i < height)
	{
		map.map[i++] = malloc(width * sizeof(t_vec_3d));
		if (map.map == NULL)
			exit(1);
	}
	map.height = height;
	map.width = width;
	return (map);
}

t_map	map_cpy(t_map map)
{
	t_map	cpy;
	size_t	i;
	size_t	j;

	cpy = init_map(map.height, map.width);
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			cpy.map[i][j].x = map.map[i][j].x;
			cpy.map[i][j].y = map.map[i][j].y;
			cpy.map[i][j].z = map.map[i][j].z;
			cpy.map[i][j].w = map.map[i][j].w;
			j++;
		}
		i++;
	}
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
