/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 04:39:42 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/13 05:12:05 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

# include "vector.h"

typedef struct s_matrix
{
	float	m[4][4];
}			t_matrix;

typedef struct s_trans
{
	double	x;
	double	y;
	double	z;
}			t_trans;

typedef struct s_rot
{
	double	pitch;
	double	yaw;
	double	roll;
}			t_rot;

typedef struct s_proj
{
	double	z_near;
	double	z_far;
	double	z_ratio;
	double	fov;
	double	aspect_ratio;
	double	fov_rad;
}			t_proj;

t_vec_3d	apply_matrix(t_vec_3d v, t_matrix m);
t_matrix	multiply_matrix(t_matrix m1, t_matrix m2);
t_matrix	get_world_matrix(t_trans trans, t_rot rot);
t_matrix	get_perspective_matrix(t_proj proj);
t_matrix	get_scale_matrix(double scale_factor);

#endif
