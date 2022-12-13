/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megalx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 01:58:39 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/13 04:25:12 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEGALX_H
# define MEGALX_H

# include "fdf.h"

void	init_img(t_data *img, void *mlx, int size_x, int size_y);
void	put_pixel(t_data *data, int x, int y, int color);

#endif
