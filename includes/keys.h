/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 03:41:13 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/10 04:42:20 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# include "fdf.h"

enum
{
	KEY_Q = 12,
	KEY_W = 13,
	KEY_E = 14,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_Z = 6,
	KEY_X = 7,
	KEY_C = 8,
	KEY_O = 31,
	KEY_P = 35,
	KEY_DOWN = 123,
	KEY_UP = 124,
	KEY_RIGHT = 125,
	KEY_LEFT = 126,
	KEY_ESC = 53,
	KEY_SPACE = 49,
	KEY_SHIFT = 257,
};

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int	key_hook(int keycode, t_fdf *fdf);

#endif
