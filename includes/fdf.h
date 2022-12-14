/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 07:56:51 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/14 08:19:27 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "../mlx/mlx.h"
# include "megalx.h"
# include "matrices.h"
# include "vector.h"
# include "ft_utils.h"

# include <stdio.h>

# define RES_X 1920
# define RES_Y 1080
# define COLOR 0xff0000

enum
{
	DRAW_POINT = 0,
	DRAW_LINE = 1,
	PROJ_ISO = 0,
	PROJ_PERSP = 1,
};

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
