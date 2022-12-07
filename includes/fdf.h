/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 07:56:51 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/07 00:04:11 by hferraud         ###   ########lyon.fr   */
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

# include <stdio.h>

# define RES_X 1920
# define RES_Y 1080
# define ROTATION 45
# define POINT_DISTANCE 60

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

typedef struct s_imgdata
{
	t_data	*img;
	int		color;
}			t_imgdata;

typedef struct s_vec_3d
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vec_3d;

typedef struct s_map_line
{
	char				*line;
	struct s_map_line	*next;
}						t_map_line;

typedef struct s_map
{
	size_t		height;
	size_t		width;
	t_vec_3d	**map;
}				t_map;

typedef struct s_matrix
{
	float	m[4][4];
}			t_matrix;

typedef struct s_trans
{
	double	x;
	double	y;
	double	z;
}			t_trans;

typedef struct s_rot
{
	double	pitch;
	double	yaw;
	double	roll;
}			t_rot;

typedef struct s_proj
{
	double	z_near;
	double	z_far;
	double	z_ratio;
	double	fov;
	double	aspect_ratio;
	double	fov_rad;
}			t_proj;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_data	img;
	t_map	map;
	int		draw_style;
	t_trans	trans;
	t_rot	rot;
	t_proj	proj;

}				t_fdf;

t_map		parse_map(char *filename);
void		put_pixel(t_data *data, int x, int y, int color);
void		draw_line(t_vec_3d p_start, t_vec_3d p_end, t_data *imgdata);
void		draw_map(t_fdf fdf);
char		*get_next_line(int fd);
t_vec_3d	apply_matrix(t_vec_3d v, t_matrix m);
t_vec_3d	init_vect(double x, double y, double z);
t_vec_3d	add_vect(t_vec_3d v1, t_vec_3d v2);
t_vec_3d	sub_vect(t_vec_3d v1, t_vec_3d v2);
t_vec_3d	div_vect(t_vec_3d v1, double k);
t_vec_3d	mul_vect(t_vec_3d v1, double k);
double		vect_dot_product(t_vec_3d v1, t_vec_3d v2);
t_vec_3d	vect_normalise(t_vec_3d v);
t_vec_3d	vect_cross_product(t_vec_3d v1, t_vec_3d v2);
t_matrix	get_projection_matrix(t_proj proj);
t_matrix	get_world_matrix(t_trans trans, t_rot rot);
t_matrix	get_camera_matrix(t_vec_3d camera);
t_matrix	multiply_matrix(t_matrix m1, t_matrix m2);
t_matrix	inverse_matrix(t_matrix m);
void		bzero(void *ptr, size_t size);
void		clear_img(t_data *img);

#endif
