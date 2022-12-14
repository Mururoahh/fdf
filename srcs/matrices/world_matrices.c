/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_matrices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:02:12 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/14 08:55:32 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "matrices.h"
#include "ft_utils.h"

t_matrix	get_translation_matrix(double x, double y, double z)
{
	t_matrix	matrix;

	ft_bzero(&matrix, sizeof(t_matrix));
	matrix.m[0][0] = 1.0;
	matrix.m[1][1] = 1.0;
	matrix.m[2][2] = 1.0;
	matrix.m[3][3] = 1.0;
	matrix.m[3][0] = x;
	matrix.m[3][1] = y;
	matrix.m[3][2] = z;
	return (matrix);
}

t_matrix	get_rotation_x_matrix(double theta)
{
	t_matrix	matrix;

	ft_bzero(&matrix, sizeof(t_matrix));
	matrix.m[0][0] = 1.0;
	matrix.m[1][1] = cos(theta);
	matrix.m[1][2] = sin(theta);
	matrix.m[2][1] = -sin(theta);
	matrix.m[2][2] = cos(theta);
	matrix.m[3][3] = 1.0;
	return (matrix);
}

t_matrix	get_rotation_y_matrix(double theta)
{
	t_matrix	matrix;

	ft_bzero(&matrix, sizeof(t_matrix));
	matrix.m[0][0] = cos(theta);
	matrix.m[0][2] = sin(theta);
	matrix.m[2][0] = -sin(theta);
	matrix.m[1][1] = 1.0f;
	matrix.m[2][2] = cos(theta);
	matrix.m[3][3] = 1.0f;
	return (matrix);
}

t_matrix	get_rotation_z_matrix(double theta)
{
	t_matrix	matrix;

	ft_bzero(&matrix, sizeof(t_matrix));
	matrix.m[0][0] = cos(theta);
	matrix.m[0][1] = sin(theta);
	matrix.m[1][0] = -sin(theta);
	matrix.m[1][1] = cos(theta);
	matrix.m[2][2] = 1.0;
	matrix.m[3][3] = 1.0;
	return (matrix);
}

t_matrix	get_world_matrix(t_trans tran, t_rot rot)
{
	t_matrix	mat;

	mat = get_rotation_x_matrix(rot.pitch);
	mat = multiply_matrix(mat, get_rotation_y_matrix(rot.yaw));
	mat = multiply_matrix(mat, get_rotation_z_matrix(rot.roll));
	mat = multiply_matrix(mat, get_translation_matrix(tran.x, tran.y, tran.z));
	return (mat);
}
