/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:49:26 by hferraud          #+#    #+#             */
/*   Updated: 2022/11/29 08:57:26 by hferraud         ###   ########lyon.fr   */
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

int	*parse_line(char *line, t_map *map)
{
	int		*parsed_line;
	int		parsed_index;
	int		line_size;
	size_t	i;

	line_size = get_line_size(line);
	parsed_line = malloc(sizeof(int) * (line_size));
	if (parsed_line == NULL)
		return (NULL);
	if (map->width == -1)
		map->width = line_size;
	else if (map->width != line_size)
		return (NULL);
	parsed_index = 0;
	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (!ft_isdigit(line[i]) && line[i] != '-')
			return (NULL);
		parsed_line[parsed_index] = ft_iatoi(line, &i);
		while (line[i] && line[i] != ' ')
			i++;
		parsed_index++;
	}
	return (parsed_line);
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

t_map	*parse_map(char *filename)
{
	t_map_line	*line_head;
	size_t		map_height;
	size_t		current_line;
	t_map		*map;

	map = malloc(sizeof(t_map));
	line_head = map_to_list(filename);
	if (line_head == NULL)
		return (NULL);
	map_height = lstrev(&line_head);
	map->height = map_height;
	map->points = malloc(map_height * sizeof(int *));
	if (map->points == NULL)
		return (NULL);
	map->width = -1;
	current_line = 0;
	while (line_head)
	{
		map->points[current_line] = parse_line(line_head->line, map);
		if (map->points[current_line] == NULL)
			return (NULL);
		line_head = line_head->next;
		current_line++;
	}
	return (map);
}
