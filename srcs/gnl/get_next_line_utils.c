/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferraud <hferraud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 23:03:29 by hferraud          #+#    #+#             */
/*   Updated: 2022/11/20 21:07:22 by hferraud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find_newl(char *str, int buf_size)
{
	int	i;

	i = 0;
	while (i < buf_size && str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_bufmove(char *buf, int index_newl, int size)
{
	int	i;

	i = 0;
	while (i + index_newl + 1 < size && index_newl != -1)
	{
		buf[i] = buf[index_newl + 1 + i];
		i++;
	}
	while (i < size)
		buf[i++] = 0;
}

size_t	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, char *src, size_t dstsize, size_t srcsize)
{
	size_t	i;
	size_t	size_dst;

	if ((dst == NULL || src == NULL) && dstsize == 0)
		return (0);
	i = 0;
	size_dst = ft_strlen(dst);
	if ((dstsize > 0) && (dstsize >= size_dst))
	{
		while (((size_dst + i) < dstsize - 1) && src[i])
		{
			dst[size_dst + i] = src[i];
			i++;
		}
		dst[size_dst + i] = '\0';
		return (size_dst + srcsize);
	}
	return (dstsize + srcsize);
}

char	*ft_strjoin(char *s1, char *s2, int s2_size)
{
	char	*str;
	size_t	len;
	int		i;

	if (s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + s2_size;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	ft_strlcat(str, s2, len + 1, s2_size);
	return (str);
}
