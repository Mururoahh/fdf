/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:02:12 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/03 23:20:47 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec_3d	apply_matrix(t_vec_3d v, t_matrix m)
{
	t_vec_3d	r;

	r.x = v.x * m.m[0][0] + v.y * m.m[1][0] + v.z * m.m[2][0] + v.w * m.m[3][0];
	r.y = v.x * m.m[0][1] + v.y * m.m[1][1] + v.z * m.m[2][1] + v.w * m.m[3][1];
	r.z = v.x * m.m[0][2] + v.y * m.m[1][2] + v.z * m.m[2][2] + v.w * m.m[3][2];
	r.w = v.x * m.m[0][3] + v.y * m.m[1][3] + v.z * m.m[2][3] + v.w * m.m[3][3];
	return (r);
}

void	bzero(void *ptr, size_t size)
{
	while (size--)
		((unsigned char *)ptr)[size] = 0;
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

t_matrix	get_translation_matrix(double x, double y, double z)
{
	t_matrix	matrix;

	bzero(&matrix, sizeof(t_matrix));
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

	bzero(&matrix, sizeof(t_matrix));
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

	bzero(&matrix, sizeof(t_matrix));
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

	bzero(&matrix, sizeof(t_matrix));
	matrix.m[0][0] = cos(theta);
	matrix.m[0][1] = sin(theta);
	matrix.m[1][0] = -sin(theta);
	matrix.m[1][1] = cos(theta);
	matrix.m[2][2] = 1.0;
	matrix.m[3][3] = 1.0;
	return (matrix);
}

t_matrix	get_world_matrix(void)
{
	t_matrix	mat;

	mat = get_rotation_z_matrix(M_PI);
	mat = multiply_matrix(mat, get_rotation_x_matrix(-M_PI));
	mat = multiply_matrix(mat, get_rotation_y_matrix(M_PI));
	mat = multiply_matrix(mat, get_translation_matrix(0.0, 0.0, -20.0));
	return (mat);
}
