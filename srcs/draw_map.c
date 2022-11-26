/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:57:06 by hferraud          #+#    #+#             */
/*   Updated: 2022/11/24 14:06:25 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(int width, int length, t_mappoint *map)
{
	int	i;
	int	j;

	i = 0;
	while (map)
	{
		draw_point(map);
		
	}
}
