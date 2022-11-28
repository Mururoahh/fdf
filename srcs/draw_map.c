/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:05:07 by hferraud          #+#    #+#             */
/*   Updated: 2022/11/28 07:14:43 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pos	get_hrz_pos(t_pos origin)
{
	t_pos	point_pos;
	double	rotated_x;
	double	rotated_y;

	rotated_x = cos(((ROTATION * M_PI) / 180)) * (POINT_DISTANCE);
	rotated_y = sin(((ROTATION * M_PI) / 180)) * (POINT_DISTANCE);
	point_pos.x = origin.x + (rotated_x);
	point_pos.y = origin.y + (rotated_y);
	return (point_pos);
}

t_pos	get_vrt_pos(t_pos origin)
{
	t_pos	point_pos;
	double	rotated_x;
	double	rotated_y;

	rotated_x = sin(((ROTATION * M_PI) / 180)) * (POINT_DISTANCE);
	rotated_y = cos(((ROTATION * M_PI) / 180)) * (POINT_DISTANCE);
	point_pos.x = origin.x + (rotated_x);
	point_pos.y = origin.y - (rotated_y);
	return (point_pos);
}

t_pos	draw_point(t_pos origin, t_imgdata imgdata)
{
	t_pos	current_pos;

	current_pos = get_hrz_pos(origin);
	draw_line(origin, current_pos, imgdata);
	draw_line(current_pos, get_vrt_pos(current_pos), imgdata);
	origin = current_pos;
	return (origin);
}

t_pos_3d	init_3d_pos(int x, int y, int z)
{
	t_pos_3d	pos_3d;

	pos_3d.x = x * POINT_DISTANCE;
	pos_3d.y = y * POINT_DISTANCE;
	pos_3d.z = z;
}

t_pos_3d	**init_3d_map(t_map map)
{
	t_pos_3d	**map_3d;
	int			i;
	int			j;

	map_3d = malloc(map.height * sizeof(t_pos_3d *));
	if (map_3d == NULL)
		return (NULL);
	i = 0;
	while (i < map.height)
	{
		map_3d[i] = malloc (map.width * sizeof(t_pos_3d));
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

void	draw_map(t_map map, t_imgdata imgdata)
{
	t_pos	origin;
	t_pos	last_pos;
	int		height;
	int		width;

	origin.x = (RES_X / 2) - ((map.width * POINT_DISTANCE) / 2);
	origin.y = (RES_Y / 2) - ((map.height * POINT_DISTANCE) / 2);
	height = 0;
	while (height <= map.height)
	{
		last_pos = origin;
		width = 0;
		while (width <= map.width)
		{
			last_pos = draw_point(last_pos, imgdata);
			width++;
		}
		origin.x -= sin(((ROTATION * M_PI) / 180)) * (POINT_DISTANCE);
		origin.y += sin(((ROTATION * M_PI) / 180)) * (POINT_DISTANCE);
		height++;
	}
}
