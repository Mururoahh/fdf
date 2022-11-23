/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 07:56:51 by hferraud          #+#    #+#             */
/*   Updated: 2022/11/22 09:02:06 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <math.h>
# include "../minilibx_macos/mlx.h"

typedef struct s_data
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_imgdata
{
	t_data	*img;
	int		color;
}			t_imgdata;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

void	put_pixel(t_data *data, int x, int y, int color);
void	draw_line(t_pos p_start, t_pos p_end, t_imgdata imgdata);

#endif
