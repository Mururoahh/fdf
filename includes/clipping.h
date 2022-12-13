/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipping.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 06:38:57 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/13 05:31:37 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIPPING_H
# define CLIPPING_H

# include "fdf.h"
# include "vector.h"

typedef int	t_region;

enum
{
	TOP = 8,
	BOTTOM = 4,
	RIGHT = 2,
	LEFT = 1,
	INSIDE = 0
};

typedef struct s_plane
{
	t_vec_3d	normal;
	double		distance;
}				t_plane;

typedef struct s_frustum
{
	t_plane	sides[4];
	t_plane	znear;
}			t_frustum;

int	line_clipping(t_vec_3d *start, t_vec_3d *end);

#endif
