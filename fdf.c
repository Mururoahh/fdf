/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 06:10:27 by hferraud          #+#    #+#             */
/*   Updated: 2022/11/21 18:46:22 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "./minilibx_macos/mlx.h"

typedef struct s_data
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

float	get_coef_dir(t_pos p_start, t_pos p_end)
{
	long	dif_x;
	long	dif_y;

	dif_x = p_end.x - p_start.x;
	dif_y = p_end.y - p_start.y;
	return (dif_y / dif_x);
}

int	round_float(float nb)
{
	return ((int) nb + 0.5);
}

void	draw_line(t_data *img, t_pos p_start, t_pos p_end, int color)
{
	t_pos	p_curr;
	int		v_dec;
	int		delta_up;
	int		delta_down;

	v_dec = 2 * (p_end.y - p_start.y) - (p_end.x - p_start.x);
	delta_down = 2 * (p_end.y - p_start.y);
	delta_up = 2 * ((p_end.y - p_start.y) - (p_end.x - p_start.x));
}

void	place_pix_right(t_pos p_start, t_pos p_end, t_pos delta, int color)
{
	t_pos	p_curr;
	int		v_dec;
	int		aprox_up;
	int		aprox_down;

	p_curr.x = p_start.x;
	p_curr.y = p_start.y;
	if (p_end.x >= p_start.x)
	{
		if (delta.x >= delta.y)
		{
			v_dec = 2 * (delta.y - delta.x);
			aprox_down = 2 * delta.y;
			aprox_up = 2 * (delta.y - delta.x);
		}
	}
	while (p_curr.x < p_end.x)
	{
		if (v_dec <= 0)
			v_dec += aprox_down;
		else
		{
			v_dec += aprox_up;
			p_curr.y++;
		}
			p_curr.x++;
		put_pixel(img, p_curr.x, p_curr.y, color);
	}
}

t_pos	get_pos(int x, int y)
{
	t_pos	point;

	point.x = x;
	point.y = y;
	return (point);
}

int	main(void)
{
	void	*mlx;
	void	*win;
	t_data	img;
	t_pos	origin = get_pos(250, 250);
	t_pos	right = get_pos(350, 250);
	t_pos	up = get_pos(250, 150);
	t_pos	left = get_pos(150, 250);
	t_pos	down = get_pos(250, 350);

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "fdf");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	draw_line(&img, origin, right, 0xff0000);
	draw_line(&img, origin, up, 0xff0000);
	draw_line(&img, origin, left, 0xff0000);
	draw_line(&img, origin, down, 0xff0000);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
