/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   near_clipping.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:37:10 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/05 17:28:59 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "clipping.h"

void	init_frustum(double project_scale, double screen_x, double screen_y)
{
	double		angle_hrz;
	double		angle_vrt;
	double		sh;
	double		sv;
	double		ch;
	double		cv;
	t_frustum	fru;

	angle_hrz = atan2l(screen_x / 2, project_scale);
	angle_vrt = atan2l(screen_y / 2, project_scale);
	sh = sinl(angle_hrz);
	sv = sinl(angle_vrt);
	ch = cosl(angle_hrz);
	cv = cosl(angle_vrt);
	fru.sides[0].normal.x = ch;
	fru.sides[0].normal.y = .0;
	fru.sides[0].normal.z = sh;
	fru.sides[0].distance = .0;
	fru.sides[1].normal.x = -ch;
	fru.sides[1].normal.y = .0;
	fru.sides[1].normal.z = sh;
	fru.sides[1].distance = .0;
	fru.sides[2].normal.x = .0;
	fru.sides[2].normal.y = cv;
	fru.sides[2].normal.z = sv;
	fru.sides[2].distance = .0;
	fru.sides[3].normal.x = .0;
	fru.sides[3].normal.y = -cv;
	fru.sides[3].normal.z = sv;
	fru.sides[3].distance = .0;
	fru.znear.normal.x = .0;
	fru.znear.normal.y = -cv;
	fru.znear.normal.z = sv;
	fru.znear.distance = .0;
}
