/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 04:40:16 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/13 05:19:35 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec_3d
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vec_3d;

t_vec_3d	init_vect(double x, double y, double z);
t_vec_3d	add_vect(t_vec_3d v1, t_vec_3d v2);
t_vec_3d	sub_vect(t_vec_3d v1, t_vec_3d v2);
t_vec_3d	div_vect(t_vec_3d v1, double k);
t_vec_3d	mul_vect(t_vec_3d v1, double k);

#endif
