/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 06:35:29 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/09 19:26:23 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "clipping.h"

t_region	get_region(t_vec_3d vec)
{
	t_region	region;

	region = INSIDE;
	if (vec.y >= RES_Y)
		region |= TOP;
	else if (vec.y < 0)
		region |= BOTTOM;
	if (vec.x >= RES_X)
		region |= RIGHT;
	else if (vec.x < 0)
		region |= LEFT;
	return (region);
}

t_vec_3d	clip_line(t_vec_3d p0, t_vec_3d p1, t_region tested_region)
{
	t_vec_3d	new;

	new = init_vect(.0, .0, .0);
	if (tested_region & TOP)
	{
		new.x = p0.x + (p1.x - p0.x) * (RES_Y - p0.y) / (p1.y - p0.y);
		new.y = RES_Y - 1;
	}
	else if (tested_region & BOTTOM)
	{
		new.x = p0.x + (p1.x - p0.x) * (.0 - p0.y) / (p1.y - p0.y);
		new.y = .0;
	}
	else if (tested_region & RIGHT)
	{
		new.y = p0.y + (p1.y - p0.y) * (RES_X - p0.x) / (p1.x - p0.x);
		new.x = RES_X - 1;
	}
	else if (tested_region & LEFT)
	{
		new.y = p0.y + (p1.y - p0.y) * (.0 - p0.x) / (p1.x - p0.x);
		new.x = .0;
	}
	return (new);
}

/**	
 *	\brief	Clip the offscreen part of line.
 *	\return	0 if line is completly offscreen and 1 otherwise.
 */
int	line_clipping(t_vec_3d *start, t_vec_3d *end)
{
	t_region	start_region;
	t_region	end_region;
	int			in_window;

	in_window = 0;
	while (1)
	{
		start_region = get_region(*start);
		end_region = get_region(*end);
		if (!(start_region | end_region))
		{
			in_window = 1;
			break ;
		}
		else if (start_region & end_region)
			break ;
		else
		{
			if (start_region > end_region)
				*start = clip_line(*start, *end, start_region);
			else
				*end = clip_line(*start, *end, end_region);
		}
	}
	return (in_window);
}
