/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 04:41:18 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/13 05:32:54 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"
#include "matrices.h"

t_vec_3d	apply_matrix(t_vec_3d v, t_matrix m)
{
	t_vec_3d	r;

	r.x = v.x * m.m[0][0] + v.y * m.m[1][0] + v.z * m.m[2][0] + v.w * m.m[3][0];
	r.y = v.x * m.m[0][1] + v.y * m.m[1][1] + v.z * m.m[2][1] + v.w * m.m[3][1];
	r.z = v.x * m.m[0][2] + v.y * m.m[1][2] + v.z * m.m[2][2] + v.w * m.m[3][2];
	r.w = v.x * m.m[0][3] + v.y * m.m[1][3] + v.z * m.m[2][3] + v.w * m.m[3][3];
	return (r);
}

t_matrix	multiply_matrix(t_matrix m1, t_matrix m2)
{
	t_matrix	res;
	int			c;
	int			r;

	c = 0;
	while (c < 4)
	{
		r = 0;
		while (r < 4)
		{
			res.m[r][c] = m1.m[r][0] * m2.m[0][c] + m1.m[r][1] * m2.m[1][c]
				+ m1.m[r][2] * m2.m[2][c] + m1.m[r][3] * m2.m[3][c];
			r++;
		}
		c++;
	}
	return (res);
}
