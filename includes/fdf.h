/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 07:56:51 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/13 05:53:49 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "../mlx/mlx.h"
# include "ft_utils.h"
# include "matrices.h"
# include "vector.h"

# include <stdio.h>

# define RES_X 1920
# define RES_Y 1080
# define COLOR 0xff0000

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

typedef struct s_map
{
	size_t		height;
	size_t		width;
	t_vec_3d	**map;
}				t_map;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	t_data		img;
	t_map		map;
	int			draw_style;
	t_trans		trans;
	t_rot		rot;
	t_proj		proj;
	int			proj_style;

}				t_fdf;

void	init_fdf(t_fdf *fdf, char *map_name);
void	start_fdf(t_fdf *fdf);

#endif
