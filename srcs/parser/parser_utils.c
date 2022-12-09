/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:20:30 by hferraud          #+#    #+#             */
/*   Updated: 2022/12/09 18:21:47 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
