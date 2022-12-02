/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:55:45 by hferraud          #+#    #+#             */
/*   Updated: 2022/11/30 09:52:42 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec_3d	init_vect(double x, double y, double z)
{
	t_vec_3d	vect;

	vect.x = x;
	vect.y = y;
	vect.z = z;
	vect.w = 1;
	return (vect);
}

t_vec_3d	add_vect(t_vec_3d v1, t_vec_3d v2)
{
	return (init_vect(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

t_vec_3d	div_vect(t_vec_3d v1, double k)
{
	return (init_vect(v1.x / k, v1.y / k, v1.z / k));
}
