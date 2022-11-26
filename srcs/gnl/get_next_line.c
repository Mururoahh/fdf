/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:54:30 by hferraud          #+#    #+#             */
/*   Updated: 2022/11/24 13:14:22 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_flush_buf(char *line, char *buf, int index_newl)
{
	char	*joined_line;

	if (*buf == 0)
		return (line);
	if (index_newl == -1)
		joined_line = ft_strjoin(line, buf, BUFFER_SIZE);
	else
		joined_line = ft_strjoin(line, buf, index_newl + 1);
	free(line);
	ft_bufmove(buf, index_newl, BUFFER_SIZE);
	return (joined_line);
}

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE];
	char			*final_str;
	int				index_nl;
	int				read_ret;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	read_ret = 1;
	final_str = NULL;
	index_nl = ft_find_newl(buf, BUFFER_SIZE);
	while (read_ret > 0 && index_nl == -1)
	{
		if (*buf != 0)
			final_str = ft_flush_buf(final_str, buf, index_nl);
		read_ret = read(fd, buf, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free(final_str);
			return (NULL);
		}
		index_nl = ft_find_newl(buf, BUFFER_SIZE);
	}
	return (ft_flush_buf(final_str, buf, index_nl));
}
