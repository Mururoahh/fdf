/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:02:12 by hferraud          #+#    #+#             */
/*   Updated: 2022/11/29 11:03:37 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec_3d	apply_matrix(t_vec_3d v, t_matrix m)
{
	t_vec_3d	res;
	float		w;

	res.x = v.x * m.m[0][0] + v.y * m.m[1][0] + v.z * m.m[2][0] + m.m[3][0];
	res.y = v.x * m.m[0][1] + v.y * m.m[1][1] + v.z * m.m[2][1] + m.m[3][1];
	res.z = v.x * m.m[0][2] + v.y * m.m[1][2] + v.z * m.m[2][2] + m.m[3][2];
	w = v.x * m.m[0][3] + v.y * m.m[1][3] + v.z * m.m[2][3] + m.m[3][3];
	if (w != 0)
	{
		res.x /= w;
		res.y /= w;
		res.z /= w;
	}
	return (res);
}

static void	bzero(void *ptr, size_t size)
{
	while (size--)
		((unsigned char *)ptr)[size] = 0;
}

t_matrix	get_projection_matrix(void)
{
	t_matrix	matrix;
	double		z_near;
	double		z_far;
	double		fov;
	double		aspect_ratio;
	double		fov_rad;

	z_near = 0.1;
	z_far = 1000.0;
	fov = 90.0;
	aspect_ratio = (float)RES_Y / (float)RES_X;
	fov_rad = 1.0 / tan(fov * 0.5 / 180.0 * M_PI);
	bzero(&matrix, sizeof(t_matrix));
	matrix.m[0][0] = aspect_ratio * fov_rad;
	matrix.m[1][1] = fov_rad;
	matrix.m[2][2] = z_far / (z_far - z_near);
	matrix.m[3][2] = (-z_far * z_near) / (z_far - z_near);
	matrix.m[2][3] = 1.0;
	return (matrix);
}

t_matrix	get_rotation_x_matrix(double theta)
{
	t_matrix	matrix;

	bzero(&matrix, sizeof(t_matrix));
	matrix.m[0][0] = 1;
	matrix.m[1][1] = cos(theta * 0.5);
	matrix.m[1][2] = sin(theta * 0.5);
	matrix.m[2][1] = -sin(theta * 0.5);
	matrix.m[2][2] = cos(theta * 0.5);
	matrix.m[3][3] = 1;
	return (matrix);
}

t_matrix	get_rotation_z_matrix(double theta)
{
	t_matrix	matrix;

	bzero(&matrix, sizeof(t_matrix));
	matrix.m[0][0] = cos(theta);
	matrix.m[0][1] = sin(theta);
	matrix.m[1][0] = -sin(theta);
	matrix.m[1][1] = cos(theta);
	matrix.m[2][2] = 1;
	matrix.m[3][3] = 1;
	return (matrix);
}
