/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:05:07 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/13 05:38:43 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "draw_map.h"
#include "matrices.h"

void	draw_map(t_fdf fdf)
{
	size_t		i;
	size_t		j;
	t_map		map;

	map = map_cpy(fdf.map);
	get_projected_map(&map, fdf);
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
