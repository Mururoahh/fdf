/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:49:26 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/14 09:41:19 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "parser.h"
#include "ft_utils.h"

int	get_line_size(char *line)
{
	int			line_size;
	size_t		i;

	line_size = 0;
	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if ((ft_isdigit(line[i]) || line[i] == '-'))
		{
			line_size++;
			while ((ft_isdigit(line[i]) || line[i] == '-'))
				i++;
		}
		while (line[i] && line[i] != ' ')
			i++;
	}
	return (line_size);
}

void	init_map_line(t_map *map, size_t row_i, size_t line_size)
{
	map->map[row_i] = malloc(sizeof(t_vec_3d) * (line_size));
	if (map->map[row_i] == NULL)
		exit (1);
	if (map->width == 0)
		map->width = line_size;
	else if (map->width != line_size)
		exit (1);
}

void	parse_line(char *line, t_map *map, size_t row_i)
{
	size_t	col_i;
	size_t	line_size;
	size_t	i;

	line_size = get_line_size(line);
	init_map_line(map, row_i, line_size);
	col_i = 0;
	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (ft_isdigit(line[i]) || line[i] == '-')
		{
			map->map[row_i][col_i] = init_vect(col_i - map->width / 2.0,
					row_i - map->height / 2.0, ft_iatoi(line, &i));
			col_i++;
		}
		while (line[i] && line[i] != ' ')
			i++;
	}
}

t_map	parse_map(char *filename)
{
	t_map_line	*line_head;
	t_map_line	*next;
	size_t		row_i;
	t_map		map;

	line_head = map_to_list(filename);
	if (line_head == NULL)
		exit(1);
	map.height = lstrev(&line_head);
	map.map = malloc(map.height * sizeof(int *));
	if (map.map == NULL)
		exit(1);
	map.width = 0;
	row_i = 0;
	while (line_head)
	{
		next = line_head->next;
		parse_line(line_head->line, &map, row_i);
		free(line_head->line);
		free(line_head);
		line_head = next;
		row_i++;
	}
	return (map);
}
