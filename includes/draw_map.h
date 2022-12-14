/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 01:37:02 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/14 08:22:57 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_MAP_H
# define DRAW_MAP_H

# include "fdf.h"

t_map	map_cpy(t_map map);
void	free_map(t_map map);
void	get_projected_map(t_map *map, t_fdf fdf);
void	clear_img(t_data *img);
void	draw_line(t_vec_3d p_start, t_vec_3d p_end, t_fdf *fdf);
void	draw_map(t_fdf fdf);

#endif
