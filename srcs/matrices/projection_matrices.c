/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_matrices.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 04:46:32 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/13 05:52:23 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"
#include "ft_utils.h"

t_matrix	get_perspective_matrix(t_proj proj)
{
	t_matrix	matrix;

	ft_bzero(&matrix, sizeof(t_matrix));
	matrix.m[0][0] = proj.aspect_ratio * proj.fov_rad;
	matrix.m[1][1] = proj.fov_rad;
	matrix.m[2][2] = proj.z_ratio;
	matrix.m[3][2] = -proj.z_near * proj.z_ratio;
	matrix.m[2][3] = 1.0;
	return (matrix);
}

t_matrix	get_scale_matrix(double scale_factor)
{
	t_matrix	matrix;

	ft_bzero(&matrix, sizeof(t_matrix));
	matrix.m[0][0] = scale_factor;
	matrix.m[1][1] = scale_factor;
	matrix.m[2][2] = scale_factor;
	matrix.m[3][3] = 1.0;
	return (matrix);
}
