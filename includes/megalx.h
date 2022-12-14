/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megalx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 01:58:39 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/14 08:06:06 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEGALX_H
# define MEGALX_H

typedef struct s_data
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		bits_ratio;
	int		line_length;
	int		endian;
	int		x_size;
	int		y_size;
}			t_data;

void	init_img(t_data *img, void *mlx, int size_x, int size_y);
void	put_pixel(t_data *data, int x, int y, int color);

#endif
