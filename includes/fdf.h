/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 07:56:51 by hferraud          #+#    #+#             */
/*   Updated: 2022/11/29 11:03:26 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "ft_utils.h"

# define RES_X 1920
# define RES_Y 1080
# define ROTATION 45
# define POINT_DISTANCE 60

typedef struct s_data
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x_size;
	int		y_size;
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

typedef struct s_pos_3d
{
	int	x;
	int	y;
	int	z;
}	t_pos_3d;

typedef struct s_vec_3d
{
	float	x;
	float	y;
	float	z;
}	t_vec_3d;

typedef struct s_map_line
{
	char				*line;
	struct s_map_line	*next;
}						t_map_line;

typedef struct s_map
{
	int	height;
	int	width;
	int	**points;
}				t_map;

typedef struct s_matrix
{
	float	m[4][4];
}			t_matrix;

t_map		*parse_map(char *filename);
t_pos		get_pos(int x, int y);
void		put_pixel(t_data *data, int x, int y, int color);
void		draw_line(t_pos p_start, t_pos p_end, t_imgdata imgdata);
void		draw_map(t_map map, t_imgdata imgdata);
char		*get_next_line(int fd);
t_vec_3d	apply_matrix(t_vec_3d v, t_matrix m);
t_matrix	get_projection_matrix(void);
t_matrix	get_rotation_x_matrix(double theta);
t_matrix	get_rotation_z_matrix(double theta);

#endif
