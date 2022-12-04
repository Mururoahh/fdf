/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:49:26 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/03 14:37:06 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
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
		if (ft_isdigit(line[i]) || line[i] == '-')
		{
			line_size++;
			while (ft_isdigit(line[i]) || line[i] == '-')
				i++;
		}
		while (line[i] && line[i] != ' ')
			i++;
	}
	return (line_size);
}

t_map_line	*push_map_line(t_map_line **head, char *line)
{
	t_map_line	*elem;

	elem = malloc(sizeof(t_map_line));
	if (elem == NULL)
		return (NULL);
	elem->line = line;
	elem->next = *head;
	*head = elem;
	return (elem);
}

t_map_line	*map_to_list(char *filename)
{
	t_map_line	*head;
	int			fd;
	char		*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	head = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (push_map_line(&head, line) == NULL)
			return (NULL);
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
		return (NULL);
	return (head);
}

size_t	lstrev(t_map_line **head)
{
	t_map_line	*prev;
	t_map_line	*current;
	t_map_line	*next;
	size_t		count;

	current = *head;
	next = NULL;
	prev = NULL;
	count = 0;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}
	*head = prev;
	return (count);
}

void	parse_line(char *line, t_map *map, size_t row_i)
{
	size_t	col_i;
	size_t	line_size;
	size_t	i;

	line_size = get_line_size(line);
	map->points[row_i] = malloc(sizeof(t_vec_3d) * (line_size));
	if (map->points[row_i] == NULL)
		exit (1);
		//ERRNO
	if (map->width == 0)
		map->width = line_size;
	else if (map->width != line_size)
		exit (1);
	col_i = 0;
	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (!ft_isdigit(line[i]) && line[i] != '-')
			exit (1);
		map->points[row_i][col_i] = init_vect(col_i, row_i, ft_iatoi(line, &i));
		while (line[i] && line[i] != ' ')
			i++;
		col_i++;
	}
}

t_map	parse_map(char *filename)
{
	t_map_line	*line_head;
	size_t		row_i;
	t_map		map;

	line_head = map_to_list(filename);
	if (line_head == NULL)
	//ERRNO
		exit(1);
	map.height = lstrev(&line_head);
	map.points = malloc(map.height * sizeof(int *));
	if (map.points == NULL)
		exit(1);
	map.width = 0;
	row_i = 0;
	while (line_head)
	{
		parse_line(line_head->line, &map, row_i);
		line_head = line_head->next;
		row_i++;
	}
	return (map);
}
